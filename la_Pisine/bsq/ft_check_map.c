/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:16:59 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/15 00:17:01 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_firstrow_check(char *buf, int *col)
{
	int	i;

	i = 0;
	while (buf[i] != '\n')
	{
		(*col)++;
		i++;
	}
	i++;
	return (i);
}

void	ft_while_increase(char *buf, int *i, int *len)
{
	while (buf[*i] != '\n' && buf[*i] != '\0')
	{
		(*len)++;
		(*i)++;
	}
}

int	ft_rowcol_check(char *buf, int *row, int *col, int total)
{
	int	len;
	int	i;
	int	row_len;
	int	first_row;

	len = 0;
	row_len = 1;
	first_row = 1;
	i = ft_firstrow_check(buf, col);
	while (i < total - 5)
	{
		len = 0;
		ft_while_increase(buf, &i, &len);
		row_len++;
		if (*col != len || buf[i] == '\0')
			return (0);
		if (buf[i] == '\n' && buf[i + 1] == '\0')
			break ;
		i++;
	}
	if (row_len != *row)
		return (0);
	return (1);
}

int	ft_exist_in_c(char *c, char *buf, int total)
{
	int	idx;

	idx = 0;
	while (idx < total - 5)
	{
		if (buf[idx] != '\n' && buf[idx] != '\0')
		{
			if (!(c[0] == buf[idx] || c[1] == buf[idx]))
				return (0);
		}
		if (buf[idx] == '\0')
			break ;
		idx++;
	}
	return (1);
}
