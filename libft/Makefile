# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
      ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
      ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
      ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
      ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c \
	  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Object files
OBJS = $(SRC:.c=.o)

# Library name
NAME = libft.a

# Rules
all: $(NAME)

# Create the library from object files
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up object files and the library
fclean: clean
	rm -f $(NAME) libft.so

# Recompile everything
re: fclean all

# Phony targets (not actual files)
.PHONY: all clean fclean re so

# Create the shared library (.so file)
so: $(OBJS)
	$(CC) -nostartfiles -fPIC $(CFLAGS) -c $(SRC)
	$(CC) -nostartfiles -shared -o libft.so $(OBJS)
