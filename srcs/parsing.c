/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:10:54 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/16 13:34:41 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

t_input	parse_input(int argc, char **argv)
{
	t_input	ret;

	if (argc != 5)
		error_exit(INVALID_ARGC);
	ret.f1 = open(argv[1], O_RDONLY);
	ret.f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC | 0644);
	if (ret.f1 < 0 || ret.f2 < 0)
		error_exit(INVALID_FILES);
	ret.cmd1 = argv[2];
	ret.cmd2 = argv[3];
	ret.cmd1_args = ft_split(argv[2], ' ');
	ret.cmd2_args = ft_split(argv[3], ' ');
	return (ret);
}
