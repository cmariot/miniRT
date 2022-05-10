# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/05/10 16:44:46 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                              EXECUTABLE'S NAME                               #
# **************************************************************************** #


NAME			 = miniRT

SCENE_TEST		 = scenes/00_minimaliste.rt


# **************************************************************************** #
#                                 COMPILATION                                  #
# **************************************************************************** #


CC				 = clang


CFLAGS			 = -Wall -Wextra -Werror -g3 -O3
LFLAGS			 = -Wall -Wextra -Werror -g3 -O3


INCLUDES		 = -I includes
INCLUDES		+= -I $(MLX)



LIBRARY			 = -L libft -lft
LIBRARY			+= -L libft/srcs/print -lprint
LIBRARY			+= -L /usr/lib -lm


# **************************************************************************** #
#                                  MINILIBX                                    #
# **************************************************************************** #


# Select the correct minilibX for the current system
# Works on macOS (ARM64) & Linux

UNAME 			:= $(shell uname -m)

ifeq ($(UNAME), arm64)

	MLX			 = mlx_macos
	LIBRARY		+= -L mlx_macos -lmlx -framework OpenGL -framework AppKit
	SRC_SUBDIR	+= mlx/close_window_macos.c

else

	MLX			 = mlx_linux
	LIBRARY		+= -L mlx_linux -lmlx -lmlx_Linux -L /usr/lib -lXext -lX11
	SRC_SUBDIR	+= mlx/close_window_linux.c

endif



# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #


SRC_ROOTDIR		= srcs/

SRC_SUBDIR	   += main.c \
				  $(addprefix parsing/, $(PARSING)) \
				  $(addprefix utils/, $(UTILS)) \
				  $(addprefix mlx/, $(MLX_DIR)) \
				  $(addprefix vectors/, $(VECTORS)) \
				  $(addprefix raytracer/, $(RAYTRACER)) \
				  $(addprefix intersection/, $(INTER))


MAIN		= main.c

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
			  utils.c

RAYTRACER	= raytracer.c \
			  ray_generator.c \
			  check_intersection.c \
			  illumination.c \
			  shadow.c

INTER		= intersection_sphere.c \
			  intersection_plan.c \
			  intersection_cylindre.c

MLX_DIR		= open_window.c \
			  create_images.c \
			  mlx_putpixel.c \
			  key_hook.c

UTILS		= error.c \
			  print_structure.c \
			  print_structure2.c \
			  free_world.c

VECTORS		= new_vector.c \
			  add_vector.c \
			  div_vector.c \
			  length.c \
			  mul_vector.c \
			  normalize.c \
			  norm.c \
			  norm_square.c \
			  scalar_product.c \
			  cross_product.c \
			  sub_vector.c


SRCS		= $(addprefix $(SRC_ROOTDIR), $(SRC_SUBDIR))



# **************************************************************************** #
#                                OBJECT FILES                                  #
# **************************************************************************** #


DIROBJ		= objs/

SUB_OBJ_DIR = objs/parsing \
			  objs/utils \
			  objs/raytracer \
			  objs/mlx \
			  objs/intersection \
			  objs/vectors

OBJ			= $(SRC_SUBDIR:.c=.o)


DIROBJS		= $(addprefix $(DIROBJ), $(OBJ))



# **************************************************************************** #
#                                  COLORS                                      #
# **************************************************************************** #


RED			= \033[31;1m
CYAN		= \033[36;1m
RESET		= \033[0m



# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #


.SILENT : all


all : header $(NAME) footer


bonus : all


$(DIROBJ)%.o: $(SRC_ROOTDIR)%.c
		@mkdir -p $(SUB_OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(NAME)	: $(DIROBJS)
		@printf "$(CYAN)"
		@printf "\nMLX COMPILATION\n"
		@printf "$(RESET)"
		@make -C $(MLX) --no-print-directory
		@make -C libft --no-print-directory
		$(CC) $(LFLAGS) $(DIROBJS) $(LIBRARY) -o $(NAME)
		@printf "\n"


leaks :	all
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(SCENE_TEST)


test :	all
		./miniRT $(SCENE_TEST)


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
