# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 18:04:15 by lpohribn          #+#    #+#              #
#    Updated: 2018/03/15 18:04:17 by lpohribn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./libft/
INC_DIR = ./inc/wolf3d.h

SRC = main.c \
	ft_op_n_rd_map.c \
	ft_events.c \
	ft_raycasting.c \
	ft_textures.c \
	ft_draw_image.c \
	ft_record_map.c \
	ft_validation_map.c \
	ft_floor_ceiling.c \
	ft_movement.c \
	ft_minimap.c \
	ft_error.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS = -Wall -Werror -Wextra

H_FLAGS = -I $(INC_DIR) -I $(LIB_DIR)

MINILIBX = -lmlx -framework OpenGL -framework AppKit

LIBFT = $(LIB_DIR)libft.a

LIBFT_FLAGS = -lft -L $(LIB_DIR)

all: $(NAME)
	
$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(MINILIBX) $(H_FLAGS) $(LIBFT_FLAGS) $(LIBFT)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o : %.c $(INC_DIR)
	gcc -c $< -o $@ -I $(FLAGS) $(H_FLAGS)

clean :
	rm -rf $(OBJ)
	make clean -C $(LIB_DIR)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIB_DIR)

re : fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
