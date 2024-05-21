#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"
#include "AsciiArtDefines.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137, "none") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm",145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
    if (this != &form) {
        AForm::operator=(form);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::createShrubberyFile() {
    std::ofstream outfile((this->getTarget() + "_shrubbery").c_str());
    if (!outfile) {
        std::cerr << RED "Error: could not open and write to file" RESET << std::endl;
        return;
    }
    outfile << SHRUBBERY_ART;
    outfile.close();
}