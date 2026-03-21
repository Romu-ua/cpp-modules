CXX			= g++
CXXFLAGS	= -std=c++98 -pedantic-errors -Wall -Wextra -Werror
TARGET		= zombie

SRCS		= src/main.cpp src/Zombie.cpp src/newZombie.cpp src/randomChump.cpp
OBJS		= $(SRCS:.cpp=.o)
INCLUDES	= -I.
LIBS		=

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re