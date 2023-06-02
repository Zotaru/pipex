/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_pipars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:55:07 by amonier           #+#    #+#             */
/*   Updated: 2023/05/25 03:11:24 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	clear_pipars(t_pipars *pip)
{
	clear_double_tab(pip->cmds);
	clear_double_tab(pip->paths);
	free(pip->infile);
	free(pip->outfile);
}
