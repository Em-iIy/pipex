/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:08:16 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/22 14:45:58 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(int count, size_t size)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = (char *)malloc(size * count);
	if (!ret)
		error_exit("malloc");
	while (i < count * size)
	{
		ret[i] = 0;
		i++;
	}
	return ((void *)ret);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	return (ret);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	int				ret;
	unsigned char	str1;
	unsigned char	str2;

	i = 0;
	str1 = s1[i];
	str2 = s2[i];
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && n--)
	{
		str1 = s1[i];
		str2 = s2[i];
		ret = str1 - str2;
		if (str1 != str2)
			return (ret);
		i++;
	}
	ret = str1 - str2;
	return (ret);
}
