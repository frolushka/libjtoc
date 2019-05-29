# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 16:14:32 by sbednar           #+#    #+#              #
#    Updated: 2019/05/29 00:52:35 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	libjtoc.a

SRC_DIR			=	./src
OBJ_DIR			=	./obj
INC_DIR			=	./include

SRC				=	main.c	\
					jtoc_read_file.c \
					jtoc_validate.c \
					jtoc_utils.c

OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

INCS		=		-I$(INC_DIR)

CC 			=		gcc
CFLAGS		=		-Wall -Werror -Wextra -g

test: $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(INCS) $(OBJ)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
