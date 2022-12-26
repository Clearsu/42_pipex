/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:01:42 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/03 21:01:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	arg_check(int argc, char **argv)
{
	int	open_test;

	if (argv[1] && ft_strncmp(argv[1], "here_doc", 8) == 0)
		return (1);
	if (argc < 5)
		ft_error(1, argv[argc - 1]);
	open_test = open(argv[1], O_RDONLY);
	if (open_test == -1)
		ft_error(0, argv[1]);
	close(open_test);
	return (0);
}
