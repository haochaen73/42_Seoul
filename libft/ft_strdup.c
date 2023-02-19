/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:29:22 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/05 17:29:23 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned char	*new_s1;
	unsigned char	*dup;
	int				i;

	new_s1 = (unsigned char *)s1;
	i = 0;
	dup = (unsigned char *)malloc(sizeof(unsigned char) * \
	(ft_strlen((char *)new_s1) + 1));
	if (!dup)
		return ((char *)dup);
	while (*new_s1)
	{
		dup[i] = *new_s1++;
		i++;
	}
	dup[i] = '\0';
	return ((char *)dup);
}
