CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = bb7k
OBJECTS = role.o gameControler.o property.o gameMap.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
