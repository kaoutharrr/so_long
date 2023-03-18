/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:20:47 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/18 11:24:39 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include "gnl/get_next_line.h"
typedef struct	s_vars {
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
		char **map;
}	t_vars;
char	**ft_split(char  *s, char c);
void	error(char *s, int fd, int ex);
void    readmap(int fd);
char	*ft_strjoin_a(char const *s1, char const *s2);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len);
void check_errors(char **map);
void	check_walls(char **map);
void	check_borders(char **map);
void	map_check(char *map);
void	collectible_check(char *map);
void	exit_check(char *map, char c);
void fill(char **map, int i, int j, char c);
void find(char **walls, char c);
void    game(int x, int y, char **map);
void	move_the_player(t_vars vars, char **map);
int find_cookie(t_vars vars);
#	endif