# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 20:47:54 by daparici          #+#    #+#              #
#    Updated: 2024/09/25 20:49:46 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

vpath                   %.hpp includes
vpath                   %.cpp src
vpath                   %.o obj

INCLUDE         =   -Iinclude/
SRC = main.cpp  Fixed.cpp
OBJ_DIR = obj

CC = c++
SANITIZER       =   -g3 -fsanitize=address -g
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