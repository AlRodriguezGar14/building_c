CC       = cc
HEADERS_DIR = .
CFLAGS   = -Wall -Wextra -Werror -ggdb -pedantic -I $(HEADERS_DIR)
NAME     = libft.a
RM       = rm -rf

SRC_DIR  = src
OBJ_DIR  = obj

# Find every .c file within the SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS})

all: $(NAME)

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): ${OBJ_DIR} ${OBJS}
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
