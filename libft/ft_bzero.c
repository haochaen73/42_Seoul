/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:51:27 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/03 20:51:31 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*new_dest;
	size_t			i;

	new_dest = s;
	i = 0;
	while (i++ < n)
		*new_dest++ = 0;
	return (s);
}
