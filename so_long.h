/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:20:47 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/12 10:38:27 by kkouaz           ###   ########.fr       */
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

#	endif