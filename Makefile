# Declaration of variables
CC = gcc
CC_FLAGS = -Wall -Wextra -Wno-unused-parameter
LIBS_FLAGS = $$(pkg-config --cflags --libs sdl2)

# File names
EXEC = drvn
SOURCES =	$(wildcard source/*.c) \
			$(wildcard source/*/*.c)
OBJECTS = $(SOURCES:.c=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS_FLAGS) -o $(EXEC)

# To obtain object files
%.o: %.c
	$(CC) -c $(CC_FLAGS) $(LIBS_FLAGS) $< -o $@

# To remove generated files
.PHONY: clean
clean:
	rm -f $(EXEC) $(OBJECTS)
