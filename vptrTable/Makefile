DEST= vptrTable
OBJS= vptrTable.o
#CPPFLAGS  = -Wall
LDFLAGS=
LIBS=
CC= gcc
CXX= g++
DEBUG_FLAG = -O0 -g3 -Wall -c -fmessage-length=0
RELEASE_FLAG = -O3 -Wall -c -fmessage-length=0
CFLAGS = $(DEBUG_FLAG) -DDEBUG
ifeq ($(MAKECMDGOALS),debug)
	CFLAGS := $(DEBUG_FLAG) -DDEBUG
endif
ifeq ($(MAKECMDGOALS),release)
	 CFLAGS := $(RELEASE_FLAG)
endif
CXXFLAGS=${CFLAGS}
debug:${DEST}
	mkdir -p _debug
	@echo "debug done"
release:${DEST}
	mkdir -p _release
	@echo "release done"
${DEST}:${OBJS}
	$(CXX)  -o $@ $^ ${LIB}
.c.o:
	$(CXX)  $(CFLAGS) -c $<
.PHONY : clean 
clean : 
	rm  ${OBJS} ${DEST} -rf  _debug _release
submit: 
	cp ./${DEST} ~/bin/