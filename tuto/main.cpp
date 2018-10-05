#include <dlfcn.h>
#include <iostream>

void	dlerror_wrapper(void)
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
	void	*dl_handle;
	int		(*square_ptr)(int);

	if (!(dl_handle = dlopen(av[1], RTLD_LAZY | RTLD_LOCAL)))
		dlerror_wrapper();
	if (!(square_ptr = (int (*)(int))dlsym(dl_handle, "square")))
		dlerror_wrapper();
	std::cout << "@executable_path 3 * 3 = " << square_ptr(3) << std::endl;

	dlclose(dl_handle);
}
