/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:20:05 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/01 22:15:54 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	arg_check(int argc, char **argv)
{
	int	open_test;

	if (argc < 5)
		ft_error(1, argv[argc - 1]);
	open_test = open(argv[1], O_RDONLY);
	if (open_test == -1)
		ft_error(0, argv[1]);
	close(open_test);
	return (0);
}
