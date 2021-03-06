SRC     = ./src
IDIR    = ./include
TEMPDIR = temp
CXX     = g++
CFLAGS  = -I$(IDIR) -std=c++17 -Wall
LDFLAGS = -I$(IDIR) -std=c++17
FILES   = main.cpp Storage/Vector.cpp Storage/VectorException.cpp Monopoly/MonopolyException.cpp Monopoly/Game.cpp Monopoly/Printer/Printer.cpp Monopoly/Randomizer/OneDice.cpp Monopoly/Randomizer/PreDefined.cpp Monopoly/Fields/Field.cpp Monopoly/Fields/Property.cpp Monopoly/Fields/Service.cpp Monopoly/Fields/Luck.cpp Monopoly/Fields/Chance.cpp Monopoly/Player/Player.cpp Monopoly/Player/AI/AI.cpp Monopoly/Player/AI/Greedy.cpp Monopoly/Player/AI/Careful.cpp Monopoly/Player/AI/Tactician.cpp
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
