/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:09:38 by amonier           #+#    #+#             */
/*   Updated: 2023/05/31 23:49:00 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/Includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipexparsing
{
	char	*infile;
	char	*outfile;
	char	**cmds;
	char	**paths;
	char	**envp;
	int		*pid;
	int		nbcmd;
	int		status_here_doc;
}			t_pipars;

typedef struct s_vectcmd
{
	char	*path;
	char	**cmd;
}			t_vcmd;

//-----------pipex-------------------
void		pipex(t_pipars *pip, int **fd_pipe);

//-----------child-------------------
void		child(t_pipars *pip, t_vcmd *macmd, int **fd_pipe, int position);

//-----------environment--------------
char		**environment(char **envp);

//------------parsing-----------------
void		parsing(t_pipars *pip, int argc, char **argv);
void		create_here_doc(char **argv);
void		parsing_here_doc(t_pipars *pip, int argc, char **argv);

void		free_all_security(t_pipars *pip, int i_act);

//------------create_cmd-------------
void		create_cmd(t_pipars *pip, t_vcmd *vcmd, int numcmd);

//------------pipe_fd------------------
void		security_malloc(int **fd_tab, int i_act);
int			**pipe_fd(int nb_pipe);
void		close_pipe(int **fd_tab, int size);

//-----------utils--------------------
char		*ft_join_triple(char *s1, char *s2, char *s3);
void		clear_pipars(t_pipars *pip);
void		clear_double_tab(char **tab);
void		error_exit(void);
int			ft_strlen_double_tab(char **str);
void		clear_double_tab_int(int **fd_tab, int size);
int			check_char(char *str, char c);
int			find_last_char(char *str, char c);

#endif