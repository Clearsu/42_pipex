/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:56:57 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/29 17:17:01 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	char	res;

	res = (char)c;
	write(1, &res, 1);
	return (1);
}

int	print_str(char *s)
{
	int	len;

	if (s)
	{
		len = ft_strlen(s);
		ft_putstr(s);
		return (len);
	}
	ft_putstr("(null)");
	return (6);
}
