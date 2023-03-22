/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:33:12 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/21 22:06:00 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t				i;
	unsigned const char	*a1;
	unsigned const char	*a2;

	a1 = (unsigned const char *)s1;
	a2 = (unsigned const char *)s2;
	i = 0;
	while ((a1[i] != '\0' || a2[i] != '\0'))
	{
		if (a1[i] != a2[i])
			return (a1[i] - a2[i]);
		i++;
	}
	return (0);
}

void	check_errors(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[j]))
			error("invalid map\n", 2, 1);
		i++;
	}
}

void	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	--i;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1')
			error("invalid map\n", 2, 1);
		j++;
	}
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			error("invalid map\n", 2, 1);
		j++;
	}
}

void	check_borders(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j])
		j++;
	j -= 1;
	while (map[i])
	{
		if (map[i][0] != '1')
			error("invalid map\n", 2, 1);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][j] != '1')
			error("invalid map\n", 2, 1);
		i++;
	}
}

void	map_check(char *map)
{
	int	i;

	i = 0;
	if (map[i])
	{
		collectible_check(map);
		exit_check(map, 'E');
		exit_check(map, 'P');
	}
	i = 0;
	while (map[i])
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == '\n'
			|| map[i] == 'C' || map[i] == 'P' || map[i] == 'E')
			i++;
		else
			error("invalid map\n", 2, 1);
	}
}
