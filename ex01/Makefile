# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 11:31:39 by fcoullou          #+#    #+#              #
#    Updated: 2024/10/24 09:12:55 by fcoullou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##	PROGS NAMES	################################################################
NAME			= phonebook

################################################################################
##	FILES		################################################################
SRC				= main.cpp PhoneBook.class.cpp Contact.class.cpp
#------------------------------------------------------------------------------#
OBJ				= $(SRC:.cpp=.o)
#------------------------------------------------------------------------------#
OUTPUT_LEAKS 	= valgrind-out.txt

################################################################################
##	COMPILER	################################################################
##	-Wall -Werror -Wextra : Active tous les avertissements (-Wall), traite les avertissements comme des erreurs (-Werror), et active des avertissements supplémentaires (-Wextra).
##	-g3 : Génère des informations de débogage détaillées dans le fichier exécutable.
##	-ftrapv : Génère des erreurs d'exécution en cas de débordement arithmétique.
CFLAGS			= -Wall -Werror -Wextra -I./include -g3 -ftrapv
# -fsanitize=undefined -fsanitize=address

##  -MMD : Génère des fichiers .d avec des dépendances pour chaque fichier source, utile pour la recompilation conditionnelle avec make.
##  -c : Compile les fichiers source sans les lier, générant des fichiers objet (.o).
CPPFLAGS		= -std=c++98

##  -lft : Lie votre programme avec la bibliothèque libft.
##  -lreadline : Lie votre programme avec la bibliothèque readline.
LFLAGS 			= -L./libft_v2 -lft -lreadline -lm
# -fsanitize=undefined -static-libsan -fsanitize=address

#------------------------------------------------------------------------------#
AR				= ar
CC				= g++
RM				= rm -f
CD				= cd
DIR_DUP			= mkdir -p $(@D)

################################################################################
##	+++++		################################################################
GREEN=\033[0;32m
RED=\033[0;31m
RESET=\033[0m
CLEAR_EOL=\033[K
CLEAR_EOL_FROM_CURSOR=; tput el; printf 
#------------------------------------------------------------------------------#
VALCHECK=--leak-check=full
VALSHOW=--show-leak-kinds=all
VALFD=--track-fds=yes
VALIGNORE=--suppressions=valgrind_readline_leaks_ignore.txt
VALCHILD=--trace-children=yes

################################################################################
##	RULES		################################################################
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)[CREATED]$(RESET) : $(NAME)" $(CLEAR_EOL_FROM_CURSOR) "\n"

%.o: %.cpp
	@printf "$(GREEN)[COMPILATION]$(RESET) : $<$(CLEAR_EOL)\r"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< 

#------------------------------------------------------------------------------#
clean:
	@deleted=0; \
	for file in $(OBJ); do \
        if [ -f $$file ]; then \
            printf "$(RED)[DELETE FILES]$(RESET) : $(CLEAR_EOL)$$file "; \
            sleep 0.01; \
            printf "\r"; \
            $(RM) $$file; \
            deleted=1; \
        fi; \
    done; \
    if [ $$deleted -eq 1 ]; then \
        printf "$(CLEAR_EOL)$(RED)[ALL FILES DELETED]$(RESET)\n"; \
    else \
        printf "$(CLEAR_EOL)make: *** All files already deleted ***$(RESET)\n"; \
	fi
	
#------------------------------------------------------------------------------#
fclean: clean
	@if [ -f $(NAME) ]; then \
        $(RM) -f $(NAME); \
    fi
	
#------------------------------------------------------------------------------#
re: fclean all

#------------------------------------------------------------------------------#
test: all
	./$(NAME)
	
#------------------------------------------------------------------------------#
leaks: all
	valgrind $(VALIGNORE) $(VALSHOW) $(VALCHECK) ./$(NAME)
	@cat valgrind-out.txt
	
#------------------------------------------------------------------------------#
valgrind : all
	valgrind $(VALIGNORE) $(VALSHOW) $(VALCHECK) $(VALCHILD) $(VALFD) ./${NAME}

#------------------------------------------------------------------------------#
.PHONY: all bonus clean fclean re test leaks  

#------------------------------------------------------------------------------#
