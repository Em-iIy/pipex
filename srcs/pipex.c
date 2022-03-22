/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:23:56 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/22 12:32:00 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

static void	pipex(t_input input, int pipe_fd[2], char **argv, char **envp)
{
	pid_t	child1;
	pid_t	child2;
	int		status;

	child1 = fork();
	if (child1 < 0)
		error_exit("Fork", 0);
	else if (child1 == 0)
		child_one(argv[1], input, pipe_fd, envp);
	child2 = fork();
	if (child2 < 0)
		error_exit("Fork", 0);
	else if (child2 == 0)
		child_two(argv[4], input, pipe_fd, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

// static void	print_input(t_input input)
// {
// 	int		i;

// 	printf("INPUT\ncmd1:\t\t\"%s\"\ncmd2:\t\t\"%s\"\n", input.cmd1, input.cmd2);
// 	for (i = 0; input.cmd1_args[i]; i++)
// 		printf("cmd1 args:\t\"%s\"\n", input.cmd1_args[i]);
// 	for (i = 0; input.cmd2_args[i]; i++)
// 		printf("cmd2 args:\t\"%s\"\n", input.cmd2_args[i]);
// }

int	main(int argc, char **argv, char **envp)
{
	t_input	input;
	int		pipe_fd[2];

	if (argc != 5)
	{
		write(2, "Error, invalid amount of arguments\n", 35);
		exit(EXIT_FAILURE);
	}
	input = parse_input(argc, argv, envp);
	if (pipe(pipe_fd) < 0)
		error_exit("pipe", 0);
	pipex(input, pipe_fd, argv, envp);
}
