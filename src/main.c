/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:46:46 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/04/30 19:28:10 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	
	if (argc != 2)
		ft_error();
	ft_read_map(&map, argv[1]);
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



// typedef struct s_data {
// 	mlx_t* mlx;
// 	mlx_image_t* img;
// 	mlx_texture_t* texture;
// } t_data;

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

// void ft_fun(mlx_key_data_t keydata, void* param)
// {
// 	t_data *data = param;
// 	int STEP = 50;

// 	if (keydata.key == MLX_KEY_SPACE)
// 	{
// 		// printf("\n");
// 		//bzero(data->img->pixels, data->img->width * data->img->height * 4);
// 		//mlx_draw_texture(data->img, data->texture, x++, y++);
// 		data->img->instances[0].x += 1;
// 		data->img->instances[0].y += 1;

// 	}
// 	if (keydata.key == MLX_KEY_A)
// 		data->img->instances[0].x -= STEP;
// 	if (keydata.key == MLX_KEY_D)
// 		data->img->instances[0].x += STEP;
// 	if (keydata.key == MLX_KEY_S)
// 		data->img->instances[0].y += STEP;
// 	if (keydata.key == MLX_KEY_W)
// 		data->img->instances[0].y -= STEP;
// }

// int	main(void)
// {






// 	char	*relative_path = "poke.xpm";


// 	t_data data;

// 	// MLX allows you to define its core behaviour before startup.
// 	mlx_set_setting(MLX_MAXIMIZED, true);
// 	data.mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false);
// 	if (!data.mlx)
// 		ft_error();

// 	/* Do stuff */

// 	// Create and display the image.
// 	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
// 	if (!data.img || (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0))
// 		ft_error();

// 	// Even after the image is being displayed, we can still modify the buffer.
// 	//mlx_put_pixel(img, 10, 10, 0xFF0000FF);

// 	// Register a hook and pass mlx as an optional param.
// 	// NOTE: Do this before calling mlx_loop!


// 	data.texture = mlx_load_png("poke.png");
// 	if (!data.texture)
//         ft_error();
// 	// mlx_image_t* img = mlx_texture_to_image(mlx, texture);
// 	// if (!img)
//     //     ft_error();
// 	mlx_draw_texture(data.img, data.texture, 25, 42);
// 	// if (mlx_image_to_window(mlx, img, 10, 10) < 0)
//     //     ft_error();
// 	// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_key_hook(data.mlx, ft_fun, &data);
// 	mlx_loop(data.mlx);
// 	mlx_terminate(data.mlx);
// 	return (EXIT_SUCCESS);
// }