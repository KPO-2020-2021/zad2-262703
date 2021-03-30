
TRGDIR=./
OBJ=./obj
TESTS=./tests
TBIN=./tests/bin
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

__start__: ${TRGDIR}/test_arytm_zesp
	${TRGDIR}/test_arytm_zesp  trudny

${TRGDIR}/test_arytm_zesp: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/BazaTestu.o ${OBJ}/Stat.o
	g++ -o ${TRGDIR}/test_arytm_zesp ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/Stat.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/LZespolona.hh inc/BazaTestu.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/LZespolona.o src/LZespolona.cpp

${OBJ}/BazaTestu.o: src/BazaTestu.cpp inc/BazaTestu.hh inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o src/BazaTestu.cpp

${OBJ}/WyrazenieZesp.o: src/WyrazenieZesp.cpp inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZesp.o src/WyrazenieZesp.cpp

${OBJ}/BazaTestu.o: src/BazaTestu.cpp inc/BazaTestu.hh inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o src/BazaTestu.cpp

${OBJ}/Stat.o: src/stat.cpp inc/stat.hh 
	g++ -c ${FLAGS} -o ${OBJ}/Stat.o src/stat.cpp

${TBIN}/test_1: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_1 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test1.cpp ${OBJ}/LZespolona.o

${TBIN}/test_2: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_2 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test2.cpp ${OBJ}/LZespolona.o


${TBIN}:
	mkdir ${TBIN}

test:  ${TBIN}/test_1 ${TBIN}/test_2
	${TBIN}/test_1 
	${TBIN}/test_2
run:
	${TRGDIR}/test_arytm_zesp latwy

clean:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/* ${TBIN}/*
