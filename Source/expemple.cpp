#include "UnicodeStream/UnicodeStream.h"


int main () {

    dm::cxxout << "Hello World!" << std::endl << "Привет Мир!" << std::endl << "世界您好" << std::endl << "Γεια σου κόσμε";
    std::string a;
    dm::cxxin >> a;
    dm::cxxout << a; 
}