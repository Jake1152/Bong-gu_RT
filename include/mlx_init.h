/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:15:26 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/16 19:02:41 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H

# include "mlx.h"

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	int		width;
	int		height;
	t_img	img;
	int		painted;
}	t_mlx;

typedef enum e_input
{
	MOUSE_UP = 4,
	MOUSE_DOWN = 5,
	// KEY_C = 8,
	// KEY_M = 46,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126,
}	t_input;

int		destroy(t_mlx *mlx);
int		mlx_wrap_key_hook(int keycode, t_mlx *mlx);
int		mlx_wrap_mouse_hook(int button, int x, int y, t_mlx *mlx);
int		mlx_wrap_loop_hook(t_mlx *mlx);
void	mlx_wrap_init_run(t_mlx *mlx, int width, int height);

#endif
