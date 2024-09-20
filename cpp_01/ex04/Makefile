# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 12:34:42 by daparici          #+#    #+#              #
#    Updated: 2024/09/20 23:41:59 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sed_is_for_losers

vpath			%.cpp src
vpath			%.o obj

SRC = main.cpp 
OBJ_DIR = obj

CC = c++
SANITIZER	=   -g3 -fsanitize=address -g
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDES) $(SANITIZER)

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

RM = rm -f

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
