NAME = libft.a

HEADERS = libft.h
SRCS = ft_string.c ft_memory.c ft_memory_ext.c ft_ctype.c ft_conversion.c \
	ft_list.c ft_list_algo.c ft_print.c ft_split.c ft_string_algo.c \
	ft_string_algo2.c ft_str_base.c ft_buffer.c ft_buffer_util.c\
	ft_handler.c ft_number_handler.c ft_parse_specifier.c\
	ft_printf_justified.c ft_printf.c


OBJS = $(SRCS:.c=.o)
C_FLAGS = -Wall -Wextra -Werror
CC = gcc
AR = ar

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re