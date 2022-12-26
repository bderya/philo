
NAME	=	philo

CC		=	gcc
CFLAGS	=	-g -pthread

RM		=	rm -rf

SRC		=	$(addprefix src/, init.c main.c philo_behaviour.c philo_control.c timeutils.c utils.c)
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all



.PHONY: all clean fclean re