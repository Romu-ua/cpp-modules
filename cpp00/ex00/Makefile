CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror
TARGET		= megaphone

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)
INCLUDES	=
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