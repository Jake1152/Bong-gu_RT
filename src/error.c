/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:25:16 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/02 16:14:22 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	perror_exit(char *str)
{
	perror(str);
	exit(1);
}

void	perror_exit_arg(char *str)
{
	errno = EINVAL;
	printf("Example: ./miniRT [file.rt:test.rt] [width:1280] [height:720]\n");
	perror_exit(str);
}
