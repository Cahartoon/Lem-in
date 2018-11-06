# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edinguim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 03:24:54 by edinguim          #+#    #+#              #
#    Updated: 2018/10/24 04:42:34 by edinguim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all

CC= gcc

CFLAGS= -Wall -Wextra -Werror

NAME= lem-in

LIB= ./libft/libft.a

INC= ./includes/lem_in.h

SRC= ./srcs/algorithm.c\
	 ./srcs/find_way.c\
	 ./srcs/free_memory.c\
	 ./srcs/init_links.c\
	 ./srcs/init_pipes.c\
	 ./srcs/init_rooms.c\
	 ./srcs/lets_go.c\
	 ./srcs/main.c\
	 ./srcs/parse.c\
	 ./srcs/set_graph.c\
	 ./srcs/tools_1.c\
	 ./srcs/tools_2.c\
	 ./srcs/tools_3.c\
	 ./srcs/tools_4.c\
	 ./srcs/tools_5.c\
	 ./srcs/tools_6.c

OBJ= $(SRC:.c=.o)

all: $(OBJ) $(NAME)

$(NAME):
	@echo "Make libft.a"
	@$(MAKE) -C ./libft
	@echo "Make lem-in"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -I $(INC) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C ./libft clean
	@echo "Object files deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "Lem-in deleted"
	@$(MAKE) -C ./libft fclean

re: fclean all
