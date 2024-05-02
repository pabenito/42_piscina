# Makefile

NAME = rush-02  # El nombre del programa que se va a generar

# Opciones de compilación
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Archivos fuente y objetos
SRC = fuente1.c fuente2.c fuente3.c
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
