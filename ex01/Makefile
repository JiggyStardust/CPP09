# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 14:29:28 by sniemela          #+#    #+#              #
#    Updated: 2025/08/19 15:01:29 by sniemela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN
CPPFLAGS = -Wall -Werror -Wextra -std=c++11
CPP = c++
SOURCES = src/main.cpp \
			src/RPN.cpp
		

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