OBJS 	= main.o Poluonumo.o Array.o Sy.o Md.o 
SOURCE	= main.cpp Poluonumo.cpp Array.cpp Sy.cpp Md.cpp
HEADER  = classes.h 
OUT  	= main
CXX		= g++
FLAGS   = -g3 -c 
# =======================================

all: $(OBJS)
	$(CXX) -g3 -o $(OUT) $(OBJS)


main.o: main.cpp $(HEADER)
	$(CXX) $(FLAGS) main.cpp

Poluonumo.o: Poluonumo.cpp classes.h
	$(CXX) $(FLAGS) Poluonumo.cpp
Array.o: Array.cpp classes.h
	$(CXX) $(FLAGS) Array.cpp

Sy.o: Sy.cpp classes.h
	$(CXX) $(FLAGS) Sy.cpp
Md.o: Md.cpp classes.h
	$(CXX) $(FLAGS) Md.cpp


clean:
	rm -f $(OBJS) $(OUT)
	
