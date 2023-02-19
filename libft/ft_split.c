/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:28:56 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/12 15:29:00 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_malloc(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

static void	ft_strcpy(char *dst, char *src, char *to)
{
	while (src < to)
		*(dst++) = *(src++);
	*dst = 0;
}

int	ft_cnt(const char *s, char c)
{
	int	cnt;
	int	flag;

	flag = 0;
	cnt = 0;
	while (*s)
	{
		if (*s != c && !flag)
		{
			flag = 1;
			cnt++;
		}
		if (*s == c && flag == 1)
			flag = 0;
		s++;
	}
	return (cnt);
}

char	**ft_charsplit(char *s, char c, int len, char **ptr)
{
	int		i;
	char	*from;

	i = 0;
	while (i < len)
	{
		while (*s && *s == c)
			s++;
		from = (char *)s;
		while (*s && *s != c)
			s++;
		ptr[i] = (char *)malloc(sizeof(char) * (s - from + 1));
		if (!ptr[i])
			return (free_malloc(ptr));
		ft_strcpy(ptr[i++], from, (char *)s);
	}
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		len;

	if (!(char *)s)
		return (NULL);
	len = ft_cnt((char *)s, c);
	ptr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr = ft_charsplit((char *)s, c, len, ptr);
	if (ptr)
		ptr[len] = NULL;
	return (ptr);
}
