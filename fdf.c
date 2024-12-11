#include <unistd.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

int		main()
{
	void	*qualcosa;
	void	*qualcosaltro;

	qualcosa = mlx_init();
	qualcosaltro = mlx_new_window(qualcosa, 500, 500, "fdf");
	mlx_loop(qualcosa);
	//mlx_pixel_put(qualcosa, qualcosaltro, 10, 10, 0x00FF0000);
}
