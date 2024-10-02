# Compiler
CXX = g++

# Flags
CXXFLAGS = -g -Wall -Wextra -Iinclude -std=c++17  # Include das 'include'-Verzeichnis für Header-Dateien

# Source files
SRC = tests.cpp string.cpp  # Füge hier deine Implementierungsdatei hinzu

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
EXEC = test_program  # Name für das Test-Executable

# Default target
all: $(EXEC)

# Regel zur Erstellung des Executables aus den Objektdateien
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Regel zum Kompilieren von Quellcodedateien in Objektdateien
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regel zum Ausführen mit Valgrind
valgrind: $(EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(EXEC)

# Aufräumen von Objektdateien und Executable
clean:
	rm -f $(OBJ) $(EXEC)

# Phony targets
.PHONY: all clean valgrind
