/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:19:42 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/21 19:20:24 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
