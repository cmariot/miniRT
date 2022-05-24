# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/05/22 12:01:35 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                              EXECUTABLE'S NAME                               #
# **************************************************************************** #


NAME			 = miniRT


SCENE_TEST		 = scenes/00_test.rt



# **************************************************************************** #
#                                 COMPILATION                                  #
# **************************************************************************** #


CC				 = clang


CFLAGS			 = -Wall -Wextra -Werror -O3  -g3
LFLAGS			 = -Wall -Wextra -Werror -O3 -g3


INCLUDES		 = -I includes
INCLUDES		+= -I libft/includes
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
	LIBRARY		+= -L $(MLX) -lmlx -framework OpenGL -framework AppKit

else

	MLX			 = mlx_linux
	LIBRARY		+= -L $(MLX) -lmlx -lmlx_Linux -L /usr/lib -lXext -lX11

endif



# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #


SRC_ROOTDIR		= srcs/


SRC_SUBDIR	    = $(MAIN) \
				  $(addprefix vectors/, $(VECTORS)) \
				  $(addprefix intersection/, $(INTER)) \
				  $(addprefix second_intersection/, $(2ND_INTER)) \
				  $(addprefix utils/, $(UTILS)) \
				  $(addprefix raytracer/, $(RAYTRACER)) \
				  $(addprefix parsing/, $(PARSING)) \
				  $(addprefix mlx/, $(MLX_DIR))


MAIN			= main.c


PARSING			= parsing.c \
				  check_extension.c \
				  check_reading_access.c \
				  count_objects.c \
				  memory_allocation.c \
				  fill_structure.c \
				  new_sphere.c \
				  new_plan.c \
				  new_cylinder.c \
				  new_camera.c \
				  new_ambient.c \
				  new_light.c \
				  utils.c


RAYTRACER		= raytracer.c \
				  lookat.c \
				  ray_generator.c \
				  compute_color.c \
				  second_ray_generator.c \
				  in_light.c \
				  light_reflexion.c \
				  objects_translation.c


INTER			= intersection_sphere.c \
				  intersection_plan.c \
				  intersection_cylindre.c \
				  utils.c


2ND_INTER		= second_inter_cyl.c \
				  second_inter_plan.c \
				  second_inter_sphere.c \


MLX_DIR			= open_window.c \
				  create_image.c \
				  mlx_putpixel.c \
				  key_handler.c

				  ifeq ($(UNAME), arm64)
				  	MLX_DIR	+= close_window_macos.c
				  else
				  	MLX_DIR	+= close_window_linux.c
				  endif


UTILS			= error.c \
				  print_structure.c \
				  print_structure2.c \
				  free_structure.c


VECTORS			= new_vector.c \
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


SRCS			= $(addprefix $(SRC_ROOTDIR), $(SRC_SUBDIR))



# **************************************************************************** #
#                                OBJECT FILES                                  #
# **************************************************************************** #


OBJ_ROOTDIR		= objs/

OBJ_SUBDIR		= $(SRC_SUBDIR:.c=.o)

OBJ_DIR 		= $(shell find ./srcs -type d | sed s/".\/srcs"/".\/objs"/g)

OBJS			= $(addprefix $(OBJ_ROOTDIR), $(OBJ_SUBDIR))

DEPENDS			:= $(OBJS:.o=.d)



# **************************************************************************** #
#                                  COLORS                                      #
# **************************************************************************** #


RED				= \033[31;1m
CYAN			= \033[36;1m
RESET			= \033[0m



# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #


.SILENT : 		all


all : 			header $(NAME) footer


bonus:
				@make -C miniRT_bonus --no-print-directory


$(OBJ_ROOTDIR)%.o: $(SRC_ROOTDIR)%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@


$(NAME)	: 		$(OBJS)
				@printf "$(CYAN)"
				@printf "\nMLX COMPILATION\n"
				@printf "$(RESET)"
				@make -C $(MLX) --no-print-directory
				@make -C libft --no-print-directory
				$(CC) $(LFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)
				@printf "\n"


leaks :			all
				valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) $(SCENE_TEST)


test :			all
				./$(NAME) $(SCENE_TEST)


norm :
				@norminette srcs includes libft miniRT_bonus/srcs miniRT_bonus/includes


clean :
				@rm -rf $(OBJ_ROOTDIR) $(DEPENDS)
				@make clean -C libft --no-print-directory
				@make clean -C $(MLX) --no-print-directory
				@make clean -C miniRT_bonus --no-print-directory
				@printf "$(RED)"
				@printf "Object files removed\n"
				@printf "$(RESET)"


fclean :
				@-rm -f $(NAME)
				@-rm -rf $(OBJ_ROOTDIR) $(DEPENDS)
				@make fclean -C libft --no-print-directory
				@make clean -C $(MLX) --no-print-directory
				@make fclean -C miniRT_bonus --no-print-directory
				@printf "$(RED)"
				@printf "Binary and object files removed\n"
				@printf "$(RESET)"


re :			fclean all


header :
				@printf "$(CYAN)"
				@printf "MINIRT COMPILATION\n"
				@printf "$(RESET)"


footer :
				@printf "$(CYAN)"
				@printf "➤     SUCCESS\n"
				@printf "\nUSAGE\n"
				@printf "$(RESET)"
				@printf "./$(NAME) scene.rt\n"


-include $(DEPENDS)


.PHONY : 		all clean fclean re
