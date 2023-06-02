/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_pipars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:55:07 by amonier           #+#    #+#             */
/*   Updated: 2023/05/22 04:00:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_pipars(t_pipars *pip)
{
	clear_double_tab(pip->cmds);
	clear_double_tab(pip->paths);
	free(pip->infile);
	free(pip->outfile);
}
