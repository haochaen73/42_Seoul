/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:51:16 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/13 19:51:17 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_setcharset(char *charset, char *extcharset)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	while (charset[cnt])
		cnt++;
	i = 0;
	j = 0;
	while (i < cnt)
	{
		extcharset[(int)charset[i]] = 1;
		i++;
	}
}

char	**ft_wordmalloc(char *str, char **result, char *extcharset)
{
	int	idx;
	int	wc;
	int	wc_ing;

	idx = 0;
	wc = 0;
	wc_ing = 0;
	while (str[idx])
	{
		if (wc_ing && extcharset[(int)str[idx]])
			wc_ing = 0;
		if (!wc_ing && !extcharset[(int)str[idx]])
		{
			wc++;
			wc_ing = 1;
		}
		idx++;
	}
	result = (char **)malloc(sizeof(char *) * (wc + 1));
	result[wc] = 0;
	return (result);
}

char	**ft_charmalloc(char *str, char **result, char *extcharset, int i)
{
	int	idx;
	int	len;
	int	wc_ing;

	idx = -1;
	len = 0;
	wc_ing = 0;
	while (str[++idx])
	{
		if (wc_ing && extcharset[(int)str[idx]])
		{
			wc_ing = 0;
			result[i++] = (char *)malloc(sizeof(char) * (len + 1));
			len = 0;
		}
		if (!extcharset[(int)str[idx]])
		{
			if (!wc_ing)
				wc_ing = 1;
			len++;
		}
	}
	if (wc_ing)
		result[i++] = (char *)malloc(sizeof(char) * (len + 1));
	return (result);
}

char	**ft_putchar(char *str, char **result, char *extcharset, int i)
{
	int	wc_ing;
	int	idx;
	int	len;

	wc_ing = 0;
	idx = -1;
	len = 0;
	while (str[++idx])
	{
		if (wc_ing && extcharset[(int)str[idx]])
		{
			result[i++][len] = 0;
			wc_ing = 0;
			len = 0;
		}
		if (!extcharset[(int)str[idx]])
		{
			result[i][len++] = str[idx];
			if (!wc_ing)
				wc_ing = 1;
		}
	}
	if (wc_ing)
		result[i][len] = 0;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	extcharset[256];
	int		idx;

	idx = 0;
	while (idx < 256)
		extcharset[idx++] = 0;
	result = 0;
	ft_setcharset(charset, extcharset);
	result = ft_wordmalloc(str, result, extcharset);
	result = ft_charmalloc(str, result, extcharset, 0);
	result = ft_putchar(str, result, extcharset, 0);
	return (result);
}
