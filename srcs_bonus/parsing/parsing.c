/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:14:51 by amonier           #+#    #+#             */
/*   Updated: 2023/06/01 04:07:51 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_all_security(t_pipars *pip, int i_act)
{
	int	i;

	i = 0;
	free(pip->infile);
	free(pip->outfile);
	while (i < i_act)
	{
		free((pip->cmds)[i]);
		i++;
	}
}

int	parsing_norm_2(t_pipars *pip, int argc, char **argv)
{
	pip->infile = ft_strdup(argv[1]);
	if (pip->infile == NULL)
		return (0);
	pip->outfile = ft_strdup(argv[argc - 1]);
	if (pip->outfile == NULL)
		return (free(pip->infile), 0);
	pip->cmds = malloc(sizeof(char *) * (argc - 3 + 1));
	if (pip->cmds == NULL)
		return (free(pip->infile), free(pip->outfile), 0);
	return (1);
}

void	parsing_norm(t_pipars *pip, int argc, char **argv)
{
	int	i;
	int	j;

	pip->status_here_doc = 0;
	if (argc < 5)
		error_exit();
	if (parsing_norm_2(pip, argc, argv) == 0)
		return ;
	i = 0;
	j = 2;
	while (i < argc - 3)
	{
		(pip->cmds)[i] = ft_strdup(argv[j]);
		if ((pip->cmds)[i] == NULL)
			return (free_all_security(pip, i));
		i++;
		j++;
	}
	(pip->cmds)[i] = NULL;
	return ;
}

void	parsing(t_pipars *pip, int argc, char **argv)
{
	if (argc < 2)
		error_exit();
	if (ft_strncmp("here_doc", argv[1], 8) == 0 && argv[1][8] == '\0')
		parsing_here_doc(pip, argc, argv);
	else
		parsing_norm(pip, argc, argv);
	return ;
}
