#include <unistd.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		byte_per_pixel;
	int		vertical_offset;
	int		horizontal_offset;

	byte_per_pixel = data->bits_per_pixel / 8;
	vertical_offset = y * data->line_length;
	horizontal_offset = x * byte_per_pixel;
	dst = data->addr + (vertical_offset + horizontal_offset);
	*(unsigned int*)dst = color;
}

void	put_horizontal_line(t_data *img, int x, int y, int size)
{
	int		i;

	(void)y;
	i = 0;
	while (i < size)
	{
		my_mlx_pixel_put(img, x + (1.73)*i, y + i, 0x00FFFFFF);
		i++;
	}
}

void	put_vertical_line(t_data *img, int x, int y, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		my_mlx_pixel_put(img, x, y + i, 0x00FFFFFF);
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	put_horizontal_line(&img, 10, 10, 100);
	//put_vertical_line(&img, 10, 10, 100);
	//put_horizontal_line(&img, 10, 110, 100);
	//put_vertical_line(&img, 110, 10, 100);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
