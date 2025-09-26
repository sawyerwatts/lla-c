BINARY = demo

SRC = $(shell find src/ -name '*.c' -type f)
# Alt (but non-recursive): SRC = $(wildcard src/*.c)

# Pattern substituation to convert src files into obj files
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

.DEFAULT_GOAL = run

.PHONY: all
all: $(OBJ)

## help: print this help message
.PHONY: help
help:
	@echo 'Usage:'
	@sed -n 's/^##//p' ${MAKEFILE_LIST} | column -t -s ':' | sed -e 's/^/ /'

## clean: remove build artifacts
clean:
	rm -rf obj
	rm -rf bin

## build: build the application
build: $(OBJ)
	@# $? means the list of inputs
	@mkdir bin 2>/dev/null || true
	gcc -o bin/$(BINARY) $?

## run: run the application
run: build
	./bin/demo data.db

obj/%.o : src/%.c
	@# $< is an input file
	@# $@ is an output file
	@# Create obj dirs if needed
	@mkdir $(shell dirname $(shell echo '$@')) 2>/dev/null || true
	gcc -Wall -Werror -c $< -o $@ -Iinclude

