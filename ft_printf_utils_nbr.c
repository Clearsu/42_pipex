/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:53:32 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/29 19:00:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_rev(char *str, int i)
{
	while (i >= 0)
		ft_putchar(*(str + i--));
}

void	ft_putnbr(long long n)
{
	int		i;
	char	nums[20];

	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	while (n > 0)
	{
		nums[i++] = n % 10 + '0';
		n /= 10;
	}
	print_rev(nums, i - 1);
}

int	ft_nbr_len(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
