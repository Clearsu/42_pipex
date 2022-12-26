/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:14:15 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/03 16:55:20 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	int		h;

	h = arg_check(argc, argv);
	if (h)
		here_doc(&vars, argc, argv, envp);
	else
	{
		parse(&vars, argc, argv, envp);
		pipex(&vars);
	}
	return (0);
}
