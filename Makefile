CC = gcc
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)
BIN = build/buckshot_roulette_c
INCLUDES = -Iinclude

# Default mode
MODE ?= release

ifeq ($(MODE),debug)
    CFLAGS = -Wall -Wextra -Og -g $(INCLUDES)
else ifeq ($(MODE),release)
    CFLAGS = -Wall -Wextra -O3 $(INCLUDES)
else
    $(error Unknown mode '$(MODE)'. Use 'make MODE=debug' or 'make MODE=release')
endif

all: $(BIN)

$(BIN): $(OBJ)
    mkdir -p build
    $(CC) $(OBJ) -o $@

# Rule for compiling object files in the build directory
build/%.o: src/%.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f build
