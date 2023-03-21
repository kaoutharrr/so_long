/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:12:15 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/21 02:13:16 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include <stdio.h>

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
	int	fd;

	if (ft_strcmp(av[1], "map.ber"))
		error("Error!\n", 2, 1);
	fd = open(av[1], O_RDONLY, 0644);
	if (fd < 0)
		error("invalid map\n", 2, 1);
	if (ac != 2)
		error("Error!\n", 2, 1);
	readmap(fd);
}
