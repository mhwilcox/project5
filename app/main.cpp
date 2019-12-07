//proj5.cpp
/*	Programmer: Morgan Wilcox
	Class: ICS46 - Data Structures - Fall 2019
*/

#include <iostream>
#include <sstream>
#include <string>
#include "proj5.hpp"


int main()
{

	std::string someWords = "ant cat abc ing\nnot for now you rot\n";
		// min: ant, abc, ing, not, for, now, rot
		// min.size == 7

	std::istringstream stream( someWords );

	std::vector<std::string> vec = findHeaps(stream);

	std::cout<<"solution: ";
	for ( int i = 0; i < vec.size(); i++) {
		std::cout<<vec[i]<<", ";
	}

	std::cout<<"\nend"<<std::endl;

    return 0;
}

