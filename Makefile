CC       = cc
HEADERS_DIR = .
CFLAGS   = -Wall -Wextra -Werror -ggdb -pedantic -I $(HEADERS_DIR)
NAME     = libft.a
RM       = rm -rf

SRC_DIR  = src
OBJ_DIR  = obj
BONUS_DIR  = bonus
BONUS_OBJ_DIR  = bonus_obj

# Find every .c file within the SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.c)
BONUSS = $(wildcard $(BONUS_DIR)/*.c)
OBJS := $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS})

all: $(NAME)

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): ${OBJ_DIR} ${OBJS}
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

${BONUS_OBJ_DIR}:
	mkdir -p $(BONUS_OBJ_DIR)

BONUS_OBJS := $(patsubst ${BONUS_DIR}/%.c, ${BONUS_OBJ_DIR}/%.o, ${BONUSS})

${BONUS_OBJ_DIR}/%.o: ${BONUS_DIR}/%.c | ${BONUS_OBJ_DIR}
	$(CC) $(CFLAGS) -c $< -o $@

bonus: ${BONUS_OBJ_DIR} ${BONUS_OBJS}
	ar rc $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
