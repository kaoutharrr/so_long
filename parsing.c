/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:49 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/12 15:21:10 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	readmap(int fd)
{
	//int 	fd;
	char	*line;
	char	*join;
	char	**walls;

	//int a = 0;

	//fd = open(filename, O_RDONLY, 0644);
	if(fd < 0)
		error("appaahhhhh\n",2,1);
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
	map_check(join);
	}
