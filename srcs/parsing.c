/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:10:54 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/22 14:45:41 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

static char	*check_cmd(char	*cmd, char	**path)
{
	char	*ret;
	char	*temp;
	int		i;

	i = 0;
	if (!path)
		error_exit("environment");
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		ret = ft_strjoin(temp, cmd);
		free(temp);
		if (access(ret, X_OK) == 0)
			return (ret);
		free(ret);
		i++;
	}
	return (NULL);
}

t_input	parse_input(int argc, char **argv, char **envp)
{
	t_input	ret;
	char	**path;
	int		i;

	i = 0;
	ret.cmd1_args = ft_split(argv[2], ' ');
	ret.cmd2_args = ft_split(argv[3], ' ');
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			path = ft_split(&envp[i][5], ':');
		i++;
	}
	ret.cmd1 = check_cmd(ret.cmd1_args[0], path);
	ret.cmd2 = check_cmd(ret.cmd2_args[0], path);
	free_all(path);
	return (ret);
}
