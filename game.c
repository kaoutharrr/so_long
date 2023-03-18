/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:24:19 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/18 02:06:34 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>


// int	close(int keycode, void *mlx, void *win)
// {
// 	if(keycode==13 )
// 	mlx_destroy_window(mlx, win);
// 	return (0);
// }
int close1(int keycode , t_vars *vars)
{
	vars->i = 0;
	vars->j = 0;
	vars->n = 0;
	vars->m = 0;
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		exit(0);
	}
	while(vars->map[vars->i])
	{
		vars->j = 0;
		vars->m = 0;
		while ( vars->map[vars->i][vars->j])
		{
			vars->j++;
			vars->m+=100;
			if(vars->map[vars->i][vars->j] == 'P')
			{
				// fprintf(stderr,"here\n");
				break;
			}

		}
		if(vars->map[vars->i][vars->j] == 'P')
		{
			// fprintf(stderr,"here\n");
			break;
		}
		vars->i++;
		vars->n+=100;
	}
	// while(vars->map[vars->i])
	// {
	// 	vars->j = 0;
	// 	vars->n = 0;
	// 	while(vars->map[vars->i][vars->j])
	// 	{
		// printf("@@@@@@@%c\n",vars->map[vars->i][vars->j]);
		// 	if(keycode == 126 )
		// 	{
				
		// 		if(vars->map[vars->i - 1][vars->j] == '0')
		// 		{
		// 			printf("fdf\n");
		// 			vars->map[vars->i][vars->j] = '0';
		// 			vars->map[vars->i -1][vars->j] = 'P';
		// 			game(vars->i , vars->j,vars->map);
		// 		}
				// mlx_put_image_to_window(vars->mlx, vars->window,vars->img, vars->m, vars->n);
				// mlx_put_image_to_window(vars->mlx, vars->window,vars->kitten, vars->m - 100, vars->n);
				// vars->m-=100;
				// vars->i--;
			if(keycode == 126)
			{
				if(vars->map[vars->i - 1][vars->j] == '1' || vars->map[vars->i - 1][vars->j] == 'E')
					return 0 ;
				mlx_put_image_to_window(vars->mlx, vars->window,vars->img, vars->m , vars->n);
				mlx_put_image_to_window(vars->mlx, vars->window,vars->kitten, vars->m, vars->n - 100);
				vars->map[vars->i][vars->j] = '0';
				vars->i--;
				vars->map[vars->i][vars->j] = 'P';
				vars->n-=100;
			}
			if(keycode == 125)
			{
				if(vars->map[vars->i  + 1][vars->j] == '1' || vars->map[vars->i + 1][vars->j] == 'E')
					return 0 ;
				mlx_put_image_to_window(vars->mlx, vars->window,vars->img, vars->m , vars->n);
				mlx_put_image_to_window(vars->mlx, vars->window,vars->kitten, vars->m, vars->n + 100);
				vars->map[vars->i][vars->j] = '0';
				vars->n+=100;
				vars->i++;
				vars->map[vars->i][vars->j] = 'P';
			}
			if(keycode == 124)
			{
				if(vars->map[vars->i ][vars->j + 1] == '1' || vars->map[vars->i][vars->j + 1] == 'E')
					return 0 ;
				mlx_put_image_to_window(vars->mlx, vars->window,vars->img, vars->m, vars->n);
				mlx_put_image_to_window(vars->mlx, vars->window,vars->kitten, vars->m+100, vars->n );
				vars->map[vars->i][vars->j] = '0';
				vars->n+=100;
				vars->j++;
				vars->map[vars->i][vars->j] = 'P';
			}
			if(keycode == 123)
			{
				if(vars->map[vars->i  ][vars->j -1] == '1' || vars->map[vars->i][vars->j -1] == 'E')
					return 0 ;
				mlx_put_image_to_window(vars->mlx, vars->window,vars->img, vars->m, vars->n);
				mlx_put_image_to_window(vars->mlx, vars->window,vars->kitten, vars->m - 100, vars->n );
				vars->map[vars->i][vars->j] = '0';
				vars->n-=100;
				vars->j--;
				vars->map[vars->i][vars->j] = 'P';
			}
				
	// 	}
	//}
	return(0);
}
	void    game(int x, int y, char **map)
	{
		t_vars vars;

		vars.map = map;
		vars.n = 0;
		vars.m = 0;
		vars.i = 0;
		vars.j = 0;
		vars.b =  (x ) *100 ;
		vars.a =  (y )* 100 ;
		vars.mlx = mlx_init();
		vars.window = mlx_new_window(vars.mlx, vars.a, vars.b, "so_long");
		//
		//img = mlx_new_image(mlx, 1920, 1080);
		vars.door = mlx_xpm_file_to_image(vars.mlx,"door.xpm", &vars.w, &vars.h );
		vars.img = mlx_xpm_file_to_image(vars.mlx,"background.xpm", &vars.w, &vars.h );
		vars.wall = mlx_xpm_file_to_image(vars.mlx,"walls.xpm", &vars.w, &vars.h );
		vars.cookie = mlx_xpm_file_to_image(vars.mlx,"cookie.xpm", &vars.w, &vars.h );
		vars.kitten = mlx_xpm_file_to_image(vars.mlx,"kitten.xpm", &vars.w, &vars.h );
		while (vars.i < vars.a)
		{
			vars.j = 0;
			while( vars.j < vars.b)
			{
				mlx_put_image_to_window(vars.mlx, vars.window, vars.img, vars.i, vars.j);
				vars.j+=100;
			}
			vars.i+=100;
		}
	vars.i = 0;
	vars.j = 0;
	while(map[vars.i])
	{
		vars.j  = 0;
		vars.n = 0;
		while(map[vars.i][vars.j])
		{
			if (map[vars.i][vars.j] == '1')
				mlx_put_image_to_window(vars.mlx, vars.window,vars.wall, vars.n, vars.m);
			else if(map[vars.i][vars.j] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.window, vars.cookie, vars.n, vars.m);
			else if (map[vars.i][vars.j] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.window, vars.kitten, vars.n, vars.m);
			else if (map[vars.i][vars.j] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.window, vars.door, vars.n, vars.m);
			vars.n+=100;
			vars.j++;
		}
		vars.m+=100;
		vars.i++;
	}
		// i = 0;
		// while (i < y)
		// {
		// 	j = 0;
		// 	while( j < x)
		// 	{
		// 			if(map[i][j] == '1')
		// 			mlx_put_image_to_window(mlx, window, wall, i, j);
		// 		j++;
		// 	}
		// 	i++;
		// }
		// i = 200;
		// while (i < a)
		// {
		// 	j = 100;
		// 	while( j < b)
		// 	{
		// 		if(map[i][j] == 'C')
		// 		mlx_put_image_to_window(mlx, window, cookie, i, j);
		// 		j+=100;
		// 	}
		// 	i+=400;
		// }
		// mlx_put_image_to_window(mlx, window, kitten, 400, 100);
		// mlx_put_image_to_window(mlx, window, door, 1000, 1000);
		mlx_key_hook(vars.window, close1, &vars);
		//move_the_player(&vars, map);
		mlx_loop(&vars);
	}

// int move_player(int keycode, )