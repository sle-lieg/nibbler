#include "Player.hpp"
#include <dlfcn.h>

void	dlerror_wrapper(void)
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
	void*	dl_handle;

	if (!(dl_handle = dlopen(av[1], RTLD_LAZY | RTLD_LOCAL)))
		dlerror_wrapper();

	creator *playerCreator;

	playerCreator = (creator *) dlsym(dl_handle, "createPlayer");
	if (!playerCreator)
		dlerror_wrapper();

	Player	*player = playerCreator("Clad");

	player->announces();
	player->markPoint();
	player->announces();

	deleter *playerDestrutor;
	playerDestrutor = (deleter*)dlsym(dl_handle, "deletePlayer");
	if (!playerDestrutor)
		dlerror_wrapper();

	playerDestrutor(player);

	dlclose(dl_handle);
	return 0;
}
