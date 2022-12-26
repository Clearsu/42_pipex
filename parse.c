/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:34:20 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/21 19:30:02 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	vars_malloc(t_vars *vars)
{
	vars->cmd_path = (char **)malloc(sizeof(char *) * (vars->cmd_num + 1));
	vars->argv = (char ***)malloc(sizeof(char **) * (vars->cmd_num + 1));
	if (!vars->cmd_path || !vars->argv)
		ft_error(2, NULL);
	vars->cmd_path[vars->cmd_num] = NULL;
	vars->argv[vars->cmd_num] = NULL;
}

static void	put_argv_4_execve(t_vars *vars, char **argv)
{
	size_t	i;

	i = 0;
	while (i < vars->cmd_num)
	{
		vars->argv[i] = ft_split(argv[i + 2], ' ');
		if (!vars->argv[i])
			ft_error(2, NULL);
		i++;
	}
}

void	parse_path(t_vars *vars, char **envp)
{
	char	**temp_list;
	char	*temp;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i++], "PATH", 4) == 0)
			break ;
	}
	temp_list = ft_split(envp[--i], '=');
	vars->path = ft_split(temp_list[1], ':');
	if (!temp_list || !vars->path)
		ft_error(2, NULL);
	free_split(temp_list);
	i = 0;
	while (vars->path[i])
	{
		temp = ft_strjoin(vars->path[i], "/");
		if (!temp)
			ft_error(2, NULL);
		free(vars->path[i]);
		vars->path[i++] = temp;
	}
}

void	search_path(t_vars *vars)
{	
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (vars->argv[i])
	{
		j = 0;
		while (vars->path[j])
		{
			temp = ft_strjoin(vars->path[j++], vars->argv[i][0]);
			if (!temp)
				ft_error(2, NULL);
			if (access(temp, X_OK) == 0)
			{
				vars->cmd_path[i] = temp;
				break ;
			}
			else
				free(temp);
		}
		if (vars->path[j] == NULL)
			ft_error(1, vars->argv[i][0]);
		i++;
	}
}

void	parse(t_vars *vars, int argc, char **argv, char **envp)
{
	vars->infile = argv[1];
	vars->outfile = argv[argc - 1];
	vars->cmd_num = argc - 3;
	vars->envp = envp;
	vars_malloc(vars);
	put_argv_4_execve(vars, argv);
	parse_path(vars, envp);
	search_path(vars);
}
