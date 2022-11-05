/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:23:57 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 03:48:05 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

unsigned char	ovfadd(unsigned char c1, unsigned char c2)
{
	unsigned char	ret;

	ret = c1 + c2;
	if (ret < c1 || ret < c2)
		return (255);
	else
		return (ret);
}
