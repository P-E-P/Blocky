CC=gcc
CFLAGS= -Werror -Wall -Wextra -std=c99 -O3 -mtune=native 
DEBUG_CFLAGS= -Wall -Wextra -Wunused -Wunreachable-code -std=c99 -g3 -O0 -ggdb

LIBS=-lm
BDIR=../build
DDIR=../debug
OUT=blocky

SOURCES=$(shell find . -type f -name '*.c')
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))


EXECUTABLE=$(BDIR)/$(OUT)
DEXECUTABLE=$(DDIR)/$(OUT)


all:	debug  $(EXECUTABLE)
	@echo "Built debug friendly executable."

export:	build $(EXECUTABLE)
	@echo "Build finished"

$(EXECUTABLE):  $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LIBS)

$(OBJECTS): %.o : %.c
	$(CC) $(CFLAGS) -c $< $(LIBS) -o $@


build:
	@mkdir -p $(BDIR)

debug:
	@mkdir -p $(BDIR)
	$(eval CFLAGS=$(DEBUG_CFLAGS))


.PHONY: clean

clean:
	@rm -rf $(EXECUTABLE) $(OBJECTS) $(BDIR)
	@find . -name "*~" -exec rm {} \;
	@find . -name "*.o" -exec rm {} \;

help:
	@echo "Targets:"
	@echo "help	- display this help message."
	@echo "all	- build the project with all debug options."
	@echo "export	- build the project using current cpu instruction set and maximum optimisations."
	@echo "clean	- cleanup .o, trash files and remove latest build."
