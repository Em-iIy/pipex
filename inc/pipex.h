/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:23:47 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/22 12:16:28 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// ----------------------------------------Includes
# include <stdlib.h>

// ----------------------------------------Enums

// ----------------------------------------Structs
typedef struct s_input
{
	char	*cmd1;
	char	**cmd1_args;
	char	*cmd2;
	char	**cmd2_args;
	int		fd[2];
}	t_input;

// ----------------------------------------Prototypes
// ------------------------------Error exit
void	cmd_error_exit(const char *cmd);
void	error_exit(const char *msg, int code);

// ------------------------------Parsing
t_input	parse_input(int argc, char **argv, char **envp);

// ------------------------------Children
void	child_one(t_input input, int pipe_fd[2], char **envp);
void	child_two(t_input input, int pipe_fd[2], char **envp);

// ------------------------------Libft utils
size_t	ft_strlen(const char *s);
void	*ft_calloc(int count, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *s, char c);
char	**free_all(char **ret);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);

#endif