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
int main(int ac, char	**av)
{
	int fd;
	fd = open("map.ber",O_RDONLY, 0644);
	if(ac != 2)
		error("Error!\n",2, 1);
	if (ft_strcmp(av[1] , "map.ber"))
		error("Error!\n",2, 1);
	readmap(fd);
	
}