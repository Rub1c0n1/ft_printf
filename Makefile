NAME	=	libftprintf.a

SRCS = ft_printf.c \
	ft_hexas.c \
	ft_unsigned_case.c \
	ft_pointer.c \
	libft/ft_putchar_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_strlen.c \
	libft/ft_itoa.c \


HEADER	=	ft_printf.h

OBJ	=	$(patsubst %.c, %.o, $(SRCS))
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o	:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re	:	fclean all