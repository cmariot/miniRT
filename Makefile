# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/03/20 16:13:42 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                             EXECUTABLE'S NAME                                #
# **************************************************************************** #


NAME			 = miniRT



# **************************************************************************** #
#                                 COMPILATION                                  #
# **************************************************************************** #


CC				 = clang


CFLAGS			 = -Wall -Wextra -Werror


INCLUDES		 = -I includes
INCLUDES		+= -I libft/includes


# **************************************************************************** #
#                                  LINKAGE                                     #
# **************************************************************************** #


LFLAGS			 = -Wall -Wextra -Werror


LIBRAIRY		 = -L ./libft -lft
LIBRAIRY		+= -L ./libft/srcs/print -lprint
LIBRAIRY		+= -L /usr/lib -lm


# **************************************************************************** #
#                                  MINILIBX                                    #
# **************************************************************************** #


# Select the correct minilibX for the current system
# Works on macOS (ARM64) & Linux

UNAME 			:= $(shell uname -m)


ifeq ($(UNAME), arm64)

	MLX			 = mlx_macos
	LIBRAIRY	+= -framework OpenGL -framework AppKit

else

	MLX			 = mlx_linux
	INCLUDES	+= -I /usr/include -O3
	LIBRAIRY	+= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11

endif


INCLUDES		+= -I $(MLX)
LIBRAIRY		+= -L $(MLX) -lmlx



# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #


DIRSRC		= srcs/


SRC			= main.c


SRCS		= $(addprefix $(DIRSRC), $(SRC))



# **************************************************************************** #
#                                OBJECT FILES                                  #
# **************************************************************************** #


DIROBJ		= objs/


OBJ			= $(SRC:.c=.o)


DIROBJS		= $(addprefix $(DIROBJ), $(OBJ))



# **************************************************************************** #
#                                  COLORS                                      #
# **************************************************************************** #


GREEN		= \033[32;1m
RED			= \033[31;1m
YELLOW		= \033[33;1m
CYAN		= \033[36;1m
RESET		= \033[0m



# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #


.SILENT : all


all : header $(NAME) footer


$(DIROBJ)%.o: $(DIRSRC)%.c
		@mkdir -p $(DIROBJ)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(NAME)	: $(DIROBJS)
		@make -C libft
		@make -C $(MLX)
		$(CC) $(LFLAGS) $(DIROBJS) $(LIBRAIRY) -o $(NAME)
		@printf "\n"


leaks :	all
		valgrind --leak-check=full ./$(NAME)


norm :
		@norminette


clean :
		@rm -rf $(DIROBJ)
		@make clean -C libft
		@make clean -C $(MLX)
		@printf "$(RED)"
		@printf "Object files removed\n"
		@printf "$(RESET)"


fclean :
		@-rm -f $(NAME)
		@-rm -rf $(DIROBJ)
		@make fclean -C libft
		@make clean -C $(MLX)
		@printf "$(RED)"
		@printf "Binary and object files removed\n"
		@printf "$(RESET)"


re :	fclean all


header :
		@printf "$(CYAN)"
		@printf "MINIRT COMPILATION\n"
		@printf "$(RESET)"


footer :
		@printf "$(CYAN)"
		@printf "➤     SUCCESS\n"
		@printf "\nUSAGE\n"
		@printf "$(RESET)"
		@printf "./miniRT scene.rt\n"


.PHONY : fclean
