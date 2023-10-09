CC=g++
PATH_HEADER=~/HW18/
EXE=HW18
SRC=main.cpp User.cpp Message.cpp
OBJ=$(SRC:.cpp=.o)

#run: all
#	./$(EXE)

all: $(SRC) $(EXE) clean 
 
$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o : %.cpp
	$(CC) -c -lstd++fs -std=c++17 $< -o $@

install: test
	rm -rf ~/HW18/programm
	mkdir ~/HW18/programm ~/HW18/programm/data
	cp $(EXE) ~/HW18/programm
#	PATH=$(PATH):~/HW18/programm/$(EXE)
	rm HW18

test:
	if [ ! -f HW18 ]; then make all; fi


uninstall:
	rm -rf ~/HW18/programm

clean:
	rm -rf *.o *.a


