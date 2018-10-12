DYLIB	= libmysfml.dylib
CC		= clang++
FLAGS	= -std=c++14 -Wall -Wextra -Werror

############ DIRECTORIES ############
CLASSES_D	= classes/
HEADERS_D	= headers/
OBJECTS_D	= objects/
MYCONTAINERS_D	= ../MyContainers/
DEP_D		= dependencies/
INCLUDES_D	= ../includes/

LIBS_SFML	= /Users/sle-lieg/.brew/Cellar/sfml/2.4.2_1/lib/libsfml-window.2.4.2.dylib
LIBS_SFML	:= $(LIBS_SFML) /Users/sle-lieg/.brew/Cellar/sfml/2.4.2_1/lib/libsfml-graphics.2.4.2.dylib
LIBS_SFML	:= $(LIBS_SFML) /Users/sle-lieg/.brew/Cellar/sfml/2.4.2_1/lib/libsfml-system.2.4.2.dylib

############## MY_SFML ##############
MYSFML_F	= MySFML.cpp
MYSFML	= $(addprefix $(CLASSES_D), $(MYSFML_F))

########### MYCONTAINERS ###########
MYCONTAINERS_F	= MyWindow.cpp MyGameGrid.cpp MyContainers.cpp MySnake.cpp
MYCONTAINERS	= $(addprefix $(MYCONTAINERS_D)$(CLASSES_D), $(MYCONTAINERS_F))

############## OBJECTS ##############
# OBJECTS	= $(MYSFML:$(CLASSES_D)%.cpp=$(OBJECTS_D)%.o)
OBJECTS	= $(MYSFML_F:%.cpp=$(OBJECTS_D)%.o)
OBJECTS	:= $(OBJECTS) $(MYCONTAINERS_F:%.cpp=$(OBJECTS_D)%.o)

DEPENDENCIES = $(OBJECTS:$(OBJECTS_D)%.o=$(DEP_D)%.d)

all: createDir $(DYLIB)

createDir:
	@test -d $(OBJECTS_D) || mkdir $(OBJECTS_D)
	@test -d $(DEP_D) || mkdir $(DEP_D)

-include $(DEPENDENCIES)

$(DYLIB): $(OBJECTS)
	$(CC) -shared -fPIC $^ $(LIBS_SFML) -o $@

$(OBJECTS_D)%.o: $(CLASSES_D)%.cpp
	$(CC) $(FLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $@ -I$(INCLUDES_D)

$(OBJECTS_D)%.o: $(MYCONTAINERS_D)$(CLASSES_D)%.cpp
	$(CC) $(FLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $@ -I$(INCLUDES_D)

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDENCIES)

fclean: clean
	rm -f $(DYLIB)

re: fclean clean
	all
