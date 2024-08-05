#include <iostream>
#include <csignal>
#include <fstream>
#include "Colors.hpp"

int	replace(const char *fileName, const std::string s1, const std::string s2) {
	int	replacementCount = 0;
	if (access(fileName, F_OK) == -1 || access(fileName, R_OK) == -1) {
		perror("Error");
		exit(EXIT_FAILURE);
	}
	std::ifstream file(fileName);
	if (!file) {
		std::cerr << RED << "Error: cannot open the file: '"<< fileName << "'" << RESET << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string fileText;
	std::string line;
	while (std::getline(file, line))
		fileText += line + "\n";
	std::size_t pos = fileText.find(s1);
	if (pos == std::string::npos) {
		std::cout << YELLOW << "Word '" << s1 << "' not found in file: '" << fileName << "'" << RESET << std::endl;
		return 0;
	} else {
		while (1) {
			std::size_t pos = fileText.find(s1);
			if (pos == std::string::npos) {
				std::ofstream outFile((std::string(fileName) + ".replace").c_str());
				if (!outFile) {
					std::cerr << RED << "Error: cannot create file: '" << fileName << "'" << RESET << std::endl;
					exit(EXIT_FAILURE);
				}
				outFile << fileText;
				return replacementCount;
			}
			else {
				fileText = fileText.substr(0, pos) + s2 + fileText.substr(pos + s1.size());
				replacementCount++;
			}
		}

	}
	return replacementCount;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED "Error: incorrect number of arguments\n" LIGHT_CYAN "Usage: ./btc <filename>" RESET << std::endl;
		return 2;
	}
	if (access(argv[1], F_OK) == -1) {
		std::cerr << RED "Error: no such file or directory" RESET << std::endl;
		return 3;
	}
	if (access(argv[1], R_OK) == -1) {
		std::cerr << RED "Error: permission denied" RESET << std::endl;
		return 4;
	}
	std::ifstream file(argv[1]);
	if (!file) {
		std::cerr << RED << "Error: unable to open the file: '" << argv[1] << "'" RESET << std::endl;
		return 5;
	}
	std::string fileText;
	std::string line;
	while (std::getline(file, line)) {
		fileText += line;
	}
	return 0;
}