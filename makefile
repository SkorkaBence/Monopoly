SRC     = ./src
IDIR    = ./include
TEMPDIR = temp
CXX     = g++
CFLAGS  = -I$(IDIR) -std=c++11
LDFLAGS = -I$(IDIR) -std=c++11
FILES   = main.cpp Monopoly/MonopolyException.cpp Monopoly/Game.cpp Monopoly/Printer/Printer.cpp Monopoly/Randomizer/OneDice.cpp
TARGET  = run
SOURCES = $(patsubst %,$(SRC)/%,$(FILES))
OBJECTS = $(patsubst %.cpp,$(TEMPDIR)/%.o,$(FILES))
DEPS    = $(patsubst %.cpp,$(TEMPDIR)/%.d,$(FILES))

$(TEMPDIR)/%.o: $(SRC)/%.cpp
	$(CXX) $(CFLAGS) -c $< -O3 -o $@

#$(TEMPDIR)/%.d: $(SRC)/%.cpp
#	$(CXX) $(CFLAGS) -MD -MP $< -MF $@

-include $(DEPS)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -O3 -o $(TARGET)
