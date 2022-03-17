/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:23:47 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/17 15:53:12 by gwinnink         ###   ########.fr       */
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
	char	**path;
	int		fd[2];
}	t_input;

// ----------------------------------------Prototypes
// ------------------------------Error exit
void	error_exit(const char *msg);

// ------------------------------Parsing
t_input	parse_input(int argc, char **argv, char **envp);

// ------------------------------Libft utils
size_t	ft_strlen(const char *s);
void	*ft_calloc(int count, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *s, char c);
char	**free_all(char **ret);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int c);

#endif