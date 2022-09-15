/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:07:27 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/08 21:27:46 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_digit_baseto(long atoi_nbr, char *base_to, int *digit)
{
	long	strlen;

	strlen = ft_strlen(base_to);
	if (atoi_nbr < 0)
	{
		(*digit)++;
		atoi_nbr *= -1;
	}
	if (atoi_nbr != 0)
	{
		(*digit)++;
		ft_digit_baseto(atoi_nbr / strlen, base_to, digit);
	}
}

void	ft_putnbr_baseto(char *result, long atoi_nbr, char *base_to, int *i)
{
	int	strlen;

	strlen = ft_strlen(base_to);
	if (atoi_nbr < 0)
	{
		result[0] = '-';
		atoi_nbr *= -1;
		*i = 1;
	}
	if (atoi_nbr != 0)
	{
		ft_putnbr_baseto(result, atoi_nbr / strlen, base_to, i);
		result[(*i)++] = base_to[atoi_nbr % strlen];
	}
}
