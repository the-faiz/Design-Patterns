CXX = g++
CXXFLAGS = -std=c++11 -Wall
OBJFILES = Facets.o Person.o PersonBuilder.o PersonAddressBuilder.o PersonJobBuilder.o
TARGET = BuilderFacets

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES)

Facets.o: Facets.cpp
	$(CXX) $(CXXFLAGS) -c Facets.cpp -o Facets.o

Person.o: Person.cpp
	$(CXX) $(CXXFLAGS) -c Person.cpp -o Person.o

PersonBuilder.o: PersonBuilder.cpp
	$(CXX) $(CXXFLAGS) -c PersonBuilder.cpp -o PersonBuilder.o

PersonAddressBuilder.o: PersonAddressBuilder.cpp
	$(CXX) $(CXXFLAGS) -c PersonAddressBuilder.cpp -o PersonAddressBuilder.o

PersonJobBuilder.o: PersonJobBuilder.cpp
	$(CXX) $(CXXFLAGS) -c PersonJobBuilder.cpp -o PersonJobBuilder.o

clean:
	rm -f $(OBJFILES) $(TARGET)