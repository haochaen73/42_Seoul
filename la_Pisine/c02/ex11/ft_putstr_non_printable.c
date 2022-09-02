/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:57:15 by youngjki          #+#    #+#             */
/*   Updated: 2022/08/31 13:02:59 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	dtoh(unsigned char *str)
{
	char	quo;
	char	rem;
	char	result[2];

	quo = *str / 16;
	rem = *str % 16;
	if (quo > 9)
		quo += 87;
	else
		quo += 48;
	if (rem > 9)
		rem += 87;
	else
		rem += 48;
	result[0] = quo;
	result[1] = rem;
	write(1, result, 2);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*value;

	while (*str)
	{
		if (*str >= 32 && *str <= 126)
		{
			write(1, str, 1);
			str++;
		}
		else
		{
			write(1, "\\", 1);
			value = (unsigned char *)str;
			dtoh(value);
			str++;
		}
	}
}
