/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:09:37 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/30 14:34:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned int n, char c)
{
	unsigned char	num[10];
	int				i;
	int				len;
	char			*base;

	i = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		num[i++] = base[n % 16];
		n /= 16;
	}
	len = i--;
	while (i >= 0)
		write(1, &num[i--], 1);
	return (len);
}

int	print_address(unsigned long long ptr)
{
	unsigned char	num[17];
	int				i;
	int				len;
	char			*base;

	ft_putstr("0x");
	if (ptr == 0)
	{
		ft_putchar('0');
		return (3);
	}
	i = 0;
	base = "0123456789abcdef";
	while (ptr > 0)
	{
		num[i++] = base[ptr % 16];
		ptr /= 16;
	}
	len = i--;
	while (i >= 0)
		write(1, &num[i--], 1);
	return (len + 2);
}
