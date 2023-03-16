/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:20:47 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/16 09:37:48 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include "gnl/get_next_line.h"

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
#	endif