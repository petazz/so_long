/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:21:58 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/04/28 21:34:25 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_save_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(map->grid[i] != NULL)
	{
		j = 0;
		while(map->grid[i][j] != '\0')
		{
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
	}
	if (map->c == 0)
		ft_free_map(map);
}



int	ft_valid(t_map *map, int i, int j)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
	map->c = 0;
	if (map->grid[i][j] != 'P' && map->grid[i][j] != 'E'
		&& map->grid[i][j] != '1' && map->grid[i][j] != '0'
		&& map->grid[i][j] != 'C' && map->grid[i][j] != '\0'
		&& map->grid[i][j] != '\n')
		return (0);
	if(map->grid[i][j] == 'C')
		map->c++;
	if(map->grid[i][j] == 'P')
		p++;
	if(map->grid[i][j] == 'E')
		e++;
	if (p > 1 || e > 1)
		ft_free_map(map);
	return (1);
}
