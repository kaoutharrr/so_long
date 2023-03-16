#include"so_long.h"

int main()
{
	int fd;
	fd = open("map.ber",O_RDONLY, 0644);
	readmap(fd);
}