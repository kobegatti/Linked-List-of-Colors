TARGET   = selectionSort
CC       = g++
CCFLAGS  = -std=c++2a -pedantic -Wall -Werror -g
LDFLAGS  = -lm
SOURCES  = $(wildcard *.cpp)
INCLUDES = $(wildcard *.h)
OBJECTS  = $(SOURCES:.cpp=.o)

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $(LDFLAGS) $(OBJECTS)

$(OBJECTS):$(SOURCES) $(INCLUDES)
	$(CC) -c $(CCFLAGS) $(SOURCES)

clean:
	rm -f $(TARGET) $(OBJECTS)
