/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:57:14 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/09 19:55:51 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*src)
{
	int	cnt;

	cnt = 0;
	while (*src)
	{
		cnt++;
		src++;
	}
	return (cnt);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (dup);
	while (*src)
	{
		dup[i] = *src++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
