#include"so_long.h"
#include <stdio.h>
int main()
{
	int fd;
	fd = open("map.ber",O_RDONLY, 0644);
	readmap(fd);
}

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	close1(int keycode, t_vars *vars)
// {
// 	if(keycode == 53)
// 		mlx_destroy_window(vars->mlx, vars->win);
// 	printf("%d\n", keycode);
// 	return (0);
// }
// int	handle_keypress(int keysym, t_vars *data)
// {
// 	if (keysym == XK_Escape)
// 		mlx_destroy_window(data->mlx, data->win);

// 	printf("Keypress: %d\n", keysym);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_key_hook(vars.win, close1, &vars);
// 	mlx_loop(vars.mlx);
// }