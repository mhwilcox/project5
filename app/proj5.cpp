//proj5.cpp

#include <iostream>
#include <sstream>
#include <string>
#include "proj5.hpp"

bool isMinHeap(std::string s)
{
	bool check;
	int totalNodes = s.length();
	int height = 0;	// count from the root
	int leaves = totalNodes / 2;	// 
	
	// tree has 2 ^ n nodes max at each height
	// if a string only has one char then its a minHeap
	if ( s.length() < 2 ) {
		return true;
	}
	// increment through string char by char starting at s[1]
	// # of nodes = height * 2 with root being h = 0
	for ( int c = 0; c < leaves; c++) {
		// start with a temp root
		// pattern is s[char] = ( y * 2 ) + (1 or 2) for nodes below temp root
		// every 2 nodes increment y (y++) and temp root (tRoot++)
		int y = height * 2;
		if ( s[c] <= s[ y + 1] ) {
			check = true;
		}
		else {
			check = false;
			break;
		}
		if( s[c] <= s[ y + 2] ) {
			check = true;
		}
		else {
			check = false;
			break;
		}
		height++;
	}	// end for loop

	return check;
}


void doSomeSort(std::vector<std::string> & vec)
{
	int unchecked = vec.size()-1;
	std::string max = vec[unchecked];
	std::string temp;
	std::cout<<"in vector: ";
	
	while ( unchecked > 1) {
		if ( max < vec[0] ) {
			max = vec[0];
			temp = vec[unchecked];
			vec[unchecked] = max;
			vec[0] = temp;
			--unchecked;
		}
		else {
			unchecked--;
			max = vec[unchecked];
		}
	} //	end for loop

std::cout<<"\nsolution: ";
for( int k = 0; k<vec.size(); k++) {
	std::cout<<vec[k]<<", ";
}

}


std::vector<std::string> findHeaps(std::istream & in)
{
	std::vector<std::string> foo;

	std::string ss>>in;

	std::cout<<"ss: "<<ss<<std::endl;


	return foo;
}
