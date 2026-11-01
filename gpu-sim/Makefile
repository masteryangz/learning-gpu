
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

TARGET = gpu-sim

SRCS = main.cpp Warp.cpp Scheduler.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
