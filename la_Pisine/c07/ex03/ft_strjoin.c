/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:58:08 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/08 21:29:27 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *word)
{
	int	cnt;

	cnt = 0;
	while (*word)
	{
		word++;
		cnt++;
	}
	return (cnt);
}

void	ft_putchar(int size, char **strs, char *sep, char *result)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (j < ft_strlen(strs[i]))
			result[k++] = strs[i][j++];
		j = 0;
		if (i < size - 1)
		{
			while (sep[j])
				result[k++] = sep[j++];
		}
		i++;
	}
	result[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total;
	int		i;

	i = 0;
	total = 0;
	if (size <= 0)
		total = 0;
	else
	{
		while (i < size)
			total += ft_strlen(strs[i++]);
		total += ft_strlen(sep) * (size - 1);
	}
	result = (char *)malloc(sizeof(char) * (total + 1));
	if (!result)
		return (result);
	*result = 0;
	ft_putchar(size, strs, sep, result);
	return (result);
}
