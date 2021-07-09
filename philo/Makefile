# -*- This is a Makefile -*-

NAME=philo
CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS= utility/init.c utility/utils.c utility/ft_atoi.c utility/ft_strlen.c \
utility/ft_isdigit.c philo/philo.c philo/controller.c philo/eat.c philo/sleep.c

all: $(NAME)

$(NAME):$(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	@ rm -rf $(NAME)

fclean:

re: fclean all

