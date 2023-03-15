/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:49 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/15 12:31:28 by kkouaz           ###   ########.fr       */
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
	int a = 0;

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
	printf("\n i %d      j %d \n" ,i,j);
	fill(walls, i,  j,'*');
	while (walls[a])
	{
	printf("\n%s", walls[a]);
	a++;
	}
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
