CFLAGS := -Wall -Werror

SRCS := UVa_11450.cc

OBJS := ${SRCS:cc=o}
PROGS := ${SRCS:.cc=}

.PHONY: all
	all: ${PROGS}

${PROGS} : % : %.o
	    ${CC} $< -o $@

clean:
	    rm -f ${PROGS} ${OBJS}

%.o: %.cc
	    ${CC} ${CFLAGS} -c $<
