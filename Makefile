# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stempels <stempels@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 10:47:36 by stempels          #+#    #+#              #
#    Updated: 2025/01/13 16:56:40 by stempels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------COMPILER-------------------------------------#
CC = cc
CCFLAGS = -Wall -Wextra -Werror
CPPFLAGS = $(INC_FLAG)

#---------------------------------LINKER---------------------------------------#

#----------------------------------MAIN----------------------------------------#
MAIN_NAME = main_printf
MAIN_DIR = misc 
INC_FLAG = -I ../$(INC_DIR)
MAIN_C = misc/main_printf.c
MAIN_O = misc/main_printf.o

#-----------------------------------SRC----------------------------------------#
SRC_DIR = src
SRC = $(addprefix src/ft_, $(addsuffix .c, printf printf_utils get_ptr)) 
SRC_BONUS = $(addsuffix _bonus.c, ft_printf ft_printf_utils get_len get_fill)

#-----------------------------------OBJ----------------------------------------#
OBJ_DIR = obj
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
OBJ_BONUS := $(SRC_BONUS:%.c=%.o)

#-----------------------------------LIB----------------------------------------#
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_FLAG = -I $(LIBFT_DIR)/$(INC_DIR)

#----------------------------------HEADER--------------------------------------#
INC_DIR = include
INC_FLAG += -I$(INC_DIR)

#----------------------------------RULES---------------------------------------#
NAME = libftprintf.a
NAME_EXEC = ft_printf.out

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) ./$(NAME)
	ar rs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(CPPFLAGS) -c $< -o $@

lib:	$(LIBFT) 
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MAIN_O): $(MAIN_C)
	$(CC) $(CCFLAGS) -L. -lftprintf -c $(MAIN_C)  $(CPPFLAGS) -o $(MAIN_O)

exec: $(NAME_EXEC)
$(NAME_EXEC): $(NAME) $(MAIN_O)
	$(CC) $(CCFLAGS) $(MAIN_O) -L. -lftprintf -o $@

bonus: $(OBJ_BONUS) $(LIBRARY)
	ar rc
	ar s
	touch bonus
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)
	rm -rf 

libclean:
	$(MAKE) clean -C $(LIBFT_DIR)	
	rm -rf $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	rm -rf $(MAIN_O)

ffclean: fclean libclean

re: ffclean all

.PHONY: all clean libclean fclean ffclean re
