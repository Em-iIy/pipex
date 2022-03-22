/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:28:47 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/22 12:18:11 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void	cmd_error_exit(const char *cmd)
{
	write(2, "command not found: ", 19);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	exit(127);
}

void	error_exit(const char *msg, int code)
{
	perror(msg);
	if (code == 0)
		exit(errno);
	exit(EXIT_FAILURE);
}
