NAME = libft.a

INCLUDES = -I includes

SUB_DIRS = is lst mem put str to gnl printf

DIR_SRCS = $(foreach dir, $(SUB_DIRS), $(addprefix srcs/, $(dir)))
DIR_OBJS = $(foreach dir, $(SUB_DIRS), $(addprefix objs/, $(dir)))
SRCS = $(foreach dir, $(DIR_SRCS), $(wildcard $(dir)/*.c))
OBJS = $(subst srcs, objs, $(SRCS:.c=.o))

AR = ar -rcs
CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -rf

objs/%.o :	srcs/%.c
			@mkdir -p objs $(DIR_OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re