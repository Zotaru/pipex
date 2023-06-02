/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:14:51 by amonier           #+#    #+#             */
/*   Updated: 2023/05/25 03:08:52 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_all_security(t_pipars *pip, int i_act)
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

void	parsing(t_pipars *pip, int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5)
		error_exit();
	pip->infile = ft_strdup(argv[1]);
	if (pip->infile == NULL)
		return ;
	pip->outfile = ft_strdup(argv[argc - 1]);
	if (pip->outfile == NULL)
		return (free(pip->infile));
	pip->cmds = malloc(sizeof(char *) * (argc - 3 + 1));
	if (pip->cmds == NULL)
		return (free(pip->infile), free(pip->outfile));
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
}
