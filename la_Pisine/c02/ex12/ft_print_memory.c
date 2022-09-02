/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:35:57 by youngjki          #+#    #+#             */
/*   Updated: 2022/08/31 13:41:17 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	ft_hexptr(unsigned long long ptr)
{
	char	*list;
	char	result[16];
	int		i;

	list = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		result[15 - i] = list[ptr % 16];
		ptr /= 16;
		i++;
	}
	i = 0;
	while (i < 16)
	{
		write(1, &result[i], 1);
		i++;
	}
}

void	ft_dtoh(char *str, int len)
{
	char	*list;
	char	result[32];
	int		i;

	list = "0123456789abcdef";
	i = 0;
	while (i < len)
	{
		result[2 * i] = list[str[i] / 16];
		result[2 * i + 1] = list[str[i] % 16];
		i++;
	}
	i = 0;
	while (i < len * 2)
	{
		write(1, &result[i++], 1);
		if (i % 4 == 0)
			write(1, " ", 1);
	}
	while (i < 32)
	{
		write(1, " ", 1);
		if (++i % 4 == 0)
			write(1, " ", 1);
	}
}

void	ft_print(char *saddr, unsigned long long ptr, int len)
{
	char	str[16];
	int		i;

	ft_hexptr(ptr);
	write(1, ": ", 2);
	ft_strncpy(str, saddr, 16);
	ft_dtoh(str, len);
	i = 0;
	while (i < len)
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char					*saddr;
	unsigned long long		ptr;
	int						size1;

	saddr = (char *) addr;
	size1 = size / 16;
	while (size1--)
	{
		ptr = (unsigned long long) saddr;
		ft_print(saddr, ptr, 16);
		saddr += 16;
	}
	ptr = (unsigned long long) saddr;
	if (size % 16 != 0)
		ft_print(saddr, ptr, size % 16);
	return (addr);
}
