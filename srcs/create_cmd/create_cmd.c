/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 04:01:25 by amonier           #+#    #+#             */
/*   Updated: 2023/05/24 03:48:19 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*last_part_path(char *path)
{
	int		pos;
	char	*str;

	pos = find_last_char(path, '/');
	str = ft_strdup(&path[pos + 1]);
	return (str);
}

int	no_slash(t_pipars *pip, t_vcmd *vcmd)
{
	int	i;

	i = 0;
	while (pip->paths && (pip->paths)[i])
	{
		vcmd->path = ft_join_triple((pip->paths)[i], "/", vcmd->cmd[0]);
		if (access(vcmd->path, F_OK & X_OK) != -1)
			return (1);
		free(vcmd->path);
		i++;
	}
	return (0);
}

void	create_cmd(t_pipars *pip, t_vcmd *vcmd, int numcmd)
{
	vcmd->cmd = ft_split((pip->cmds)[numcmd], ' ');
	if (check_char((vcmd->cmd)[0], '/') == 1)
	{
		vcmd->path = ft_strdup((vcmd->cmd)[0]);
		free((vcmd->cmd)[0]);
		(vcmd->cmd)[0] = last_part_path(vcmd->path);
		if (access(vcmd->path, F_OK & X_OK) != -1)
			return ;
		free(vcmd->path);
	}
	else if (check_char((vcmd->cmd)[0], '/') == 0)
	{
		if (no_slash(pip, vcmd) == 1)
			return ;
	}
	vcmd->path = NULL;
	return ;
}

// int	check_slash(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str == NULL || str[0] == '\0')
// 		return (-1);
// 	while (str[i])
// 	{
// 		if (str[i] == '/')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	find_last_char(char *str, char c)
// {
// 	int	i;
// 	int	final_pos;

// 	i = 0;
// 	final_pos = -1;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			final_pos = i;
// 		i++;
// 	}
// 	return (final_pos);
// }

// char	*last_part_path(char *path)
// {
// 	int 	pos;
// 	char	*str;

// 	pos = find_last_char(path, '/');
// 	str = ft_strdup(&path[pos + 1]);
// 	return(str);
// }

// void    create_cmd(t_pipars *pip, t_vcmd *vcmd, int numcmd)
// {
// 	int	i;

// 	i = 0;

// 	/*
// 	le premier if peut etre enlever 
// 	car si on gere un split sur des espaces seul
// 	alors le premier peut etre enlevable 
// 	FAIRE DES TESTS POUR VERIFIER 
// 	*/
// 	if ((pip->cmds)[numcmd][0] == '\0')
// 	{
// 		vcmd->cmd = NULL;
// 		vcmd->path = NULL;
// 		vcmd->cmdfind = 0;
// 		return;
// 	}
// 	vcmd->cmd = ft_split((pip->cmds)[numcmd], ' ');
// 	if (check_slash((vcmd->cmd)[0]) == 1)
// 	{
// 		// ici on nous a donne le path
// 		vcmd->path = ft_strdup((vcmd->cmd)[0]);
// 		free((vcmd->cmd)[0]);
// 		(vcmd->cmd)[0] = last_part_path(vcmd->path);
// 		if (access(vcmd->path, F_OK & X_OK) != -1)
// 		{
// 			// on est good
// 			vcmd->cmdfind = 1;
// 			return;
// 		}
// 		free(vcmd->path);
// 	}
// 	else if (check_slash((vcmd->cmd)[0]) == 0)
// 	{
// 		while ((pip->paths)[i])
// 		{
// 			vcmd->path = ft_join_triple((pip->paths)[i], "/", vcmd->cmd[0]);
// 			if (access(vcmd->path, F_OK & X_OK) != -1)
// 			{
// 				// on est good
// 				vcmd->cmdfind = 1;
// 				return;
// 			}
// 			free(vcmd->path);
// 			i++;
// 		}
// 	}
// 	clear_double_tab(vcmd->cmd);
// 	vcmd->cmd = NULL;
// 	vcmd->path = NULL;
// 	vcmd->cmdfind = 0;
// 	return;
// 	// il faut free tout ce qu on a cree avant de recommencer
// }
