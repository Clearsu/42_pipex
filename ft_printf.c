/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:17:25 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 22:57:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char *str, va_list ap)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += print_char(va_arg(ap, int));
	else if (*str == 's')
		count += print_str(va_arg(ap, char *));
	else if (*str == 'p')
		count += print_address(va_arg(ap, unsigned long long));
	else if (*str == 'd' || *str == 'i')
		count += print_demi(va_arg(ap, int));
	else if (*str == 'u')
		count += print_unsign(va_arg(ap, unsigned int));
	else if (*str == 'x' || *str == 'X')
		count += print_hexa(va_arg(ap, unsigned int), *str);
	else if (*str == '%')
	{
		ft_putchar('%');
		count++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		res;
	char	*formats;

	res = 0;
	formats = "cspdiuxX%";
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && ft_findchr(formats, *(str + 1)))
			res += print_format((char *)++str, ap);
		else
		{
			ft_putchar(*str);
			res++;
		}
		str++;
	}
	va_end(ap);
	return (res);
}
