NAME = push_swap

LIB_DIR = libft
LIB = $(addprefix $(LIB_DIR)/, libft.a)

INCLUDE_DIR = include
SRC_DIR = srcs

OPS_SRCS = operations/ft_ops_swap.c\
	operations/ft_ops_push.c\
	operations/ft_ops_rotate.c\
	operations/ft_ops_rrotate.c

STACK_SRCS = stack/ft_stack.c\
	stack/ft_stack_swap.c\
	stack/ft_stack_rotate.c\
	stack/ft_stack_push.c

PARCER_SRCS = parser/ft_parser.c\
	parser/ft_int_parser.c

SORT_SRCS = sort/ft_simple.c\
	sort/ft_medium.c\
	sort/ft_complex.c\
	sort/ft_adaptive.c

SRC_NAMES = main.c ranks.c app.c util.c benchmark.c\
	$(STACK_SRCS)\
	$(OPS_SRCS)\
	$(PARCER_SRCS)\
	$(SORT_SRCS)

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_NAMES))

C_FLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIB_DIR)
CC = cc
RM = rm -rf
MAKE = make

$(NAME): $(SRCS) $(LIB)
	$(CC) $(C_FLAGS) $(SRCS) $(LIB) -o $(NAME)

$(LIB): 
	$(MAKE) -C $(LIB_DIR)

debug: $(SRCS) $(LIB)
	$(CC) -I$(INCLUDE_DIR) -I$(LIB_DIR) -g $(SRCS) $(LIB) -o $(NAME)

all: $(NAME)

clean: 
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all re clean fclean