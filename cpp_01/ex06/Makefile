# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 23:57:59 by daparici          #+#    #+#              #
#    Updated: 2024/09/22 17:46:39 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = harlFilter

vpath			%.hpp includes
vpath			%.cpp src
vpath			%.o obj

INCLUDE		=   -Iinclude/
SRC = main.cpp  Harl.cpp
OBJ_DIR = obj

CC = c++
SANITIZER	=   -g3 -fsanitize=address -g
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) $(SANITIZER)

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