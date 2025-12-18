# کامپایلر و تنظیمات
CC = gcc
CFLAGS = -Wall -std=c99 -Wextra -I ./include
LDFLAGS = -L ./lib -lraylib -lopengl32 -lgdi32 -lwinmm -lm

# فایل‌های سورس و خروجی
SOURCES = main.c map.c player.c raycaster.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = raycaster.exe

# قانون پیش‌فرض (اولین قانونی که اجرا می‌شود)
all: $(TARGET)

# قانون ساخت فایل اجرایی (لینک کردن)
$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

# قانون تمیز کردن فایل‌های بیلد
clean:
	del $(TARGET)