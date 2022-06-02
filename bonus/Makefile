# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/06/02 10:37:26 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                              EXECUTABLE'S NAME                               #
# **************************************************************************** #


NAME			 = miniRT_bonus


SCENE_TEST		 = scenes/00_test.rt



# **************************************************************************** #
#                                 COMPILATION                                  #
# **************************************************************************** #


CC				 = clang


CFLAGS			 = -Wall -Wextra -Werror -g3 -O3
LFLAGS			 = -Wall -Wextra -Werror -g3 -O3


INCLUDES		 = -I includes
INCLUDES		+= -I ../libft/includes
INCLUDES		+= -I $(MLX)


LIBRARY			 = -L ../libft -lft
LIBRARY			+= -L ../libft/srcs/print -lprint
LIBRARY			+= -L /usr/lib -lm



# **************************************************************************** #
#                                  MINILIBX                                    #
# **************************************************************************** #


# Select the correct minilibX for the current system
# Works on macOS (ARM64) & Linux

UNAME 			:= $(shell uname -m)

ifeq ($(UNAME), arm64)

	MLX			 = ../mlx_macos
	LIBRARY		+= -L $(MLX) -lmlx -framework OpenGL -framework AppKit

else

	MLX			 = ../mlx_linux
	LIBRARY		+= -L $(MLX) -lmlx -lmlx_Linux -L /usr/lib -lXext -lX11

endif



# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #


SRC_ROOTDIR		= srcs/


SRC_SUBDIR	    = $(MAIN) \
				  $(addprefix vectors_bonus/, $(VECTORS)) \
				  $(addprefix intersection_bonus/, $(INTER)) \
				  $(addprefix second_intersection_bonus/, $(2ND_INTER)) \
				  $(addprefix utils_bonus/, $(UTILS)) \
				  $(addprefix raytracer_bonus/, $(RAYTRACER)) \
				  $(addprefix parsing_bonus/, $(PARSING)) \
				  $(addprefix mlx_bonus/, $(MLX_DIR))


MAIN			= main_bonus.c


PARSING			= parsing_bonus.c \
				  check_extension_bonus.c \
				  check_reading_access_bonus.c \
				  count_objects_bonus.c \
				  memory_allocation_bonus.c \
				  fill_structure_bonus.c \
				  new_sphere_bonus.c \
				  new_plan_bonus.c \
				  new_cylinder_bonus.c \
				  new_camera_bonus.c \
				  new_ambient_bonus.c \
				  new_light_bonus.c \
				  new_triangle_bonus.c \
				  utils_bonus.c


RAYTRACER		= raytracer_bonus.c \
				  lookat_bonus.c \
				  ray_generator_bonus.c \
				  compute_color_bonus.c \
				  second_ray_generator_bonus.c \
				  in_light_bonus.c \
				  light_reflexion_bonus.c \
				  objects_translation_bonus.c


INTER			= intersection_sphere_bonus.c \
				  intersection_plan_bonus.c \
				  intersection_cylindre_bonus.c \
				  intersection_triangle_bonus.c \
				  utils_bonus.c


2ND_INTER		= second_inter_cyl_bonus.c \
				  second_inter_plan_bonus.c \
				  second_inter_sphere_bonus.c \
				  second_inter_triangle_bonus.c


MLX_DIR			= open_window_bonus.c \
				  create_image_bonus.c \
				  mlx_putpixel_bonus.c \
				  key_handler_bonus.c

				  ifeq ($(UNAME), arm64)
				  	MLX_DIR	+= close_window_macos_bonus.c
				  else
				  	MLX_DIR	+= close_window_linux_bonus.c
				  endif


UTILS			= error_bonus.c \
				  print_structure_bonus.c \
				  print_structure2_bonus.c \
				  free_structure_bonus.c


VECTORS			= new_vector_bonus.c \
				  add_vector_bonus.c \
				  div_vector_bonus.c \
				  length_bonus.c \
				  mul_vector_bonus.c \
				  normalize_bonus.c \
				  norm_bonus.c \
				  norm_square_bonus.c \
				  scalar_product_bonus.c \
				  cross_product_bonus.c \
				  sub_vector_bonus.c


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


bonus : 		all


$(OBJ_ROOTDIR)%.o: $(SRC_ROOTDIR)%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@


$(NAME)	: 		$(OBJS)
				@printf "$(CYAN)"
				@printf "\nMLX COMPILATION\n"
				@printf "$(RESET)"
				@make -C $(MLX) --no-print-directory
				@make -C ../libft --no-print-directory
				$(CC) $(LFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)
				@printf "\n"


leaks :			all
				valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(SCENE_TEST)


test :			all
				./$(NAME) $(SCENE_TEST)


norm :
				@make norm -C ..


clean :
				@rm -rf $(OBJ_ROOTDIR) $(DEPENDS)
				@make clean -C ../libft
				@make clean -C $(MLX)


fclean :
				@-rm -f $(NAME)
				@-rm -rf $(OBJ_ROOTDIR) $(DEPENDS)
				@make fclean -C ../libft --no-print-directory
				@make clean -C $(MLX) --no-print-directory


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
