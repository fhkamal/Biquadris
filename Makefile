CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla -g
EXEC = biquadris
OBJECTS = main.o interface.o player.o textdisplay.o cell.o board.o level.o levels/levelzero.o levels/levelone.o levels/leveltwo.o levels/levelthree.o levels/levelfour.o block/block.o block/iblock.o block/jblock.o block/sblock.o block/oblock.o block/lblock.o block/tblock.o block/zblock.o block/starblock.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

