/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:24:42 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/30 22:35:15 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <sys/errno.h>
# include <stdio.h>
# include <stdlib.h>

void	perror_exit(char *str);
void	perror_exit_arg(char *str);

#endif
