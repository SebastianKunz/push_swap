# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skunz <skunz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 21:00:49 by skunz             #+#    #+#              #
#    Updated: 2019/02/09 20:04:51 by skunz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################################### GENERAL ##################################

NAME = push_swap

FLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRC_DIR = ./srcs/

SHARED_DIR = ../shared/

SHARED_SRC_DIR = ../shared/srcs/

################################# SOURCES #####################################

SRC = push_swap.c

SHARED_SRC = stack.c operations.c parser.c

###################################### OBJECTS #################################

OBJ_DIR = .obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ += $(addprefix $(OBJ_DIR), $(SHARED_SRC:.c=.o))

################################ LIBRARIES #####################################

LIB_DIR = $(SHARED_DIR)/libraries

LIBFT = -L $(LIB_DIR)/libft/ -lft

###################################### HEADERS #################################

INC_DIR = ./includes/

SHARED_INC_DIR = $(SHARED_DIR)/includes

LIB_HEAD = $(LIB_DIR)/libft/includes/

INC = -I $(LIB_HEAD) -I $(INC_DIR) -I $(SHARED_INC_DIR)

###############################  COLORS AND TEXT  ##############################

#COLORS
COM_COLOR   = \033[0;33m
NO_COLOR    = \033[m

#TEXT
COM_STRING  = "$(NAME) Compilation Successful"
CLEAN_OBJ	= "Cleaned $(NAME) Objects"
CLEAN_NAME	= "Cleaned $(NAME) Binary"

######################################## RULES #################################

all: lib obj $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(LIBFT) -g $^ -o $@
	@echo "$(COM_COLOR)$(COM_STRING)$(NO_COLOR)"

#OBJECTS

##SHARED
$(OBJ_DIR)%.o: $(SHARED_SRC_DIR)%.c
	@gcc $(FLAGS) $(INC) -g -c $< -o $@

##CHECKER
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(FLAGS) $(INC) -g -c $< -o $@

obj:
	@mkdir -p $(OBJ_DIR)

#CHECKER

clean: libclean
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(COM_COLOR)$(CLEAN_OBJ)$(NO_COLOR)"

fclean: clean libfclean
	@/bin/rm -f $(NAME)
	@echo "$(COM_COLOR)$(CLEAN_NAME)$(NO_COLOR)"

#LIBFT

lib:
	@make -C $(LIB_DIR)/libft/ all

libfclean:
	@make -C $(LIB_DIR)/libft/ fclean

libclean:
	@make -C $(LIB_DIR)/libft/ clean

re: fclean all