/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:49 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/16 09:38:05 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	readmap(int fd)
{
	char	*line;
	char	*join;
	char	**walls;
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
	printf("%s\n", join);
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
	printf("\n i : %d, j : %d", i, j);
	game(i, j, walls);
	fill(walls, i,  j,'*');
	find(walls, 'E');
	find(walls, 'C');
	find(walls, 'P');
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
	//return(map);
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