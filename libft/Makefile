# Makefile for libft

NAME = libft.a
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -MMD -MP
OBJFILES = $(SOURCES:.c=.o)
OBJFILESB = $(SOURCESB:.c=.o)
SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
		ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line.c get_next_line_utils.c \
		ft_c.c ft_d_i.c ft_hex.c ft_p.c ft_printf.c ft_s.c ft_u.c \

SOURCESB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

DEPS = $(SOURCES:.c=.d)
DEPSB = $(SOURCESB:.c=.d)

all: $(NAME)

$(NAME) : $(OBJFILES)
	ar rcs $(@) $(?)

bonus : $(NAME) $(OBJFILESB)
	ar rcs $(^)
	touch .bonus

.bonus: bonus

clean:
	rm -f $(OBJFILES) $(OBJFILESB) 

fclean:clean
	rm -f $(NAME) $(DEPS) $(DEPSB) .bonus

re:fclean all

.PHONY: all bonus clean fclean re

-include $(DEPS) $(DEPSB)
