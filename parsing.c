/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:49 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/19 15:52:19 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	readmap(int fd)
{
	char	*line;
	char	*join;
	char	**walls;
	char    **copy;
	int		i;
	int		j;;
	i = 0;
	j  =  0;

	if(fd < 0)
		error("invalid map\n",2,1);
	line = get_next_line(fd);
	join = "";
	while(line)
	{
		join = ft_strjoin(join, line);
		line = get_next_line(fd);
	}
	walls = ft_split(join, '\n');
	check_errors(walls);
	check_walls(walls);
	check_borders(walls);
	while(walls[i])
	 {
		j = 0;
		while ( walls[i][j])
		{
			j++;
			if(walls[i][j] == 'P')
				break;
		}
		if(walls[i][j] == 'P')
			break;
		i++;
	}
	i = 0;
	j = 0;
	while(walls[i])
		i++;
	while(walls[0][j])
		j++;
	game(i, j, walls);
	fill(copy, i,  j,'*');
	find(copy, 'E');
	find(copy, 'C');
	find(copy, 'P');
	map_check(join);
	}

void	fill(char **map, int i, int j, char c)
{
	if(map[i][j] == '1' ||  map[i][j] == c)
		return;
	if(map[i][j] == 'E')
	{
		map[i][j] = c;
		return;
	}
	map[i][j] = c;
	fill(map, i+ 1, j, c);
	fill(map, i- 1, j, c);
	fill(map, i , j+1, c);
	fill(map, i , j-1, c);
}

void find(char **walls, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(walls[i])
	 {
	
		j = 0;
		while ( walls[i][j])
		{
			if(walls[i][j] == c)
				error("invalid path", 2, 1);
			j++;
			
		}
		if(walls[i][j] == c)
				error("invalid path", 2, 1);
		i++;
	
	}
}

char **ft_copy(char **map)
{
	int i;
	int j;
	char **str;
	i = 0;
	j = 0;

	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			str[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return(str);
}