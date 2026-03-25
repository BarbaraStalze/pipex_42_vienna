# Makefile for so_long

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SOURCES = pipex.c \
		helper_functions.c \
		pathfinder.c \
		error.c \
		parsing.c \
		froking.c \
		children.c \
		
OBJFILES = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJFILES)
	@make -C libft bonus
	$(CC) $(CFLAGS) $(OBJFILES) libft/libft.a -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)
	@make -C libft clean

fclean:clean
	rm -f $(NAME)
	@make -C libft fclean

re:fclean all

.PHONY: all clean fclean re
