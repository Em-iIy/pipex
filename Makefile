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
# CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g
INC = -Iinc

#----------------------------------------Making
all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Pipex made$(NORMAL)"