NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Sources
SRCS        = push_swap.c \
              pushop.c \
              rotateop.c \
              state.c \
              revrotateop.c \
              swapop.c \
              greed_sort.c \
              tools_greed.c \
              more_tools.c \
              greedy_path.c \
              select_sort.c \
              chunk_sort.c \
              chunk_tools.c \
              disorder.c \
			  benchmod.c

OBJS        = $(SRCS:.c=.o)

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -I. -I $(LIBFT_DIR)

all:        $(NAME)

$(NAME):    $(LIBFT) $(OBJS)
            $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
            @make -C $(LIBFT_DIR)

%.o:        %.c
            $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
            rm -f $(OBJS)
            @make clean -C $(LIBFT_DIR)

fclean:     clean
            rm -f $(NAME)
            @make fclean -C $(LIBFT_DIR)

re:         fclean all

.PHONY:     all clean fclean re