# Compiler settings - Windows
CC=gcc
CFLAGS=-Wall -Wextra -g
EXE=.exe

# Directories
SRC_DIR=src
TEST_DIR=test
BIN_DIR=bin

# Source files
MAIN_SRC=$(SRC_DIR)/main.c
QUEUE_SRC=$(SRC_DIR)/queue.c
TEST_SRC=$(TEST_DIR)/performance_test.c

# Object files
MAIN_OBJ=$(BIN_DIR)/main.o
QUEUE_OBJ=$(BIN_DIR)/queue.o
TEST_OBJ=$(BIN_DIR)/performance_test.o

# Executables
MAIN_EXE=$(BIN_DIR)/pharmacy$(EXE)
TEST_EXE=$(BIN_DIR)/performance_test$(EXE)

# Default target
all: $(BIN_DIR) $(MAIN_EXE) $(TEST_EXE)

# Create bin directory
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Main program
$(MAIN_EXE): $(MAIN_OBJ) $(QUEUE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Performance test program
$(TEST_EXE): $(TEST_OBJ) $(QUEUE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIN_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean
clean:
	rm -rf $(BIN_DIR)

# Run main program
run: $(MAIN_EXE)
	./$(MAIN_EXE)

# Run performance test
test: $(TEST_EXE)
	./$(TEST_EXE)

.PHONY: all clean run test
