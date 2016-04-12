CXX = g++
CXXFLAGS = -std=c++1y -Wall -Wextra -Werror -pedantic -Isrc/ -Isrc/video
CXXLIBS = $(FLAGCV) $(LINKCV)
DEBUG = -g
BIN = bee-trail
LINKCV = `pkg-config --libs opencv`
FLAGCV = `pkg-config --cflags opencv`
OBJ = ${SRC_ALL:.cc=.o}
SRC_ALL = $(SRC) #$(SRC_VID)
SRC = $(addprefix $(DIR_SRC)/,main.cc option-parser.cc option-manager.cc)
SRC_VID = $(addprefix $(DIR_VID)/, VideoManager.cc)
DIR_VID = $(DIR_SRC)/video
DIR_SRC = src

.PHONY: all build debug check clean

all: ${BIN}

${BIN}:  build
	${CXX} ${CXXFLAGS} -o $@ ${OBJ} -L/usr/lib/x86_64-linux-gnu -lboost_program_options ${CXXLIBS}

build: $(OBJ)

debug: CXXFLAGS += ${DEBUG}
debug: CXX = clang++
debug: clean ${BIN}

check: clean  ${BIN}
	./${BIN} tests/test

clean:
	${RM} ${BIN}
	${RM} ${OBJ}
