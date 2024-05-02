# Makefile

NAME = bsq  # El nombre del programa que se va a generar

# Opciones de compilación
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Archivos fuente y objetos
SRC = read.c read_extra.c utils.c malloc.c free.c print_solution.c max_square.c main.c
OBJ = $(SRC:.c=.o)

# Regla por defecto (al ejecutar 'make' sin argumentos)
all: $(NAME)

# Regla para crear el ejecutable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Regla para compilar los archivos fuente a objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos objeto
clean:
	rm -f $(OBJ)

# Regla para limpiar todos los archivos generados durante la compilación
fclean: clean
	rm -f $(NAME)

# Regla para recompilar
re: fclean all

.PHONY: all clean fclean re
