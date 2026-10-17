TARGET = calc

INCDIR = inc
SRCDIR = src
BUILDDIR = build

CXX = clang++
CXXFLAGS = -Iinc -O0 -g
LDFLAGS =

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

$(info $(SOURCES))
$(info $(OBJECTS))

.DEFAULT_GOAL = run

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILDDIR)/$(TARGET): $(OBJECTS)
	$(CXX) -o $(BUILDDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS)

run: $(BUILDDIR)/$(TARGET)
	$(BUILDDIR)/$(TARGET)

clean:
	rm $(BUILDDIR)/*
