/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:12:15 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/22 13:59:33 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	**my_free(char **p)
{
	int	i;

	i = 0;
	if (!p)
		return (NULL);
	while (p[i])
	{
		free (p[i]);
		p[i] = (NULL);
		i++;
	}
	free(p);
	p = NULL;
	return (p);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*s;
	t_xpm	files;

	if (ac != 2)
		error("Error!\n", 2, 1);
	check_textures(&files);
	s = ft_find(av[1]);
	if (ft_strcmp(s, "reb."))
		error("Error!\n", 2, 1);
	free(s);
	fd = open(av[1], O_RDONLY, 0644);
	if (fd < 0)
		error("invalid map\n", 2, 1);
	readmap(fd);
}

char	*ft_find(char *str)
{
	int		i;
	int		j;
	int		a;
	char	*s;

	i = 0;
	j = 0;
	s = malloc(4);
	while (str[i])
		i++;
	a = i - 4;
	i--;
	while (i >= a)
	{
		s[j] = str[i];
		j++;
		i--;
	}
	s[j] = '\0';
	return (s);
}

void	check_textures(t_xpm *files)
{
	files->background = open("textures/background.xpm", O_RDONLY);
	files->cookie = open("textures/cookie.xpm", O_RDONLY);
	files->door = open("textures/door.xpm", O_RDONLY);
	files->kitten = open("textures/kitten.xpm", O_RDONLY);
	files->walls = open("textures/walls.xpm", O_RDONLY);
	if (files->background == -1)
		error("error!\n", 2, 1);
	if (files->cookie == -1)
		error("error!\n", 2, 1);
	if (files->door == -1)
		error("error!\n", 2, 1);
	if (files->kitten == -1)
		error("error!\n", 2, 1);
	if (files->walls == -1)
		error("error!\n", 2, 1);
}
