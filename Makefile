# Compiler and toolchain configuration
CC       ?= gcc
TARGET   ?= tempguard

# Directory layout
SRC_DIR  := src
OBJ_DIR  := build

# Sources and generated artifacts
SRCS     := $(SRC_DIR)/main.c $(SRC_DIR)/thermal.c
OBJS     := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS     := $(OBJS:.o=.d)

# Build flags
CPPFLAGS ?=
CFLAGS   ?= -std=c11
WARNINGS := -Wall -Wextra -Wpedantic
DEPFLAGS := -MMD -MP
LDFLAGS  ?=
LDLIBS   ?=

# Default build profile (optimized, no debug symbols)
OPTFLAGS ?= -O2

.PHONY: all debug release run clean help

all: $(TARGET)

release:
	$(MAKE) clean
	$(MAKE) OPTFLAGS='-O2' all

debug:
	$(MAKE) clean
	$(MAKE) OPTFLAGS='-O0 -g3' all

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(WARNINGS) $(OPTFLAGS) $(DEPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

help:
	@printf '%s\n' \
	  'Available targets:' \
	  '  make            Build release binary (default)' \
	  '  make release    Build optimized binary' \
	  '  make debug      Build debug binary with symbols' \
	  '  make run        Build and run the binary' \
	  '  make clean      Remove build artifacts' \
	  '  make help       Show this help message'

-include $(DEPS)
