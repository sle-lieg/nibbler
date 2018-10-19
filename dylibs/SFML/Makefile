DYLIB	= libmysfml.dylib
CC		= clang++
FLAGS	= -std=c++14 -Wall -Wextra -Werror -g

############ DIRECTORIES ############
CLASSES_D	= classes/
HEADERS_D	= headers/
OBJECTS_D	= objects/
DEP_D		= dependencies/
INCLUDES_D	= ../includes/

LIBS_SFML	= -lsfml-window.2.4.2 -lsfml-graphics.2.4.2 -lsfml-system.2.4.2

############## MY_SFML ##############
MYSFML_F	= MySFML.cpp
# MYSFML	= $(addprefix $(CLASSES_D), $(MYSFML_F))

############## OBJECTS ##############
# OBJECTS	= $(MYSFML_F:%.cpp=$(OBJECTS_D)%.o)
OBJECTS	= $(MYSFML_F:%.cpp=%.o)

DEPENDENCIES = $(OBJECTS:%.o=$(DEP_D)%.d)

all: createDir $(DYLIB)

createDir:
	@test -d $(OBJECTS_D) || mkdir $(OBJECTS_D)
	@test -d $(DEP_D) || mkdir $(DEP_D)

-include $(DEPENDENCIES)

$(DYLIB): $(OBJECTS)
	$(CC) -shared -fPIC $(addprefix $(OBJECTS_D), $^) $(LIBS_SFML) -o $@

%.o: $(CLASSES_D)%.cpp
	$(CC) $(FLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $(OBJECTS_D)$@ -I$(INCLUDES_D) -I$(HEADERS_D)

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDENCIES)

fclean: clean
	rm -f $(DYLIB)

re: fclean clean
	all
