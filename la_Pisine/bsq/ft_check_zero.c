/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:18:16 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/15 00:18:20 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_double_check(char *c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < 3)
	{
		k = 0;
		while (k < i)
		{
			if (c[k++] == c[i])
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_is_printable(char c)
{
	if (!(c >= 32 && c <= 126))
		return (0);
	return (1);
}

int	count_0th_row(char *buf)
{
	int	count;

	count = 0;
	while (buf[count] != '\n' && buf[count] != '\0')
		count++;
	if (buf[count] == '\0')
		return (0);
	return (count);
}

int	ft_put_c(char *buf, int count, char *c)
{
	int	k;

	k = 0;
	while (k < 3)
	{
		if (!ft_is_printable(buf[count - (k + 1)]))
			return (0);
		c[2 - k] = buf[count - (k + 1)];
		k++;
	}
	c[k] = '\0';
	return (1);
}

char	*check_0th_row(char *buf, int *row, char *c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = count_0th_row(buf);
	if (count < 4)
		return (0);
	if (!ft_put_c(buf, count, c))
		return (0);
	while ((*buf >= '0' && *buf <= '9') && i < count - 3)
	{
		*row = *row * 10 + *(buf++) - '0';
		i++;
	}
	if (i != count - 3)
		return (0);
	buf += 3;
	if (*buf != '\n' || ft_double_check(c))
		return (0);
	buf++;
	if (*buf == '\0')
		return (0);
	return (buf);
}
