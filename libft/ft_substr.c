/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:28:49 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/12 15:29:16 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*result;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) == 0 || (ft_strlen((char *)s) <= start))
		len = 0;
	else if (ft_strlen((char *)s) < start + len)
		len = ft_strlen((char *)s) - start;
	result = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1));
	if (!(result))
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			result[j++] = s[i];
		i++;
	}
	result[j] = '\0';
	return ((char *)result);
}
