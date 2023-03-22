/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:40:15 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/22 14:01:31 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close1(int keycode, t_vars *vars)
{
	vars->i = 0;
	vars->j = 0;
	vars->n = 0;
	vars->m = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		exit (0);
	}
	find_player_position(vars);
	if (keycode == 126 || keycode == 13)
		move_above(vars);
	if (keycode == 125 || keycode == 1)
		move_down(vars);
	if (keycode == 124 || keycode == 2)
		move_right(vars);
	if (keycode == 123 || keycode == 0)
		move_left(vars);
	return (0);
}

void	game_init(int x, int y, char **map)
{
	t_vars	vars;

	vars.count = 0;
	vars.map = map;
	vars.n = 0;
	vars.m = 0;
	vars.i = 0;
	vars.j = 0;
	vars.b = x * 100 ;
	vars.a = y * 100 ;
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, vars.a, vars.b, "so_long");
	vars.door = mlx_xpm_file_to_image(vars.mlx,
			"textures/door.xpm", &vars.w, &vars.h);
	vars.img = mlx_xpm_file_to_image(vars.mlx, "textures/background.xpm",
			&vars.w, &vars.h);
	vars.wall = mlx_xpm_file_to_image(vars.mlx, "textures/walls.xpm",
			&vars.w, &vars.h);
	vars.cookie = mlx_xpm_file_to_image(vars.mlx,
			"textures/cookie.xpm", &vars.w, &vars.h);
	vars.kitten = mlx_xpm_file_to_image(vars.mlx, "textures/kitten.xpm",
			&vars.w, &vars.h);
	put_window(vars);
	game_play(vars, map);
}

void	game_play(t_vars vars, char **map)
{
	vars.i = 0;
	vars.j = 0;
	while (map[vars.i])
	{
		vars.j = 0;
		vars.n = 0;
		while (map[vars.i][vars.j])
		{
			put_images(&vars, map);
		}
		vars.m += 100;
		vars.i++;
	}
	mlx_hook(vars.window, 02, 1L << 0, close1, &vars);
	mlx_hook(vars.window, 17, 0L, (void *)exit, &vars);
	mlx_loop(&vars);
}

void	put_window(t_vars vars)
{
	vars.i = 0;
	while (vars.i < vars.a)
	{
		vars.j = 0;
		while (vars.j < vars.b)
		{
			mlx_put_image_to_window(vars.mlx, vars.window,
				vars.img, vars.i, vars.j);
			vars.j += 100;
		}
		vars.i += 100;
	}
}

void	find_player_position(t_vars *vars)
{
	vars->i = 0;
	vars->m = 0;
	while (vars->map[vars->i])
	{
		vars->j = 0;
		vars->m = 0;
		while (vars->map[vars->i][vars->j])
		{
			vars->j++;
			vars->m += 100;
			if (vars->map[vars->i][vars->j] == 'P')
				break ;
		}
		if (vars->map[vars->i][vars->j] == 'P')
			break ;
		vars->i++;
		vars->n += 100;
	}
}
