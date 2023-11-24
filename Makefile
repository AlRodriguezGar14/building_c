# Name of the output library
NAME = libft.a

# Source code directory
SRC_DIR = .

# Object files directory
OBJ_DIR = obj

# List of source files
CFILES := \
    ${SRC_DIR}/atoi.c \
    ${SRC_DIR}/bzero.c \
    ${SRC_DIR}/calloc.c \
    ${SRC_DIR}/isalnum.c \
    ${SRC_DIR}/isalpha.c \
    ${SRC_DIR}/isascii.c \
    ${SRC_DIR}/isdigit.c \
    ${SRC_DIR}/isprint.c \
    ${SRC_DIR}/memcmp.c \
    ${SRC_DIR}/memcpy.c \
    ${SRC_DIR}/memchr.c \
    ${SRC_DIR}/memmove.c \
    ${SRC_DIR}/memset.c \
    ${SRC_DIR}/strchr.c \
    ${SRC_DIR}/strdup.c \
    ${SRC_DIR}/strlcat.c \
    ${SRC_DIR}/strlcpy.c \
    ${SRC_DIR}/strlen.c \
    ${SRC_DIR}/strncmp.c \
    ${SRC_DIR}/strnstr.c \
    ${SRC_DIR}/strrchr.c \
    ${SRC_DIR}/tolower.c \
    ${SRC_DIR}/toupper.c \
    ${SRC_DIR}/ft_substr.c \
    ${SRC_DIR}/ft_strjoin.c \

# Generate object files from source files
OFILES := $(patsubst ${SRC_DIR}/%.c,${OBJ_DIR}/%.o,${CFILES})

# Compiler and compilation flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c99

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
