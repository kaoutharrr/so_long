#include"so_long.h"

int main()
{
	int fd;
	fd = open("map.ber",O_RDONLY, 0644);
	// void	*mlx;
	// void	*window;
	// void	*img;
	// void	*wall;
	// void	*cookie;
	// void	*kitten;
	// void	*door;
	// int		w;
	// int		h;
	// int		i;
	// int		j;

	// i = 0;
	// j = 0;
	// mlx = mlx_init();
	// window = mlx_new_window(mlx, 1920, 1080, "so_long");
	// //img = mlx_new_image(mlx, 1920, 1080);
	// door = mlx_xpm_file_to_image(mlx,"door.xpm", &w, &h );
	// img = mlx_xpm_file_to_image(mlx,"background.xpm", &w, &h );
	// wall = mlx_xpm_file_to_image(mlx,"walls.xpm", &w, &h );
	// cookie = mlx_xpm_file_to_image(mlx,"cookie.xpm", &w, &h );
	// kitten = mlx_xpm_file_to_image(mlx,"kitten.xpm", &w, &h );
	// while (i < 1920)
	// {
	// 	j = 0;
	// 	while( j < 1080)
	// 	{
	// 		mlx_put_image_to_window(mlx, window, img, i, j);
	// 		j+=100;
	// 	}
	// 	i+=100;
	// }

	//  i = 100;
	// while (i < 1920)
	// {
	// 	j = 100;
	// 	while( j < 1080)
	// 	{
	// 		mlx_put_image_to_window(mlx, window, wall, i, j);
	// 		j+=100;
	// 	}
	// 	i+=400;
	// }
	//  i = 200;
	// while (i < 1920)
	// {
	// 	j = 100;
	// 	while( j < 1080)
	// 	{
	// 		mlx_put_image_to_window(mlx, window, cookie, i, j);
	// 		j+=100;
	// 	}
	// 	i+=400;
	// }
	// mlx_put_image_to_window(mlx, window, kitten, 400, 100);
	// mlx_put_image_to_window(mlx, window, door, 1000, 1000);
	// mlx_loop(mlx);
 readmap(fd);
}