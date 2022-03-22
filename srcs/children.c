/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:48:45 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/22 14:46:55 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>

void	child_one(char *file, t_input input, int pipe_fd[2], char **envp)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(file);
	if (!input.cmd1)
		cmd_error_exit(input.cmd1_args[0]);
	if (dup2(fd, STDIN_FILENO) == -1)
		error_exit("dup2");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error_exit("dup2");
	close(pipe_fd[0]);
	if (execve(input.cmd1, input.cmd1_args, envp) == -1)
		error_exit("execve");
}

void	child_two(char *file, t_input input, int pipe_fd[2], char **envp)
{
	int	fd;

	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		error_exit(file);
	if (!input.cmd2)
		cmd_error_exit(input.cmd2_args[0]);
	if (dup2(fd, STDOUT_FILENO) == -1)
		error_exit("dup2");
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		error_exit("dup2");
	close(pipe_fd[1]);
	if (execve(input.cmd2, input.cmd2_args, envp) == -1)
		error_exit("execve");
}
