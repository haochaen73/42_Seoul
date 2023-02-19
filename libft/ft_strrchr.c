/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:46:01 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/03 22:46:05 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	w;
	char			*ans;

	w = (unsigned char)c;
	ans = 0;
	while (*s)
	{
		if (*s == w)
			ans = (char *)s;
		s++;
	}
	if (w == 0)
		return ((char *)s);
	return (ans);
}
