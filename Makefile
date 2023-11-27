# Name of the output library
NAME = libft.a

# Source code directory
SRC_DIR = ./src

# Object files directory
OBJ_DIR = obj

# List of source files
CFILES := \
    ${SRC_DIR}/ft_atoi.c \
    ${SRC_DIR}/ft_bzero.c \
    ${SRC_DIR}/ft_calloc.c \
    ${SRC_DIR}/ft_isalnum.c \
    ${SRC_DIR}/ft_isalpha.c \
    ${SRC_DIR}/ft_isascii.c \
    ${SRC_DIR}/ft_isdigit.c \
    ${SRC_DIR}/ft_isprint.c \
    ${SRC_DIR}/ft_memcmp.c \
    ${SRC_DIR}/ft_memcpy.c \
    ${SRC_DIR}/ft_memchr.c \
    ${SRC_DIR}/ft_memmove.c \
    ${SRC_DIR}/ft_memset.c \
    ${SRC_DIR}/ft_strchr.c \
    ${SRC_DIR}/ft_strdup.c \
    ${SRC_DIR}/ft_strlcat.c \
    ${SRC_DIR}/ft_strlcpy.c \
    ${SRC_DIR}/ft_strlen.c \
    ${SRC_DIR}/ft_strncmp.c \
    ${SRC_DIR}/ft_strnstr.c \
    ${SRC_DIR}/ft_strrchr.c \
    ${SRC_DIR}/ft_tolower.c \
    ${SRC_DIR}/ft_toupper.c \
    ${SRC_DIR}/ft_substr.c \
    ${SRC_DIR}/ft_strjoin.c \
    ${SRC_DIR}/ft_strtrim.c \
    ${SRC_DIR}/ft_split.c \
    ${SRC_DIR}/ft_itoa.c \
    ${SRC_DIR}/ft_strmapi.c \
    ${SRC_DIR}/ft_striteri.c \
    ${SRC_DIR}/ft_putchar_fd.c \
    ${SRC_DIR}/ft_putstr_fd.c \
    ${SRC_DIR}/ft_putendl_fd.c \
    ${SRC_DIR}/ft_putnbr_fd.c \

# Generate object files from source files
OFILES := $(patsubst ${SRC_DIR}/%.c,${OBJ_DIR}/%.o,${CFILES})

# Compiler and compilation flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c99 -ggdb -pedantic

# Rule to create the obj directory if it doesn't exist
${OBJ_DIR}:
	@echo "Creating directory: ${OBJ_DIR}"
	mkdir -p ${OBJ_DIR}

# Rule to build a .o file from a .c file
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	@echo "Compiling: $<"
	${CC} ${CFLAGS} -c $< -o $@
	# Explanation: Compile a .c file into a .o file using gcc with specified flags

# Rule to build the library
${NAME}: ${OFILES}
	@echo "Building library: ${NAME}"
	ar rc $@ $^
	ranlib $@
	@echo "Library built successfully"
	# Explanation: Build the library (libft.a) from object files using ar and ranlib

# Rule to build everything
all: ${NAME}
	@echo "Build complete"
	# Explanation: Default target is to build the library

# Rule to clean object files and the library
clean:
	@echo "Removing object files in ${OBJ_DIR}"
	rm -rf ${OBJ_DIR}
	@echo "Clean complete"
	# Explanation: Remove object files and the library

# Rule to rebuild everything
re: fclean all
	@echo "Rebuild complete"
	# Explanation: Rebuild everything by cleaning and then building

# Phony targets (not real files)
.PHONY: all clean fclean re
