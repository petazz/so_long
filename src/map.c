/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:38:59 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/04/29 13:25:25 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_map(t_map *map)
{
	int	t;

	t = 0;
	while (t < 5)
	{
		free(map->grid[t]);
		t++;
	}
	free(map->grid);
	printf("Error fre\n");
}

int	ft_strlen_sl(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
		{
			str[i] = '\0';
			i = i - 1;
		}
		i++;
	}
	return (i);
}

void	ft_measure_map(char *name_map, t_map *map)
{
	int		fd;
	int		aux;
	char	*temp;

	aux = 0;
	map->h = 0;
	fd = open(name_map, O_RDONLY);
	if (fd == -1)
		ft_error();
	temp = get_next_line(fd);
	if(!temp)
		ft_error();
	map->w = ft_strlen_sl(temp);
	while(temp)
	{
		map->h++;
		aux = ft_strlen_sl(temp);
		if (map->w != aux)
			ft_error();
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
}
void	ft_check_map(t_map *map)
{
	int	i;

	i = 0;
	while(i < map->w)
	{
		if(map->grid[0][i] != '1')
			ft_free_map(map);
		if(map->grid[map->h-1][i] != '1')
			ft_free_map(map);
		i++;
	}
	i = 1;
	while(i < map->h)
	{
		if(map->grid[i][0] != '1')
			ft_free_map(map);
		if(map->grid[i][map->w-1] != '1')
			ft_free_map(map);
		i++;
	}
}

void	ft_read_map(char *name_map)
{
	int		i;
	int		fd;
	char	*line;
	t_map	map;

	i = ft_strlen(name_map) - 4;
	if (ft_memcmp(&name_map[i], ".ber", 5) != 0)
		ft_error();
	ft_measure_map(name_map, &map);
	printf("H: %d, W: %d\n", map.h, map.w);
	map.grid = ft_calloc(sizeof(char *), (map.h));
	fd = open(name_map, O_RDONLY);
	if (fd == -1)
		ft_error();
	line = get_next_line(fd);
	i = 0;
	while(i < map.h)
	{
		map.grid[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("CERRADO\n");
	ft_check_map(&map);
	printf("CHECKEADO\n");
	ft_save_player(&map);
}
