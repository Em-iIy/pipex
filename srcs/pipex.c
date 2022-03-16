/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:23:56 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/16 14:07:30 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

// static void	pipex();

int	main(int argc, char **argv, char **envp)
{
	t_input	input;

	input = parse_input(argc, argv, envp);
	printf("INPUT\ninfilefd:\t%d\noutiflefd:\t%d\ncmd1:\t\t%s\ncmd2:\t\t%s\nPATH:\t\t%s\n", input.f1, input.f2, input.cmd1, input.cmd2, input.path);
}
