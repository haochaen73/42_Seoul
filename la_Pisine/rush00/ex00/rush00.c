/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunskim@student.42seoul.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:43:53 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/08/28 12:49:07 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LT 'o' 
#define RT 'o'
#define LB 'o'
#define RB 'o'
#define VER '|'
#define HOR '-'
#define NEMO ' '

void	ft_putchar(char c);

void	ft_print_line(int x, int y, int xi, int yi)
{
	if (xi == 0 && yi == 0)
		ft_putchar(LT);
	else if (xi == x - 1 && yi == 0)
		ft_putchar(RT);
	else if (xi == 0 && yi == y - 1)
		ft_putchar(LB);
	else if (xi == x - 1 && yi == y - 1)
		ft_putchar(RB);
	else if (xi == 0 || xi == x - 1)
		ft_putchar(VER);
	else if (yi == 0 || yi == y - 1)
		ft_putchar(HOR);
	else
		ft_putchar(NEMO);
}

void	rush(int x, int y)
{
	int	xi;
	int	yi;

	if (x < 1 || y < 1)
		return ;
	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
		{
			ft_print_line(x, y, xi, yi);
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}
