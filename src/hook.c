// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "so_long.h"
void ft_hook(void* param)
{
	t_data *data;

	data = (t_data*)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		data->img_pc->instances[0].enabled = 0
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->img_pc->instances[0].y -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->img_pc->instances[0].y += 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->img_pc->instances[0].x -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->img_pc->instances[0].x += 5;
}
