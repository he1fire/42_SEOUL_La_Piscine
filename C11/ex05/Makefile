CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = do-op
SOURCES = main.c ft_func.c
OBJECTS = $(SOURCES:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
