CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror -pedantic -Isrc/
DEBUG = -g
BIN = bee-trail
OBJ = ${SRC_ALL:.cc=.o}
SRC_ALL = src/main.cc

.PHONY: all build debug check clean

all: ${BIN}

${BIN}:  build
	${CXX} ${CXXFLAGS} -o $@ ${OBJ}

build: $(OBJ)

debug: CXXFLAGS += ${DEBUG}
debug: CXX = clang++
debug: clean ${BIN}

check: clean  ${BIN}
	./${BIN} tests/test

clean:
	${RM} ${BIN}
	${RM} ${OBJ}
