/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:21:32 by amonier           #+#    #+#             */
/*   Updated: 2023/05/25 03:16:38 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int			**fd_pipe;
	t_pipars	pip;

	parsing(&pip, argc, argv);
	if (pip.infile == NULL || pip.outfile == NULL || pip.cmds == NULL)
		return (0);
	pip.envp = envp;
	pip.paths = environment(envp);
	pip.nbcmd = argc - 3;
	fd_pipe = pipe_fd(ft_strlen_double_tab(pip.cmds) - 1);
	if (fd_pipe == NULL)
		return (free(pip.infile), free(pip.outfile), clear_double_tab(pip.cmds),
			0);
	pip.pid = malloc(sizeof(int) * pip.nbcmd);
	if (pip.pid == NULL)
		return (free(pip.infile), free(pip.outfile), clear_double_tab(pip.cmds),
			clear_double_tab_int(&(pip.pid), pip.nbcmd), 0);
	pipex(&pip, fd_pipe);
	clear_double_tab_int(fd_pipe, ft_strlen_double_tab(pip.cmds) - 1);
	free(pip.pid);
	clear_pipars(&pip);
	return (1);
}
