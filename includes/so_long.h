/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:12:12 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/05/03 13:47:01 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include <fcntl.h>
#include <strings.h>

/////////////////////////////MLX//////////////////////////////

# include "MLX42/MLX42.h"
# define WIDTH 500
# define HEIGHT 500

typedef struct s_data {
	mlx_t*			mlx;
	mlx_image_t*	img_pokeball;
	mlx_image_t*	img_pc;
	mlx_image_t*	img_floor;
	mlx_image_t*	img_exit;
	mlx_image_t*	img_wall;
	mlx_texture_t*	texture;
} t_data;

typedef struct s_map
{
	char	**grid;
	char	**copy_grid;
	int		w;
	int		h;
	int		p_x;
	int		p_y;
	int		c;
	int		p;
	int		e;
} t_map;

/////////////////////////CHECK_MAP/////////////////////////////

void	ft_read_map(t_map *map, char *name_map);
void	ft_init_struct(t_map *map);
void	ft_measure_map(char *name_map, t_map *map);
void	ft_error(void);
int		ft_strlen_sl(char *str);
void	ft_free_map(t_map *map, char **matrix);
void	ft_save_player(t_map *map);
int		ft_valid(t_map *map, int i, int j);
void	ft_flood_fill(t_map *map, int x, int y);
void	ft_check_collectibles(t_map *map);
void	ft_init_my_mlx(t_map *map);
void	ft_create_texture(t_data *data);
void	ft_put_imgs(t_data *data,t_map *map);

// DEBUG
void print_config(t_map *map, int print_map);

#endif