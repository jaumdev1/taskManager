TARGET = grello

RM = rm
MD = mkdir

CXX = g++

CXXFLAGS = -std=c++11 -Wall

LIBS = -lncurses -lpthread

SRCDIR = src
OBJDIR = obj

SRCS = $(wildcard $(SRCDIR)/*.cpp)

OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR):
	$(MD) -p $(OBJDIR)

clean:
	$(RM) -rf $(OBJDIR) $(TARGET)

format:
	clang-format -i $(SRCDIR)/*

.PHONY: clean format
