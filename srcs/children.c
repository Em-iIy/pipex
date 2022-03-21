/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:48:45 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/21 17:42:06 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	child_one(t_input input, int pipe_fd[2], char **envp)
{
	if (access(input.cmd1, X_OK) == -1)
		error_exit("execve");
	if (dup2(input.fd[0], STDIN_FILENO) == -1)
		error_exit("Dup2");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error_exit("Dup2");
	close(pipe_fd[0]);
	if (execve(input.cmd1, input.cmd1_args, envp) == -1)
		error_exit("execve");
}

void	child_two(t_input input, int pipe_fd[2], char **envp)
{
	if (access(input.cmd2, X_OK) == -1)
		error_exit("execve");
	if (dup2(input.fd[1], STDOUT_FILENO) == -1)
		error_exit("Dup2");
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		error_exit("Dup2");
	close(pipe_fd[1]);
	if (execve(input.cmd2, input.cmd2_args, envp) == -1)
		error_exit("execve");
}
