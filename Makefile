NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Sources
SRCS		= push_swap.c \
			  pushop.c \
			  rotateop.c \
			  state.c

# Libft sources
LIBFT_SRCS	= libft/ft_atoi.c \
			  libft/ft_putchar_fd.c \
			  libft/ft_putnbr_fd.c

OBJS		= $(SRCS:.c=.o)
LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)

ALL_OBJS	= $(OBJS) $(LIBFT_OBJS)

all:		$(NAME)

$(NAME):	$(ALL_OBJS)
			$(CC) $(CFLAGS) $(ALL_OBJS) -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -I. -I libft -c $< -o $@

clean:
			rm -f $(ALL_OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re