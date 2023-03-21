/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:40:15 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/21 02:28:14 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	vars.door = mlx_xpm_file_to_image(vars.mlx, "door.xpm", &vars.w, &vars.h);
	vars.img = mlx_xpm_file_to_image(vars.mlx, "background.xpm",
			&vars.w, &vars.h);
	vars.wall = mlx_xpm_file_to_image(vars.mlx, "walls.xpm", &vars.w, &vars.h);
	vars.cookie = mlx_xpm_file_to_image(vars.mlx,
			"cookie.xpm", &vars.w, &vars.h);
	vars.kitten = mlx_xpm_file_to_image(vars.mlx, "kitten.xpm",
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
	mlx_key_hook(vars.window, close1, &vars);
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

int	move_above(t_vars *vars)
{
	if (vars->map[vars->i - 1][vars->j] == '1' )
		return (0);
	if (vars->map[vars->i - 1][vars->j] == 'E' )
	{
		if (find_cookie(*vars) == 0)
		{
			ft_printf("congrats u won\n");
			mlx_destroy_window(vars->mlx, vars->window);
			exit (0);
		}
		return (0);
	}
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img,
		vars->m, vars->n);
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->img, vars->m, vars->n - 100);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->kitten,
		vars->m, vars->n - 100);
	vars->count++;
	ft_printf("moves : %d\n", vars->count);
	vars->map[vars->i][vars->j] = '0';
	vars->i--;
	vars->map[vars->i][vars->j] = 'P';
	vars->n -= 100;
	return (0);
}

int	move_down(t_vars *vars)
{
	if (vars->map[vars->i + 1][vars->j] == '1' )
		return (0);
	if (vars->map[vars->i + 1][vars->j] == 'E' )
	{
		if (find_cookie(*vars) == 0)
		{
			ft_printf("congrats u won\n");
			mlx_destroy_window(vars->mlx, vars->window);
			exit(0);
		}
		return (0);
	}
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->img, vars->m, vars->n);
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->img, vars->m, vars->n + 100);
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->kitten, vars->m, vars->n + 100);
	vars->count++;
	ft_printf("moves : %d\n", vars->count);
	vars->map[vars->i][vars->j] = '0';
	vars->n += 100;
	vars->i++;
	vars->map[vars->i][vars->j] = 'P';
	return (0);
}

int	move_right(t_vars *vars)
{
	if (vars->map[vars->i][vars->j + 1] == '1')
		return (0);
	if (vars->map[vars->i][vars->j + 1] == 'E' )
	{
		if (find_cookie(*vars) == 0)
		{
			ft_printf("congrats u won\n");
			mlx_destroy_window(vars->mlx, vars->window);
			exit(0);
		}
		return (0);
	}
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img,
		vars->m, vars->n);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img,
		vars->m + 100, vars->n);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->kitten,
		vars->m + 100, vars->n);
	vars->count++;
	ft_printf("moves : %d\n", vars->count);
	vars->map[vars->i][vars->j] = '0';
	vars->n += 100;
	vars->j++;
	vars->map[vars->i][vars->j] = 'P';
	return (0);
}

int	move_left(t_vars *vars)
{
	if (vars->map[vars->i][vars->j -1] == '1' )
		return (0);
	if (vars->map[vars->i][vars->j -1] == 'E' )
	{
		if (find_cookie(*vars) == 0)
		{
			ft_printf("congrats u won\n");
			mlx_destroy_window(vars->mlx, vars->window);
			exit (0);
		}
		return (0);
	}
	vars->count++;
	ft_printf("moves : %d\n", vars->count);
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->img, vars->m, vars->n);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img,
		vars->m - 100, vars->n);
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->kitten, vars->m - 100, vars->n);
	vars->map[vars->i][vars->j] = '0';
	vars->n -= 100;
	vars->j--;
	vars->map[vars->i][vars->j] = 'P';
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
