/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:32:54 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/16 19:09:51 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"

int main(int argc, char *argv[])
{
	t_mlx	mlx;
	int		width = 1280;
	int		height = 720;

	(void)argv;
	(void)argc;

	// TODO parse fill width, height
	mlx_wrap_init_run(&mlx, width, height);
}
