# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 17:41:20 by daparici          #+#    #+#              #
#    Updated: 2024/09/19 15:54:34 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

vpath			%.hpp include
vpath			%.cpp src
vpath			%.o obj

INCLUDES = -Iinclude/
SRC = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
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