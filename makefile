CXX = g++
CXXFLAGS = -Wall -std=c++11

all: mvote.o linearHash.o Vector.o linkedlist.o postallinkedlist.o
	$(CXX) $(CXXFLAGS) -o mvote mvote.o linearHash.o Vector.o linkedlist.o postallinkedlist.o

mvote.o: mvote.cpp
	$(CXX) $(CXXFLAGS) -c mvote.cpp

linearHash.o: linearHash.cpp 
	$(CXX) $(CXXFLAGS) -c linearHash.cpp

Vector.o: Vector.cpp 
	$(CXX) $(CXXFLAGS) -c Vector.cpp

linkedlist.o: linkedlist.cpp 
	$(CXX) $(CXXFLAGS) -c linkedlist.cpp

postallinkedlist.o: postallinkedlist.cpp 
	$(CXX) $(CXXFLAGS) -c postallinkedlist.cpp

clean:
	rm -f *.o mvote
