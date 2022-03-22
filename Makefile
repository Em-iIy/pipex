# ---------------------------------------Name
NAME = pipex

# ---------------------------------------Colors
ESC = \033
NORMAL = $(ESC)[m\017
BOLD = $(ESC)[1m
GREEN = $(ESC)[0;92m$(BOLD)
BLUE = $(ESC)[0;94m$(BOLD)

# ---------------------------------------Files
FILES_SRCS =	pipex.c \
				parsing.c \
				children.c \
				libft_utils.c \
				libft_split_utils.c \
				error_exit.c \

FILES_OBJS = $(FILES_SRCS:.c=.o)

# ---------------------------------------Directories
DIR_SRCS = ./srcs/
DIR_OBJS = ./objs/
vpath %.c $(DIR_SRCS)

#----------------------------------------Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

#----------------------------------------Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

#----------------------------------------Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -Iinc

#------------------------------Debug
# CFLAGS += -g
# CFLAGS += -fsanitize=address

#----------------------------------------Making
all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) made$(NORMAL)"

$(DIR_OBJS)%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

#------------------------------Directories
$(DIR_OBJS):
	@mkdir -p $@

#----------------------------------------Cleaning
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re