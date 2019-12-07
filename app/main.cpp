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

	std::cout<<"\nend 3 char test."<<std::endl;
	std::cout<<"\n*******\n@@@@@@@\n********\n"<<std::endl;

	std::string words;
	std::string in;

std::string alphanum="abcdefghijklmnopqrstuvwxyz";
std::string mary = "Supercalifragilisticexpialidocious";

std::cout<<"supercalifragilisticexpialidocious.length(): "<<mary.length()<<std::endl;

	//words += mary+" ";

	std::vector<std::string> testSort;
int x = 0;
	while ( x < 161 ) {
		for( int s = 0; s < 12; s++) {
			words+= alphanum[rand() % (alphanum.length())];
			in += alphanum[rand() % (alphanum.length())] ;
			words+= mary[rand() % (mary.length())];
			in+=mary[rand() % (mary.length())];
		}
		in+=" ";
		testSort.push_back(words);
		words="";
		x++;
	}

	std::istringstream flow(in);

	std::vector<std::string> longTest = findHeaps(flow);
	doSomeSort(testSort);
	x=0;
	std::cout<<"\n***\nprinting testSort: "<<std::endl;
	for( int a = 0; a < 26; a++) {
		std::cout<< alphanum[a]<<": "<<std::endl;
		while (x<161) {
			if (testSort[x].at(0) == (alphanum[a]) ) {
				std::cout<<"\t"<<testSort[x]<<std::endl;
				x++;
			}
			else {
				break;
			}
		}
	}
	std::cout<<"x = "<<x<<std::endl;
std::cout<<"\nend testSort\n"<<std::endl;

	std::cout<<"longTest sort solution: ";
	if( longTest.size() == 0) {
		std::cout<<"NO minHeaps"<<std::endl;
	}
	else {
		for( int f = 0; f<longTest.size(); f++) {
			std::cout<<longTest[f]<<", ";
		}
	}
	std::cout<<"\nend longTest."<<std::endl;

    return 0;
}

