/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:51:21 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/03 20:51:24 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*new_dest;
	unsigned char	src;
	size_t			i;

	new_dest = (unsigned char *)dest;
	src = (unsigned char)c;
	i = 0;
	while (i++ < len)
	{
		*new_dest++ = src;
	}
	return (dest);
}
