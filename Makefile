# Program name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Directories
LIBFTDIR = libft
FT_PRINTFDIR = ft_printf

# Source files
SRCS = push_swap.c input_handling.c stack_init.c stack_utils.c

OBJS = $(SRCS:.c=.o)

# Include paths
INCLUDES = -I. -I$(LIBFTDIR) -I$(FT_PRINTFDIR)

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
FT_PRINTF = $(FT_PRINTFDIR)/libftprintf.a

# Default target
all: $(NAME)

# Compile object files with dependency tracking
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft (only if not up to date)
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

# Build ft_printf (only if not up to date)
$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTFDIR)

# Create the executable (no relinking if dependencies haven't changed)
$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

# Clean object files
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FT_PRINTFDIR) clean

# Clean everything
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FT_PRINTFDIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re