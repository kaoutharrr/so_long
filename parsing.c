/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:49 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/20 12:23:33 by kkouaz           ###   ########.fr       */
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
	char    *leak;
	int		i;
	int		j;
	int a = 0;
	i = 0;
	j  =  0;
		
	if(fd < 0)
		error("invalid map\n",2,1);
	line = get_next_line(fd);
	if(!line)
		error("invalid map", 2, 1);
	join = ft_strdup("");
	while(line)
	{
		free(line);
		leak = join;
		if (!ft_strcmp(line, "\n"))
		{
			free(line);
			error("invalid map", 2, 1);
		}
		
		join = ft_strjoin(join, line);
		free(leak);
		line = get_next_line(fd);
		printf("\n\n\n\n\n\n\n %s\n\n\n\n\n\n\n\n\n",line);
		system("leaks so_long");
	}
	
	walls = ft_split(join, '\n');
	copy = ft_split(join, '\n');
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
	fill(copy, i,  j,'*');
	find(copy, 'E');
	find(copy, 'C');
	find(copy, 'P');
	my_free(copy);
	map_check(join);
	free(join);
		i = 0;
	j = 0;
	while(walls[i])
		i++;
	while(walls[0][j])
		j++;
	
	game(i, j, walls);

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