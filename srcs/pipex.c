/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:23:56 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/17 15:55:07 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

// static void	pipex();

static void	print_input(t_input input)
{
	int		i;

	printf("INPUT\ncmd1:\t\t\"%s\"\ncmd2:\t\t\"%s\"\n", input.cmd1, input.cmd2);
	for (i = 0; input.path[i]; i++)
		printf("PATH:\t\t\"%s\"\n", input.path[i]);
	for (i = 0; input.cmd1_args[i]; i++)
		printf("cmd1 args:\t\"%s\"\n", input.cmd1_args[i]);
	for (i = 0; input.cmd2_args[i]; i++)
		printf("cmd2 args:\t\"%s\"\n", input.cmd2_args[i]);
}

int	main(int argc, char **argv, char **envp)
{
	t_input	input;
	int		pipe_fd[2];

	if (argc != 5)
	{
		write(2, "Error, invalid amount of arguments\n", 35);
		exit(1);
	}
	input = parse_input(argc, argv, envp);
	if (pipe(pipe_fd) < 0)
		error_exit("pipe");
	print_input(input);
}
