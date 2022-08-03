NAME	:=	a.out
CXX		:=	c++
RM		:=	rm -f
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98

DEBUG_FLAGS	:=	-g -fsanitize=address -fsanitize=undefined
# For M1MacBook, run the command below.
# export MallocNanoZone=0
# make debug
# unset MallocNanoZone
# env | grep Malloc
NO_BUILTIN_FLAGS	:=	-fno-builtin

SRCS	:=	tests.cpp Account.cpp
OBJS	:=	$(SRCS:.cpp=.o)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# suffix rule
%.o		: %.cpp
	${CXX} ${CXXFLAGS} -c $<

all		: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

test	:
	./$(NAME) | sed -E 's/[0-9]{8}_[0-9]{6}/19920104_091532/g' | diff -u - 19920104_091532.log # destructorだけ出てくる

download:
	curl -O https://projects.intra.42.fr/uploads/document/document/8753/19920104_091532.log

nm		: fclean $(OBJS)
	$(CXX) $(CXXFLAGS) $(NO_BUILTIN_FLAGS) $(OBJS) -o $(NAME)
	nm -u $(NAME)

debug	: fclean $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(OBJS) -o $(NAME)

leak	:
	leaks -quiet -atExit -- ./$(NAME)

.PHONY	: all clean fclean re nm debug leak
