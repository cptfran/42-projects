#include "colors.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

int	replace(const char *fileName, const std::string s1, const std::string s2) {
	int	replacementCount = 0;
	if (access(fileName, F_OK) == -1 || access(fileName, R_OK) == -1) {
		perror("Error");
		return 0;
	}
	std::ifstream file(fileName);
	if (!file) {
		std::cerr << RED << "Error: cannot open the file: '"<< fileName << "'" << RESET << std::endl;
		return 1;
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
					return 0;
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
	if (argc != 4) {
		std::cerr << BLUE << "Usage: '" << argv[0] << " 'file name' 's1' 's2'" << RESET << std::endl;
		return 1; 
	}
	std::cerr << RED;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (int replacementCount = replace(argv[1], s1, s2))
		std::cout << LIGHT_GREEN << "Replaced " << replacementCount << " occurrences" << RESET << std::endl;
	return 0;
}