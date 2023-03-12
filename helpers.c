/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:33:12 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/12 10:38:18 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_errors(char **map)
{
	int	i;
	int	j;

i = 0;
j = 0;
	while(map[i])
	{
		i++;
	}
	--i;
	while(map[0][j] != '\0')
	{
		
		if(map[0][j] != '1')
			error("invalid map\n",2 ,1);
		j++;
	}
	j = 0;
	while( map[i][j])
	{
		
		if(map[i][j] != '1')
			error("invalid map\n",2 ,1);
		j++;
	}
	i = 0;
	j = i+ 1;
	while(map[i])
	{
		if (ft_strlen(map[i])!= ft_strlen(map[j]))
			error("invalid map\n",2,1);
		i++;
	}
}