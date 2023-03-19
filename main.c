#include"so_long.h"
#include <stdio.h>
int main(int ac, char	**av)
{
	int fd;
	fd = open("map.ber",O_RDONLY, 0644);
	if(ac != 2)
		error("Error!\n",2, 1);
	if (ft_strcmp(av[1] , "map.ber"))
		error("Error!\n",2, 1);
	readmap(fd);
	system("leaks so_long");
}