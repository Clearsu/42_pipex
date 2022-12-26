/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:08:06 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/29 18:54:34 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_demi(int n)
{
	ft_putnbr(n);
	if (n == 0)
		return (1);
	return (ft_nbr_len(n));
}

int	print_unsign(unsigned int n)
{
	ft_putnbr(n);
	if (n == 0)
		return (1);
	return (ft_nbr_len(n));
}
