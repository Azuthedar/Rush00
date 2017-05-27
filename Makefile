# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbuys <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 08:33:10 by jbuys             #+#    #+#              #
#    Updated: 2017/05/27 08:33:13 by jbuys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC = ./classes/*.cpp ./*.cpp

OBJ = ./*.o

INCL = ./classes/*.hpp ./*.hpp

C_FLAGS = -Wall -Wextra -Werror

NCURSES = -lncurses

all: $(NAME)

$(NAME):
	@echo "Compiling $(NAME) with flags: ($(C_FLAGS)) and $(NCURSES)"
	@clang++ $(C_FLAGS) -c $(SRC)
	@clang++ $(OBJ) -o $(NAME) $(NCURSES)
	@echo "Created executable: $(NAME)"

clean:
	@echo "Cleaning root directory and class directory"
	@rm -f $(OBJ)

fclean: clean
	@echo "Removing executable $(NAME)"
	@rm -f $(NAME)

re: fclean all
