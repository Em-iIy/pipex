/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:23:47 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/16 14:10:46 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// ----------------------------------------Includes
# include <stdlib.h>

// ----------------------------------------Enums
enum e_error
{
	MALLOC_FAIL = 1,
	INVALID_ARGC,
	INVALID_FILES
};

// ----------------------------------------Structs
typedef struct s_input
{
	char	*cmd1;
	char	**cmd1_args;
	char	*cmd2;
	char	**cmd2_args;
	char	**path;
	int		f1;
	int		f2;
}	t_input;

// ----------------------------------------Prototypes
// ------------------------------Error exit
void	error_exit(int code);

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