/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subilee <subilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:15:13 by subilee           #+#    #+#             */
/*   Updated: 2022/09/12 22:04:24 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_double_check(char *c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (c[i])
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

char	*check_0th_row(char *buf, int *row, char *c)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	if (!*buf)
		return (0);
	while (*buf != '\n')
	{
		while (*buf >= '0' && *buf <= '9')
		{
			*row *= 10;
			*row += *buf - '0';
			buf++;
			i++;
		}
		if (i == 0)
			return (0);
		while (k < 3)
		{
			c[k++] =  *buf;
			buf++;
		}
		c[k] = '\0';
	}
	buf++;
	if (ft_double_check(c))
		return (0);
	return (buf);
}
