NAME        = libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = ft_atoi.c \
              ft_putchar_fd.c \
              ft_putnbr_fd.c \
              ft_strncmp.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
              PRINTF/ft_printf.c \
              PRINTF/ft_putcharb_fd.c \
			  PRINTF/print_char.c \
			  PRINTF/print_int_dec.c \
			  PRINTF/print_percent.c \
			  PRINTF/print_pointer.c \
			  PRINTF/print_string.c \
			  PRINTF/print_unsigned.c \
			  PRINTF/print_xuplo_16.c

OBJS        = $(SRCS:.c=.o)

INCLUDES    = -I. -I ft_printf

all:        $(NAME)

$(NAME):    $(OBJS)
            ar rcs $(NAME) $(OBJS)

%.o:        %.c
            $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
            rm -f $(OBJS)

fclean:     clean
            rm -f $(NAME)

re:         fclean all

.PHONY:     all clean fclean re