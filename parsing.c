/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:49 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/21 01:05:55 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	readmap(int fd)
{
	t_vars	vars;

	vars.a = 0;
	vars.i = 0;
	vars.j = 0;
	vars.line = get_next_line(fd);
	if (!vars.line)
		error("invalid map", 2, 1);
	vars.join = ft_strdup("");
	while (vars.line)
	{
		free(vars.line);
		vars.leak = vars.join;
		if (!ft_strcmp(vars.line, "\n"))
			error("invalid map", 2, 1);
		vars.join = ft_strjoin(vars.join, vars.line);
		free(vars.leak);
		vars.line = get_next_line(fd);
	}
	vars.walls = ft_split(vars.join, '\n');
	vars.copy = ft_split(vars.join, '\n');
	ft_check(vars.walls);
	map_check(vars.join);
	flood_fill(vars);
}

void	fill(char **map, int i, int j, char c)
{
	if (map[i][j] == '1' || map[i][j] == c)
		return ;
	if (map[i][j] == 'E')
	{
		map[i][j] = c;
		return ;
	}
	map[i][j] = c;
	fill(map, i + 1, j, c);
	fill(map, i - 1, j, c);
	fill(map, i, j + 1, c);
	fill(map, i, j - 1, c);
}

void	find(char **walls, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (walls[i])
	{
		j = 0;
		while (walls[i][j])
		{
			if (walls[i][j] == c)
				error("invalid path", 2, 1);
			j++;
		}
		if (walls[i][j] == c)
			error("invalid path", 2, 1);
		i++;
	}
}

void	ft_check(char **walls)
{
	check_errors(walls);
	check_walls(walls);
	check_borders(walls);
}

void	flood_fill(t_vars vars)
{
	vars.i = 0;
	while (vars.walls[vars.i])
	{
		vars.j = 0;
		while (vars.walls[vars.i][vars.j])
		{
			vars.j++;
			if (vars.walls[vars.i][vars.j] == 'P')
				break ;
		}
		if (vars.walls[vars.i][vars.j] == 'P')
			break ;
		vars.i++;
	}
	fill(vars.copy, vars.i, vars.j, '*');
	find(vars.copy, 'E');
	find(vars.copy, 'C');
	find(vars.copy, 'P');
	vars.i = 0;
	vars.j = 0;
	while (vars.walls[vars.i])
		vars.i++;
	while (vars.walls[0][vars.j])
		vars.j++;
	game_init(vars.i, vars.j, vars.walls);
}
