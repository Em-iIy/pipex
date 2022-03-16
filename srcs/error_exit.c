/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:28:47 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/16 12:36:15 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	ft_puterror(const char *s)
{
	write(2, s, ft_strlen(s));
}

void	error_exit(int code)
{
	if (code == INVALID_ARGC)
		ft_puterror("Error: Invalid amount of arguments");
	else
		perror("Error: ");
	exit(code);
}