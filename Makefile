# تنظیمات کامپایلر
CC = gcc
CFLAGS = -Wall -std=c99 -Wextra -I./include




LDFLAGS = -L./lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SOURCES = main.c map.c player.c raycaster.c
OBJECTS = $(SOURCES:.c=.o)


TARGET = raycaster

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJECTS)
