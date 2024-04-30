/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:12:12 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/04/30 19:12:08 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include <fcntl.h>
// #include "MLX42/MLX42.h"
// #define WIDTH 456
// #define HEIGHT 456

#include <strings.h>

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

void	ft_read_map(t_map *map, char *name_map);
void	ft_init_struct(t_map *map);
void	ft_measure_map(char *name_map, t_map *map);
void	ft_error(void);
int		ft_strlen_sl(char *str);
void	ft_free_map(t_map *map);
void	ft_save_player(t_map *map);
int		ft_valid(t_map *map, int i, int j);
void	ft_flood_fill(t_map *map, int x, int y);

// DEBUG
void print_config(t_map *map, int print_map);

#endif