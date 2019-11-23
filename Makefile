CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla -g
EXEC = biquadris
OBJECTS = main.o interface.o 

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}