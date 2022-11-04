/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:15:26 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 12:11:23 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H

# include "mlx.h"
# include "camera.h"
# include "object.h"
# include "ray.h"

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_parse_arg
{
	int	sign;
	int	div;
}	t_parse_arg;

typedef struct s_parse_cam
{
	t_vec	pos;
	t_vec	ori;
	float	fov;
}	t_parse_cam;

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
	t_img			img;
	int				painted;
	t_viewport		viewport;
	t_frustum		frustum;
	t_mat			camera;
	t_ray			ray;
	t_light_ambient	light_ambient;
	t_list			lights;
	t_list			objects;
	t_parse_arg		parse;
	t_parse_cam		parse_cam;
	t_list			lights_cpy;
	t_list			objects_cpy;
	t_hit_record    rec;
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
