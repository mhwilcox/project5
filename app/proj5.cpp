//proj5.cpp
/*	Programmer: Morgan Wilcox
	Class: ICS46 - Data Structures - Fall 2019
*/

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
		if ( s[c] <= s[ y + 1] && isalpha(s[y + 1]) ) {
			check = true;
		}
		else if ( !isalpha(s[y+1]) ) {
			break;
		}
		else {
			check = false;
			break;
		}
		if( s[c] <= s[ y + 2] && isalpha(s[y + 2]) ) {
			check = true;
		}
		else if ( !isalpha(s[y + 2]) ) {
			break;
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
	int nmax;
	
	// while unchecked values is greater than 1 do loop
	while ( unchecked > 0) {
		for ( int i = 0; i <= unchecked; i++) {
			// if max < vec[i] then put max as vec[i] and nmax is the address in the vec where the new max came from
			// 	and temp is the old max
			
			if ( max < vec[i] ) {
				max = vec[i];
				temp = vec[unchecked];
				nmax = i;
			}
			// if the max is already at the end of the vector, decrement unchecked and change max to the next value
			else if (max == vec[i]) {
				unchecked--;
				max = vec[unchecked];
				//break;
			}
			
		} // end for loop
		// assign max to the farthest right address that hasn't been given a max value yet
		//	decrement unchecked and assign max to the new farthest right value
		if ( max != vec[unchecked]) {
			vec[unchecked] = max;
			vec[nmax] = temp;
			unchecked--;
			max = vec[unchecked];
		}
	} // end while loop

/*
std::cout<<"\n\nsolution: ";
for( int k = 0; k<vec.size(); k++) {
	std::cout<<vec[k]<<", ";
}
*/
}


std::vector<std::string> findHeaps(std::istream & in)
{
	std::vector<std::string> words;
	std::vector<std::string> retMin;
	std::string line, word;
	std::stringstream ss; 
	bool check;

	// put words in vector from in
	while ( getline(in,line) ) {
		ss.clear();
		ss<<line;
		while ( ss >> word ) {
			if ( word != "" ) {
				words.push_back(word);
			}
		} // end ss >> word
	} // end while
	
	// puts strings that are min heap in retMin
	for ( int i = 0; i < words.size(); i++) {
		check = isMinHeap(words[i]);
		if( check == true ) {
			retMin.push_back(words[i]);
		}
	}
	// sorts retMin
	if(retMin.size() == 0) {
		return retMin;
	}

	doSomeSort(retMin);

	return retMin;
}

