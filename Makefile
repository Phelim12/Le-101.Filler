# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/08 18:11:02 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2017/12/08 18:11:02 by clcreuso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

C_FLAGS = -Wall -Wextra -Werror

NAME = players/clcreuso.filler

DIR_INC = Libft/Includes/

DIR_SRC = Sources/

DIR_LIB = Libft/

NAME_SRC = 	algo_controle_filler.c algo_filler.c main.c refresh_game_filler.c \
			algo_dist_filler.c params_filler.c tools_filler.c

SRC =	$(addprefix $(DIR_SRC), $(NAME_SRC))

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(DIR_LIB)
	@$(CC) $(OBJ) -L $(DIR_LIB) -lft -o $(NAME) 
	@echo "\033[0;32m✅️   make ft_ls."

./%.o: ./%.c
	@$(CC) -I $(DIR_INC) -o $@ -c $< 
	@echo "\033[0;32m✅️   $@ created."

clean:
	@make clean -C $(DIR_LIB)
	@rm -f $(OBJ)
	@echo "\033[38;5;202m🗑️   clean ft_ls.\033[0m\033[K" 

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(NAME)
	@echo "\033[38;5;196m🗑️   fclean ft_ls.\033[0m\033[K" 

re: fclean all

