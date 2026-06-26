# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Isrc

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

# Output
TARGET = $(BUILD_DIR)/scheduler_tests

# Default rule
all: $(BUILD_DIR) $(TARGET)

# Build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build test executable
$(TARGET): $(SRC_FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Run tests
test: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)
