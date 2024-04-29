/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:21:58 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/04/29 13:39:32 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_save_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->p_x = -1;
	map->p_y = -1;
	// map->w = 0;
	// map->h = 0;
	map->p = 0;
	map->e = 0;
	printf("C: %d\n", map->c);
	while(i < map->h)
	{
		j = 0;
		while(map->grid[i][j] != '\0')
		{
		printf("grid[i][j]: %c\n", map->grid[i][j]);
			if(!ft_valid(map, i, j))
				ft_error();
			if(map->grid[i][j] == 'P')
			{	
				map->p_x = j;
				map->p_y = i;
			}
			j++;
		}
		i++;
	printf("hola\n");
	}
	if (map->c == 0)
		ft_free_map(map);
}



int	ft_valid(t_map *map, int i, int j)
{
	printf("p:%d \n", map->p);
	if (map->grid[i][j] != 'P' && map->grid[i][j] != 'E'
		&& map->grid[i][j] != '1' && map->grid[i][j] != '0'
		&& map->grid[i][j] != 'C' && map->grid[i][j] != '\0'
		&& map->grid[i][j] != '\n')
		return (0);
	if(map->grid[i][j] == 'C')
		map->c++;
	if(map->grid[i][j] == 'P')
	{
		printf("hola\n");
		map->p++;
	}
	if(map->grid[i][j] == 'E')
		map->e++;
	if (map->p > 1 || map->e > 1)
		return (printf("p:%d , e:%d \n", map->p, map->e), ft_free_map(map), 0);
	return (1);
}
