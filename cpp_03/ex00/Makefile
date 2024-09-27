# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 20:59:34 by daparici          #+#    #+#              #
#    Updated: 2024/09/27 08:57:53 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	clapTrap

vpath                   %.hpp includes
vpath                   %.cpp src
vpath                   %.o obj

# controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

INCLUDE         =   -Iinclude/
SRC = main.cpp  ClapTrap.cpp
OBJ_DIR = obj

CC = c++
SANITIZER       =   -g3 -fsanitize=address -g
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) $(SANITIZER)

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

RM = rm -f

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	$(CC) $(CPPFLAGS) -c $< -o $@
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

all: $(NAME)
	@printf "$(GREEN)  ____    _     ____    _    ____   ___   ___  ___  \n$(RESET)"
	@printf "$(GREEN) |  _ \  / \   |  _ \  / \  |  _ \ |_ _| / __||_ _| \n$(RESET)"
	@printf "$(GREEN) | | | |/ _ \  | |_) |/ _ \ | |_) | | | | |    | |  \n$(RESET)"
	@printf "$(GREEN) | |_| / ___ \ |  __// ___ \|  _ <  | | | |__  | |  \n$(RESET)"
	@printf "$(GREEN) |____/_/   \_\|_|  /_/   \_\_| \_\|___| \___||___| \n$(RESET)"
	@printf "$(GREEN)                                                    \n$(RESET)"

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re