#Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes
SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = \
	    $(SRC_DIR)/ft_string/ft_strlen.c \
	    $(SRC_DIR)/ft_string/ft_strchr.c \
	    $(SRC_DIR)/ft_string/ft_strrchr.c \
	    $(SRC_DIR)/ft_string/ft_strncmp.c \
	    $(SRC_DIR)/ft_string/ft_strlcpy.c \
	    $(SRC_DIR)/ft_string/ft_strlcat.c \
	    $(SRC_DIR)/ft_string/ft_strnstr.c \
	    $(SRC_DIR)/ft_string/ft_strdup.c \
	    $(SRC_DIR)/ft_string/ft_substr.c \
	    $(SRC_DIR)/ft_string/ft_strjoin.c \
	    $(SRC_DIR)/ft_string/ft_strtrim.c \
	    $(SRC_DIR)/ft_string/ft_split.c \
	    $(SRC_DIR)/ft_string/ft_strmapi.c \
	    $(SRC_DIR)/ft_string/ft_striteri.c \
	    $(SRC_DIR)/ft_memory/ft_memset.c \
	    $(SRC_DIR)/ft_memory/ft_bzero.c \
	    $(SRC_DIR)/ft_memory/ft_memcpy.c \
	    $(SRC_DIR)/ft_memory/ft_memmove.c \
	    $(SRC_DIR)/ft_memory/ft_memchr.c \
	    $(SRC_DIR)/ft_memory/ft_memcmp.c \
	    $(SRC_DIR)/ft_memory/ft_calloc.c \
	    $(SRC_DIR)/ft_ctype/ft_isalpha.c \
	    $(SRC_DIR)/ft_ctype/ft_isdigit.c \
	    $(SRC_DIR)/ft_ctype/ft_isalnum.c \
	    $(SRC_DIR)/ft_ctype/ft_isascii.c \
	    $(SRC_DIR)/ft_ctype/ft_isprint.c \
	    $(SRC_DIR)/ft_ctype/ft_toupper.c \
	$(SRC_DIR)/ft_ctype/ft_tolower.c \
	$(SRC_DIR)/ft_conversion/ft_atoi.c \
	$(SRC_DIR)/ft_conversion/ft_itoa.c \
	$(SRC_DIR)/ft_io/ft_putchar_fd.c \
	$(SRC_DIR)/ft_io/ft_putstr_fd.c \
	$(SRC_DIR)/ft_io/ft_putendl_fd.c \
	$(SRC_DIR)/ft_io/ft_putnbr_fd.c \
	$(SRC_DIR)/ft_printf/ft_printf.c \
    	$(SRC_DIR)/ft_printf/ft_putchar.c \
    	$(SRC_DIR)/ft_printf/ft_putstr.c \
    	$(SRC_DIR)/ft_printf/ft_putnbr.c \
    	$(SRC_DIR)/ft_printf/ft_puthex.c \
    	$(SRC_DIR)/ft_printf/ft_putptr.c \
    	$(SRC_DIR)/ft_printf/ft_putunsigned.c \
	$(SRC_DIR)/getnextline/get_next_line.c \
	$(SRC_DIR)/getnextline/get_next_line_utils.c

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
RM = rm -f
AR = ar rcs
#Rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "Archiving object files into $(NAME)..."
	@ar rcs $(NAME) $(OBJ_FILES)
	@echo "$(NAME) created successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)  # Create the subdirectory if it doesn't exist
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned!"

fclean: clean
	@echo "Cleaning $(NAME)..."
	@rm -f $(NAME)
	@echo "$(NAME) cleaned!"

re: fclean all

.PHONY: all clean fclean re

