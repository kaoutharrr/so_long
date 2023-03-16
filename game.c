/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:24:19 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/16 09:46:32 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

	void    game(int x, int y, char **map)
	{
		void	*mlx;
		void	*window;
		void	*img;
		void	*wall;
		void	*cookie;
		void	*kitten;
		void	*door;
		int		w;
		int		h;
		int		i;
		int		j;
		int a,b;
		int n,m;
		n = 0;
		m = 0;
	(void)map;
		i = 0;
		j = 0;
		b =  (x ) *100 ;
		a =  (y )* 100 ;
		mlx = mlx_init();
		window = mlx_new_window(mlx, a, b, "so_long");
		//img = mlx_new_image(mlx, 1920, 1080);
		door = mlx_xpm_file_to_image(mlx,"door.xpm", &w, &h );
		img = mlx_xpm_file_to_image(mlx,"background.xpm", &w, &h );
		wall = mlx_xpm_file_to_image(mlx,"walls.xpm", &w, &h );
		cookie = mlx_xpm_file_to_image(mlx,"cookie.xpm", &w, &h );
		kitten = mlx_xpm_file_to_image(mlx,"kitten.xpm", &w, &h );
		while (i < a)
		{
			j = 0;
			while( j < b)
			{
				mlx_put_image_to_window(mlx, window, img, i, j);
				j+=100;
			}
			i+=100;
		}
	i = 0;
	j = 0;
	while(map[i])
	{
		j  = 0;
		n = 0;
		while(map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, window,wall, n, m);
			else if(map[i][j] == 'C')
				mlx_put_image_to_window(mlx, window, cookie, n, m);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, window, kitten, n, m);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, window, door, n, m);
			n+=100;
			j++;
		}
		m+=100;
		i++;
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
		mlx_loop(mlx);
	}


// void	fill_game(char **map, int i, int j,void	*img)
// {
// 	if( map[i][j] == c)
// 		return;
// 	// if(map[i][j] == 'E')
// 	// {
// 	// 	map[i][j] = c;
// 	// 	return;
// 	// }
// 	map[i][j] = c;
// 	fill(map, i+ 1, j, c);
// 	fill(map, i- 1, j, c);
// 	fill(map, i , j+1, c);
// 	fill(map, i , j-1, c);
// 	//return(map);
// }