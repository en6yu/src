CPPFLAGS  = -Wall
LDFLAGS=
LIBS=
CPPFLAGS=-DNDEBUG
CFLAGS= -O2 -g
CXXFLAGS=${CFLAGS}
CC= gcc
CXX= g++
SUBDIRS= base const  
ALL:
	@for n in $(SUBDIRS); do make -C $$n ; done
clean:
	@for n in $(SUBDIRS); do $(MAKE) -C $$n clean; done
submit:
	@for n in $(SUBDIRS);do $(MAKE) -C $$n submit; done
debug:
	@for n in $(SUBDIRS);do $(MAKE) -C $$n debug; done
release:
	@for n in $(SUBDIRS);do $(MAKE) -C $$n release; done
