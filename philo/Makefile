# -*- This is a Makefile -*-

NAME=philo
CC=gcc
CFLAGS=-Wall -Wextra -Werror
OPT=-O3
SRCS= utility/init.c utility/utils.c utility/ft_atoi.c utility/ft_strlen.c utility/ft_isdigit.c controller.c eat.c sleep.c philo.c

all: $(NAME)

$(NAME):$(SRCS)
	@ echo "Building"
	@ echo "Done."
	@ $(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(OPT)

clean:
	@ rm -rf $(NAME)

fclean: clean

re: fclean all

