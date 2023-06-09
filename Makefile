# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 20:40:36 by anmarque          #+#    #+#              #
#    Updated: 2023/06/09 17:49:16 by cmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#/--------------COLORS-----------------/
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

INFO = $(CYAN) ℹ️
SUCCESS = $(GREEN) ✅
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
TRASH = $(RED) 🗑


#/-----------Files and Flags--------------------/
NAME = Cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror  -g 

SRC_DIR = ./src/
OBJ_DIR = ./obj/

INC = ./includes/

MAP = map map_utils parse_map
PLAYER = player movement
HOOKS = hooks
PAINT = paint

SRCS = 	$(addsuffix .c, $(addprefix map/, $(MAP))) \
		$(addsuffix .c, $(addprefix hooks/, $(HOOKS))) \
		$(addsuffix .c, $(addprefix paint/, $(PAINT))) \
		$(addsuffix .c, $(addprefix player/, $(PLAYER))) \
		utils.c \
		main.c \

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))


#/--------------Libft-----------------/
LIBFT = -L libft -lft

LIBFT_INC = ./libft


#/--------------MLX42-----------------/
MLX42_LIB = MLX42/build/libmlx42.a

MLX42 = ./MLX42/

DEPENDENCIES_MAC = $(MLX42_LIB) -framework Cocoa -framework OpenGL -framework IOKit

DEPENDENCIES_LINUX = /home/cristian/42/42_Cub3D/MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

INC_MLX = $(MLX42)/include

GLFW =  -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

LINUX = Linux
MAC = Darwin

#/--------------Actions-----------------/
all:  lib obj  $(NAME)


obj:
	@echo "$(INFO) Creating objects folder... $(NOC)"
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/map
	@mkdir -p $(OBJ_DIR)/hooks
	@mkdir -p $(OBJ_DIR)/paint
	@mkdir -p $(OBJ_DIR)/player

lib:
	@make -C ./libft
	@echo "$(NOC)"

$(MLX42_LIB):
	@echo "$(INFO) Compiling MLX42... $(NOC)"
	cmake $(MLX42) -B $(MLX42)/build
	make -C $(MLX42)/build -j4


ifeq ($(shell uname -s), $(LINUX))

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(MLX42_LIB)
	@$(CC) $(CFLAGS) -I $(INC) -I $(INC_MLX) -I $(LIBFT_INC) -o $@ -c $<


$(NAME): $(OBJS) $(MLX42_LIB)
	@echo "$(INFO) Building $(NAME)...$(NOC)"
	@$(CC) $(CFLAGS) $(OBJS) /home/cristian/42/42_Cub3D/MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm $(LIBFT)  -o $(NAME)
	@echo "$(SUCCESS)$(NAME) built successfully!$(NOC)"

else ifeq ($(shell uname -s), $(MAC))

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(MLX42_LIB)
	@$(CC) $(CFLAGS) -I $(INC) -I $(LIBFT_INC) -I $(INC_MLX) -o $@ -c $<


$(NAME): $(OBJS) $(MLX42_LIB)
	@echo "$(INFO) Building $(NAME)...$(NOC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(DEPENDENCIES_MAC) $(GLFW) -o $(NAME)
	@echo "$(SUCCESS)$(NAME) built successfully!$(NOC)"

endif


clean:
	@make clean -C libft/
	@echo "$(NOC)"
	@echo "$(TRASH) Deleting .o files...$(NOC)"
	@rm -rf $(MLX42)/build 
	@rm -rf obj $(OBJS)
	@echo "$(SUCCESS).o files deleted successfully!$(NOC)"
	
	
fclean: clean
	@echo "$(TRASH) Deleting $(NAME)...$(NOC)"
	@rm -rf obj $(NAME)
	@rm -rf $(NAME).dSYM
	@echo "$(SUCCESS)$(NAME) deleted successfully!$(NOC)"


re: fclean 
	@make all

r: all
	./$(NAME)

val: all
	valgrind --leak-check=full ./$(NAME)
	rm -rf $(NAME).dSYM

.PHONY:	all clean fclean re val