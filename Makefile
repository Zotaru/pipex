# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amonier <amonier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 22:27:42 by amonier           #+#    #+#              #
#    Updated: 2023/05/31 23:47:33 by amonier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

NAME_BONUS	= pipex_bonus

DIR_SRCS	= srcs

DIR_BONUS	= srcs_bonus

DIR_OBJS	= obj

DIR_OBJS_B	= obj_bonus

SRCS_NAMES		=	\
	main.c			\
	pipex.c			\
	environment/environment.c	\
	utils/clear_double_tab.c	\
	utils/error_exit.c			\
	utils/clear_pipars.c		\
	utils/ft_join_triple.c		\
	utils/ft_strlen_double_tab.c		\
	parsing/parsing.c			\
	create_cmd/create_cmd.c		\
	pipe_fd/pipe_fd.c					\
	child/child.c				\
	utils/clear_double_tab_int.c		\
	pipe_fd/close_pipe.c		\
	utils/check_char.c				\
	utils/find_last_char.c			\
	
BONUS_SRCS_NAMES	=	\
	main.c			\
	pipex.c			\
	environment/environment.c	\
	utils/clear_double_tab.c	\
	utils/error_exit.c			\
	utils/clear_pipars.c		\
	utils/ft_join_triple.c		\
	utils/ft_strlen_double_tab.c		\
	parsing/parsing.c			\
	create_cmd/create_cmd.c		\
	pipe_fd/pipe_fd.c					\
	child/child.c				\
	utils/clear_double_tab_int.c		\
	pipe_fd/close_pipe.c		\
	utils/check_char.c				\
	utils/find_last_char.c			\
	parsing/parsing_here_doc.c		\

OBJS_NAMES	= ${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	= ${BONUS_SRCS_NAMES:.c=.o}

SRCS		= $(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

SRCS_B		= $(addprefix $(DIR_BONUS)/,$(BONUS_SRCS_NAMES))

OBJS		= $(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

OBJS_BONUS	= $(addprefix $(DIR_OBJS_B)/,$(OBJS_NAMES_B))

CC			= cc -g3
CFLAGS		= -Wall -Wextra -Werror
# CFLAGSBONUS	= -pthread
HEAD		= -IIncludes 
# dans le head a la base: -Iminilibx-linux
# MLX			= minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a

RM			= rm -f
# MAKEFLAGS	= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	$(info CREATED $(NAME))
	@echo "\033[34;5mpipex\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
	$(info CREATED $@)

bonus: all $(NAME_BONUS)
	
$(DIR_OBJS_B)/%.o: $(DIR_BONUS)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
	$(info CREATED $@)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) libft/libft.a -o $(NAME_BONUS)
	$(info CREATED $(NAME_BONUS))
	@echo "\033[34;5mpipex BONUS\033[0m"


clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
.SILENT:
