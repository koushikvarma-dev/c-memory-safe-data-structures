CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Iinclude
BUILD_DIR := build
TARGET := $(BUILD_DIR)/test_data_structures

.PHONY: all test sanitize clean

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): src/data_structures.c tests/test_data_structures.c include/data_structures.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) src/data_structures.c tests/test_data_structures.c -o $(TARGET)

test: $(TARGET)
	./$(TARGET)

sanitize: CFLAGS += -fsanitize=address,undefined -fno-omit-frame-pointer -g
sanitize: clean $(TARGET)

clean:
	rm -rf $(BUILD_DIR)
