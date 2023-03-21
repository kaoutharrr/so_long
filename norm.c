/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:17:08 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/21 19:21:11 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_check(char *map)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
		{
			c++;
			i++;
		}
		i++;
	}
	if (c == 0)
		error("invalid map\n", 2, 1);
}

void	exit_check(char *map, char c)
{
	int	i;
	int	e;

	e = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == c)
		{
			e++;
			i++;
		}
		i++;
	}
	if (e != 1)
		error("invalid map\n", 2, 1);
}

int	find_cookie(t_vars vars)
{
	vars.i = 0;
	vars.j = 0;
	while (vars.map[vars.i])
	{
		vars.j = 0;
		while (vars.map[vars.i][vars.j])
		{
			if (vars.map[vars.i][vars.j] == 'C')
				return (1);
			vars.j++;
		}
		vars.i++;
	}
	return (0);
}

void	put_images(t_vars *vars, char **map)
{
	if (map[vars->i][vars->j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->wall, vars->n, vars->m);
	else if (map[vars->i][vars->j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->cookie, vars->n, vars->m);
	else if (map[vars->i][vars->j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->kitten, vars->n, vars->m);
	else if (map[vars->i][vars->j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->door, vars->n, vars->m);
	vars->n += 100;
	vars->j++;
}
