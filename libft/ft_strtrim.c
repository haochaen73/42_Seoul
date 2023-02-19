/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:28:54 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/12 15:29:09 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			front;
	size_t			rear;
	unsigned char	*str;

	str = 0;
	if (*s1 == 0)
	{
		str = (unsigned char *)ft_strdup("");
		return ((char *)str);
	}
	if (s1 != 0 && set != 0)
	{
		front = 0;
		rear = ft_strlen(s1);
		while (s1[front] && ft_strchr(set, s1[front]))
			front++;
		while (s1[rear - 1] && ft_strchr(set, s1[rear - 1]) && rear > front)
			rear--;
		str = (unsigned char *)malloc(sizeof(unsigned char) * \
		(rear - front + 1));
		if (str)
			ft_strlcpy((char *)str, &s1[front], rear - front + 1);
	}
	return ((char *)str);
}
