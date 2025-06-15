NAME    = minishell
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g -Isrc/lexer -Ilibft -Iinclude -Isrc/parser
SRC_DIR = src
OBJ_DIR = obj

SRCS = \
	$(SRC_DIR)/lexer/lexer.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parser/parser.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

LIBFT_DIR   = libft

LIBFT_LIB   = $(LIBFT_DIR)/libft.a

all: $(LIBFT_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -lreadline -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re