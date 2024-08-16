CC = gcc
FLAGS = -Wextra -Wall -Werror
SOURCES = *.c
OBJS = $(SOURCES:.c=.o)
NAME = libftprintf.a
RM = rm -f

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $^ -I../libft/ ../libft/libft.a

$(NAME): $(OBJS)
	@ar rcs $@ $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	@$(CC) $(FLAGS) tester.c ft_printf.c -I../libft/ ../libft/libft.a
	@./a.out
	@$(RM) a.out