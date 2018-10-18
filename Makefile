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
DYLIBS_D	= dylibs/

############### PATHS ###############
MY_OPENGL_PATH	= dylibs/OpenGL/
MY_SFML_PATH	= dylibs/SFML/
MY_SDL_PATH		= dylibs/SDL/

INCLUDES	= -I$(INCLUDES_D) -I$(HEADERS_D) -I$(DYLIBS_D)$(INCLUDES_D)

############## SOURCES ##############
SOURCES_F	= main.cpp
CLASSES_F	= Game.cpp

# SOURCES	= $(addprefix $(SOURCES_D), $(SOURCES_F))
# CLASSES	= $(addprefix $(CLASSES_D), $(CLASSES_F))

############## OBJECTS ##############
# OBJECTS	= $(SOURCES:$(SOURCES_D)%.cpp=$(OBJECTS_D)%.o)
# OBJECTS	:= $(OBJECTS) $(CLASSES:$(CLASSES_D)%.cpp=$(OBJECTS_D)%.o)
OBJECTS	= $(SOURCES_F:%.cpp=%.o)
OBJECTS	:= $(OBJECTS) $(CLASSES_F:%.cpp=%.o)

DEPENDENCIES = $(OBJECTS:%.o=$(DEP_D)%.d)
# DEPENDENCIES = $(OBJECTS:$(OBJECTS_D)%.o=$(DEP_D)%.d)

all: createDir $(SFML) $(EXEC)

createDir:
	@test -d $(OBJECTS_D) || mkdir $(OBJECTS_D)
	@test -d $(DEP_D) || mkdir $(DEP_D)

-include $(DEPENDENCIES)

$(SFML):
	make -C $(MY_SFML_PATH)

$(EXEC): $(OBJECTS)
	$(CC) $(addprefix $(OBJECTS_D), $^) -o $@

%.o: $(SOURCES_D)%.cpp
	$(CC) $(FLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $(OBJECTS_D)$@ $(INCLUDES)

%.o: $(CLASSES_D)%.cpp
	$(CC) $(FLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $(OBJECTS_D)$@ $(INCLUDES)

clean:
	make clean -C $(MY_SFML_PATH)
	rm -f $(OBJECTS)
	rm -f $(DEPENDENCIES)

fclean: clean
	make fclean -C $(MY_SFML_PATH)
	rm -f $(EXEC)

re: fclean clean all
