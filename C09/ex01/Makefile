CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRCDIR = srcs
INCDIR = includes

TARGET = libft.a
SOURCES = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	ar -rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ $< 

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
