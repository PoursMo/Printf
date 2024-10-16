CC = gcc
FLAGS = -Wextra -Wall -Werror
SOURCES =	ft_printf.c	\
			utils1.c	\
			utils2.c
OBJS = $(SOURCES:.c=.o)
NAME = libftprintf.a
RM = rm -f

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $^

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all