# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 14:29:28 by sniemela          #+#    #+#              #
#    Updated: 2025/08/25 11:40:15 by sniemela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
CPPFLAGS = -Wall -Werror -Wextra
CPP = c++
SOURCES = src/main.cpp \
			src/PmergeMe.cpp
		

OBJDIR = obj
OBJS = $(SOURCES:src/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	mkdir -p $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re