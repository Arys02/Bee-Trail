#CXX = gcc-4.9
CXXFLAGS = -std=c++1y -Wall -Wextra -pedantic -g -Isrc/ -Isrc/video -O3
CXXLIBS = $(FLAGCV) $(LINKCV) -ltbb
DEBUG = -g
BIN = bee-trail
LINKCV = `pkg-config --libs opencv`
FLAGCV = `pkg-config --cflags opencv`
OBJ = ${SRC_ALL:.cc=.o}
SRC_ALL = $(SRC) $(SRC_VID) $(SRC_SWA) $(SRC_FFU)
SRC = $(addprefix $(DIR_SRC)/,main.cc timer.cc )

SRC_VID = $(addprefix $(DIR_VID)/, video-manager.cc)
DIR_VID = $(DIR_SRC)/video
SRC_SWA = $(addprefix $(DIR_SWA)/, particle.cc)
DIR_SWA = $(DIR_SRC)/swarm
SRC_FFU = $(addprefix $(DIR_FFU)/, distance-middle.cc \
		gray-scale-histogram.cc covariance-zone.cc utilities.cc)
DIR_FFU = $(DIR_SRC)/ffunctions
DIR_SRC = src

.PHONY: all build debug check clean doc

all: ${BIN}

${BIN}:  build
	${CXX} ${CXXFLAGS} -o $@ ${OBJ} -L/usr/lib/x86_64-linux-gnu -lboost_program_options ${CXXLIBS}

build: $(OBJ)

error: CXXFLAGS += -Werror
error: ${BIN}

debug: CXXFLAGS += ${DEBUG}
debug: CXX = clang++
debug: clean ${BIN}

doc:
	doxygen Doxyfile

check: clean  ${BIN}
	./${BIN} tests/test

clean:
	${RM} ${BIN}
	${RM} ${OBJ}
	rm -rf doc/*
