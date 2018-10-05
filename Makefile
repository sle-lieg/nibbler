EXEC	= nibbler
CC		= clang++
FLAGS	= -std=c++14 -Wall -Wextra -Werror

############ DIRECTORIES ############
SOURCES_D	= sources/
CLASSES_D	= classes/
HEADERS_D	= headers/
INCLUDES_D	= includes/
OBJECTS_D	= objects/
DEP_D		= dependencies/

############## SOURCES ##############
SOURCES_F	= main.cpp
CLASSES_F	= Game.cpp

SOURCES	= $(addprefix $(SOURCES_D), $(SOURCES_F))
CLASSES	= $(addprefix $(CLASSES_D), $(CLASSES_F))

############## OBJECTS ##############
OBJECTS	= $(SOURCES:$(SOURCES_D)%.cpp=$(OBJECTS_D)%.o)
OBJECTS	:= $(OBJECTS) $(CLASSES:$(CLASSES_D)%.cpp=$(OBJECTS_D)%.o)

DEPENDENCIES = $(OBJECTS:$(OBJECTS_D)%.o=$(DEP_D)%.d)


all: createDir $(EXEC)

createDir:
	@test -d $(OBJECTS_D) || mkdir $(OBJECTS_D)

-include $(DEPENDENCIES)

$(EXEC): $(OBJECTS)
	$(CC) $^ -o $@

$(OBJECTS_D)%.o: $(SOURCES_D)%.cpp
	$(CC) $(FLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $@ -I$(INCLUDES_D) -I$(HEADERS_D)

$(OBJECTS_D)%.o: $(CLASSES_D)%.cpp
	$(CC) $(FLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $@ -I$(INCLUDES_D) -I$(HEADERS_D)

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDENCIES)

fclean: clean
	rm -f $(EXEC)

re: fclean clean
	all
