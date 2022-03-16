/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:35:32 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/16 10:44:10 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

static char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		str_size;

	str_size = ft_strlen(s1);
	ret = (char *)malloc(str_size + 1);
	if (!ret)
		return (NULL);
	ret[str_size] = (char) s1[str_size];
	while (str_size--)
		ret[str_size] = (char) s1[str_size];
	return (ret);
}

static char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static int	ft_str_count(const char *s, char c)
{
	int	str_count;
	int	i;

	str_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			str_count++;
		i++;
	}
	return (str_count);
}

static char	**free_all(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		str_count;
	int		words;
	int		i;

	words = 0;
	str_count = ft_str_count(s, c);
	ret = (char **)malloc((str_count + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while (words < str_count)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i])
			i++;
		ret[words] = ft_substr(s, 0, i);
		if (!ret[words])
			return (free_all(ret));
		s += i;
		words++;
	}
	ret[str_count] = 0;
	return (ret);
}