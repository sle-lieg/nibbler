EXEC	= nibbler
SFML	= libmysfml.dylib
CC		= clang++
FLAGS	= -std=c++14 -Wall -Wextra -Werror

############ DIRECTORIES ############
SOURCES_D	= sources/
CLASSES_D	= classes/
HEADERS_D	= headers/
INCLUDES_D	= includes/
OBJECTS_D	= objects/
DEP_D		= dependencies/

############### PATHS ###############
MY_OPENGL_PATH	= dylibs/OpenGL/
MY_SFML_PATH	= dylibs/SFML/
MY_SDL_PATH		= dylibs/SDL/

INCLUDES	= -I$(INCLUDES_D) -I$(HEADERS_D) -I$(MY_SFML_PATH)headers

############## SOURCES ##############
SOURCES_F	= main.cpp
CLASSES_F	= Game.cpp LibHandler.cpp Scene.cpp

SOURCES	= $(addprefix $(SOURCES_D), $(SOURCES_F))
CLASSES	= $(addprefix $(CLASSES_D), $(CLASSES_F))

############## OBJECTS ##############
OBJECTS	= $(SOURCES:$(SOURCES_D)%.cpp=$(OBJECTS_D)%.o)
OBJECTS	:= $(OBJECTS) $(CLASSES:$(CLASSES_D)%.cpp=$(OBJECTS_D)%.o)

DEPENDENCIES = $(OBJECTS:$(OBJECTS_D)%.o=$(DEP_D)%.d)

all: createDir $(SFML) $(EXEC)

createDir:
	@test -d $(OBJECTS_D) || mkdir $(OBJECTS_D)
	@test -d $(DEP_D) || mkdir $(DEP_D)

-include $(DEPENDENCIES)

$(SFML):
	make -C $(MY_SFML_PATH)

$(EXEC): $(OBJECTS)
	$(CC) $^ -o $@

$(OBJECTS_D)%.o: $(SOURCES_D)%.cpp
	$(CC) $(FLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $@ $(INCLUDES)

$(OBJECTS_D)%.o: $(CLASSES_D)%.cpp
	$(CC) $(FLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $@ $(INCLUDES)

clean:
	make clean -C $(MY_SFML_PATH)
	rm -f $(OBJECTS)
	rm -f $(DEPENDENCIES)

fclean: clean
	make fclean -C $(MY_SFML_PATH)
	rm -f $(EXEC)

re: fclean clean all
