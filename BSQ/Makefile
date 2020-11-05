CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = bsq
SOURCES = main.c input.c error.c etc.c
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
