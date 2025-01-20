# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stempels <stempels@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 10:47:36 by stempels          #+#    #+#              #
#    Updated: 2025/01/20 11:09:18 by stempels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------COMPILER-------------------------------------#
CC = cc
CPPFLAGS = -I.
CCFLAGS = -Wall -Wextra -Werror

#-----------------------------------SRC----------------------------------------#
SRC_DIR = src/
SRC = $(addprefix src/ft_, $(addsuffix .c, printf printf_utils get_ptr libft)) 

#-----------------------------------OBJ----------------------------------------#
OBJ_DIR = obj/
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

#----------------------------------RULES---------------------------------------#
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating $@"
	ar -rcs $(NAME) $(OBJ)
	@echo "$@ created !"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@echo "$(NAME) cleaned !"

fclean: clean
	rm -rf $(NAME)
	@echo "$(NAME) fcleaned !"

re: fclean all

.PHONY: all clean fclean re

#----------------------------TEXT_FORMAT---------------------------------------#
