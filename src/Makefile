CXXFLAGS = -std=c++1y -Wall -Wextra -pedantic -g -I./ -Isrc/video -O0
CXXLIBS = $(FLAGCV) $(LINKCV)
DEBUG = -g
BIN = bee-trail
LINKCV = `pkg-config --libs opencv`
FLAGCV = `pkg-config --cflags opencv`
OBJ = ${SRC_ALL:.cc=.o}
SRC_ALL = $(SRC) $(SRC_SWA) $(SRC_FFU)
SRC = test.cc

SRC_SWA = $(addprefix $(DIR_SWA)/, particle.cc)
DIR_SWA = swarm

SRC_FFU = $(addprefix $(DIR_FFU)/, image-descriptor.cc distance-middle.cc)
DIR_FFU = ffunctions

.PHONY: all build debug check clean

all: ${BIN}

${BIN}:  build
	${CXX} ${CXXFLAGS} -o $@ ${OBJ} -L/usr/lib/x86_64-linux-gnu -lboost_program_options ${CXXLIBS}

build: $(OBJ)

error: CXXFLAGS += -Werror
error: ${BIN}

debug: CXXFLAGS += ${DEBUG}
debug: CXX = clang++
debug: clean ${BIN}

check: clean  ${BIN}
	./${BIN} tests/test

clean:
	${RM} ${BIN}
	${RM} ${OBJ}
