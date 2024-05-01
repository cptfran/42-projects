#include <iostream>

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int arg = 1; arg < argc; arg++) {
			for (int i = 0; argv[arg][i]; i++) {
				argv[arg][i] = static_cast<char>(std::toupper(static_cast<unsigned char>(argv[arg][i])));
			}
			std::cout << argv[arg];
		}
		std::cout << std::endl;
	}
	return 0;
}

