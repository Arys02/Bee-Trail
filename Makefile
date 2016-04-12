CXX = g++
CXXFLAGS = -std=c++1y -Wall -Wextra -Werror -pedantic -Isrc/
DEBUG = -g
BIN = bee-trail
OBJ = ${SRC_ALL:.cc=.o}
SRC_ALL = src/main.cc src/option-parser.cc src/option-manager.cc

.PHONY: all build debug check clean

all: ${BIN}

${BIN}:  build
	${CXX} ${CXXFLAGS} -o $@ ${OBJ} -L/usr/lib/x86_64-linux-gnu -lboost_program_options

build: $(OBJ)

debug: CXXFLAGS += ${DEBUG}
debug: CXX = clang++
debug: clean ${BIN}

check: clean  ${BIN}
	./${BIN} tests/test

clean:
	${RM} ${BIN}
	${RM} ${OBJ}
