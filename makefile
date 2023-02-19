CXX = g++
CXXFLAGS = -Wall -std=c++11

all: main.o linearHash.o Vector.o linkedlist.o postallinkedlist.o
	$(CXX) $(CXXFLAGS) -o main main.o linearHash.o Vector.o linkedlist.o postallinkedlist.o

linearHash.o: linearHash.cpp 
	$(CXX) $(CXXFLAGS) -c linearHash.cpp

Vector.o: Vector.cpp 
	$(CXX) $(CXXFLAGS) -c Vector.cpp

linkedlist.o: linkedlist.cpp 
	$(CXX) $(CXXFLAGS) -c linkedlist.cpp

postallinkedlist.o: postallinkedlist.cpp 
	$(CXX) $(CXXFLAGS) -c postallinkedlist.cpp

clean:
	rm -f *.o all
