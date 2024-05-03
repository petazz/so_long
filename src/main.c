/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:46:46 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/05/03 18:15:28 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	
	if (argc != 2)
		ft_error();
	ft_read_map(&map, argv[1]);
	ft_init_my_mlx(&map);
	return (0);
}

void	ft_init_struct(t_map *map)
{
	map->h = 0;
	map->p_x = -1;
	map->p_y = -1;
	map->p = 0;
	map->e = 0;
}
void ft_fun(mlx_key_data_t keydata, void* param)
{
	t_data *data = param;
	int STEP = 50;
		
	printf("mapa:%c\n", data->map->grid[data->map->p_y][data->map->p_x-1]);
	print_config(data->map, 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(1);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS && data->map->grid[data->map->p_y][data->map->p_x-1] != '1')
	{
		data->map->p_x--;
		data->img_pc->instances[0].x -= STEP;
	}
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS && data->map->grid[data->map->p_y][data->map->p_x+1] != '1')
	{
		data->map->p_x++;
		data->img_pc->instances[0].x += STEP;
	}
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS && data->map->grid[data->map->p_y+1][data->map->p_x] != '1')
	{
		data->map->p_y++;
		data->img_pc->instances[0].y += STEP;
	}
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && data->map->grid[data->map->p_y-1][data->map->p_x] != '1')
	{
		data->map->p_y--;
		data->img_pc->instances[0].y -= STEP;
	}
	if(data->map->grid[data->map->p_y][data->map->p_x] == 'C')
	{
		printf("asdasd\n");
		data->map->grid[data->map->p_y][data->map->p_x] = '0';
		data->map->c--;
		ft_print_colectables(data);
	}
	
}

void	ft_print_colectables(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	
	if(data->img_pokeball)
	{
		mlx_delete_image(data->mlx, data->img_pokeball);
		data->img_pokeball = mlx_texture_to_image(data->mlx, data->texture);
	}
	while(j < data->map->h)
	{
		i = 0;
		while(i < data->map->w)
		{
		printf("Porro ayudaaaaa\n");
			if(data->map->grid[j][i] == 'C')
				mlx_image_to_window(data->mlx, data->img_pokeball, i * 50, j * 50);
			i++;
		}
		j++;
	}

}

void	ft_create_texture(t_data *data)
{
	data->texture = mlx_load_png("texture/bush.png");
	data->img_wall = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("texture/fond.png");
	data->img_floor = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("texture/npc.png");
	data->img_pc = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("texture/imgexit.png");
	data->img_exit = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("texture/poke.png");
	data->img_pokeball = mlx_texture_to_image(data->mlx, data->texture);
	//mlx_delete_texture(data->texture);
}
void	ft_put_imgs(t_data *data, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while(j < map->h)
	{
		i = 0;
		while(i < map->w)
		{
			if(map->grid[j][i] == '1')
				mlx_image_to_window(data->mlx, data->img_wall, i * 50, j * 50);
			if(map->grid[j][i] == 'P')
				mlx_image_to_window(data->mlx, data->img_floor, i * 50, j * 50);
			if(map->grid[j][i] == '0')
				mlx_image_to_window(data->mlx, data->img_floor, i * 50, j * 50);
			if(map->grid[j][i] == 'C')
			{
				mlx_image_to_window(data->mlx, data->img_floor, i * 50, j * 50);
				mlx_image_to_window(data->mlx, data->img_pokeball, i * 50, j * 50);
			}
			if(map->grid[j][i] == 'E')
				mlx_image_to_window(data->mlx, data->img_exit, i * 50, j * 50);
			i++;
		}
		j++;
	}
}



void ft_init_my_mlx(t_map *map)
{
	t_data data;
	
	data.map = map;
	data.mlx = mlx_init(map->w * 50, map->h * 50, "er juegoh", false);
	if (!data.mlx)
		ft_error();
	ft_create_texture(&data);
	ft_put_imgs(&data, map);
	mlx_image_to_window(data.mlx,data.img_pc,map->p_x * 50,map->p_y * 50);
	mlx_key_hook(data.mlx, ft_fun, &data);
	

	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}

// void	ft_print_bg(t_map *map, t_data *data)
// {
	// int	i;
	// int	j;

	// i = 0;
	// while(i < map->h)
	// {
	// 	j = 0;
	// 	while(map->grid[i][j] != '\0')
	// 	{
	// 		if(map->grid[i][j] == '1')
	// 			ft_print_wall();
	// 		if(map->grid[i][j] == '0')
	// 			ft_print_floor();
	// 		i++;
	// 	}
	// 	j++;
	// }
// }

// void	ft_print_wall()


// 	char	*relative_path = "../texture/poke.xpm";

// 	data.texture = mlx_load_png("poke.png");
// 	if (!data.texture)
//         ft_error();
// 	// mlx_image_t* img = mlx_texture_to_image(mlx, texture);
// 	// if (!img)
//     //     ft_error();
// 	// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_key_hook(data.mlx, ft_fun, &data);
// 	mlx_loop(data.mlx);
// 	mlx_terminate(data.mlx);
// 	return (EXIT_SUCCESS);
// }





// // Exit the program as failure.
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// // Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

