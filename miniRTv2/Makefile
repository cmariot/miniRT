# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/05/03 17:08:55 by cmariot          ###   ########.fr        #
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


CFLAGS			 = -Wall -Wextra -Werror -g3


INCLUDES		 = -I includes
INCLUDES		+= -I libft/includes


# **************************************************************************** #
#                                  LINKAGE                                     #
# **************************************************************************** #


LFLAGS			 = -Wall -Wextra -Werror -g3


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
	LIBRAIRY	+= -L mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11

endif


INCLUDES		+= -I $(MLX)
LIBRAIRY		+= -L $(MLX) -lmlx



# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #


DIRSRC		= srcs/

UTILS		= error.c \
			  print_structure.c \
			  free_world.c \

PARSING		= parsing.c \
			  check_extension.c \
			  check_reading_access.c \
			  get_object_list.c \
			  memory_allocation.c \
			  fill_world.c \
			  new_sphere.c \
			  new_plan.c \
			  new_cylinder.c \
			  new_camera.c \
			  new_ambient.c \
			  new_light.c \
			  utils.c \

#RAYTRACING	= rendering.c \
#			  intersection.c
#
MLX_DIR		= open_window.c \
			  key_hook.c \
			  close_window.c

VECTORS		= new_vector.c \
			  add_vector.c \
			  div_vector.c \
			  length.c \
			  mul_vector.c \
			  normalize.c \
			  norm.c \
			  norm_square.c \
			  scalar_product.c \
			  sub_vector.c

SRC			= main.c \
			  $(addprefix parsing/, $(PARSING)) \
			  $(addprefix utils/, $(UTILS)) \
			  $(addprefix mlx/, $(MLX_DIR)) \
			  $(addprefix vectors/, $(VECTORS)) \
#			  $(addprefix raytracing/, $(RAYTRACING)) \

SRCS		= $(addprefix $(DIRSRC), $(SRC))



# **************************************************************************** #
#                                OBJECT FILES                                  #
# **************************************************************************** #


DIROBJ		= objs/

SUB_OBJ_DIR = objs/parsing \
			  objs/utils \
			  objs/raytracing \
			  objs/mlx \
			  objs/vectors

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


bonus : all


$(DIROBJ)%.o: $(DIRSRC)%.c
		@mkdir -p $(SUB_OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(NAME)	: $(DIROBJS)
		@printf "$(CYAN)"
		@printf "\nMLX COMPILATION\n"
		@printf "$(RESET)"
		@make -C $(MLX) --no-print-directory
		@make -C libft --no-print-directory
		$(CC) $(LFLAGS) $(DIROBJS) $(LIBRAIRY) -o $(NAME)
		@printf "\n"


leaks :	all
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) scenes/00_minimaliste.rt

test :	all
		./miniRT scenes/minimaliste.rt

norm :
		@norminette srcs includes libft


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
		@make fclean -C libft --no-print-directory
		@make clean -C $(MLX) --no-print-directory
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
