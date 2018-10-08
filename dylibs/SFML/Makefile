DYLIB	= libmysfml.dylib
CC		= clang++
FLAGS	= -std=c++14 -Wall -Wextra -Werror

############ DIRECTORIES ############
CLASSES_D	= classes/
HEADERS_D	= headers/
OBJECTS_D	= objects/
DEP_D		= dependencies/

LIBS_SFML	= /Users/sle-lieg/.brew/Cellar/sfml/2.4.2_1/lib/libsfml-window.2.4.2.dylib 
LIBS_SFML	:= $(LIBS_SFML) /Users/sle-lieg/.brew/Cellar/sfml/2.4.2_1/lib/libsfml-graphics.2.4.2.dylib
LIBS_SFML	:= $(LIBS_SFML) /Users/sle-lieg/.brew/Cellar/sfml/2.4.2_1/lib/libsfml-system.2.4.2.dylib

############## SOURCES ##############
CLASSES_F	= MySFML.cpp

CLASSES	= $(addprefix $(CLASSES_D), $(CLASSES_F))

############## OBJECTS ##############
OBJECTS	= $(CLASSES:$(CLASSES_D)%.cpp=$(OBJECTS_D)%.o)

DEPENDENCIES = $(OBJECTS:$(OBJECTS_D)%.o=$(DEP_D)%.d)

all: createDir $(DYLIB)

createDir:
	@test -d $(OBJECTS_D) || mkdir $(OBJECTS_D)
	@test -d $(DEP_D) || mkdir $(DEP_D)

-include $(DEPENDENCIES)

$(DYLIB): $(OBJECTS)
	$(CC) -shared -fPIC $^ $(LIBS_SFML) -o $@

$(OBJECTS_D)%.o: $(CLASSES_D)%.cpp
	$(CC) $(FLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $@ -I$(HEADERS_D)

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDENCIES)

fclean: clean
	rm -f $(DYLIB)

re: fclean clean
	all
