CFLAGS := -Wall -Werror

SRCS := UVa_11450_TopDown.cc \
        UVa_11450_BottomUp.cc


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
