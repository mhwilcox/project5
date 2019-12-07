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
	
	std::cout<<"string: "<<s<<std::endl;
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
	//	std::cout<<"s["<<c<<"] ("<< s[c] <<") <= s[ "<<y<<" + 1]("<<s[y+1]<<")"<<std::endl;
		if ( s[c] <= s[ y + 1] && isalpha(s[y + 1]) ) {
			check = true;
		}
		else if ( !isalpha(s[y+1]) ) {
	//		std::cout<<"blank node. break;"<<std::endl;
			break;
		}
		else {
			check = false;
			break;
		}
	//	std::cout<<"s["<<c<<"] ("<< s[c] <<") <= s[ "<<y<<" + 2] ("<<s[y+2]<<")"<<std::endl;
		if( s[c] <= s[ y + 2] && isalpha(s[y + 2]) ) {
			check = true;
		}
		else if ( !isalpha(s[y + 2]) ) {
	//		std::cout<<"blank node. break;"<<std::endl;
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
std::cout<<"\nin string: ";
for( int k = 0; k<vec.size(); k++) {
	std::cout<<vec[k]<<", ";
}	
	// while unchecked values is greater than 1 do loop
	while ( unchecked > 1) {
		for ( int i = 0; i < unchecked; i++) {
		std::cout<<"compare curMax: "<<max<<" to vec["<<i<<"]: "<<vec[i]<<std::endl;
			// if max < vec[i] then put max as vec[i] and nmax is the address in the vec where the new max came from
			// 	and temp is the old max
			if ( max < vec[i] ) {
				max = vec[i];
				temp = vec[unchecked];
				nmax = i;
			}
			// if the max is already at the end of the vector, decrement unchecked and change max to the next value
			else if (max == vec[unchecked]) {
				std::cout<<"max == vec[unchecked]"<<std::endl;
				unchecked--;
				max = vec[unchecked];
				break;
			}
			
		} // end for loop
		std::cout<<"out of for loop."<<std::endl;
		// assign max to the farthest right address that hasn't been given a max value yet
		//	decrement unchecked and assign max to the new farthest right value
		if ( max != vec[unchecked]) {
			std::cout<<"temp: "<<vec[unchecked]<<"\n new max: "<<max<<std::endl;;
			vec[unchecked] = max;
			vec[nmax] = temp;
			unchecked--;
			max = vec[unchecked];
		}
		std::cout<<"end of while loop"<<std::endl;
	} // end while loop

std::cout<<"\nsolution: ";
for( int k = 0; k<vec.size(); k++) {
	std::cout<<vec[k]<<", ";
}
	std::cout<<"\n end sort\n"<<std::endl;
}


std::vector<std::string> findHeaps(std::istream & in)
{
	std::cout<<"findHeaps"<<std::endl;
	std::vector<std::string> words;
	std::vector<std::string> retMin;
	std::string line, word;
	std::stringstream ss; 
	bool check;

	while ( getline(in,line) ) {
		ss.clear();
		ss<<line;
		while ( ss >> word ) {
			if ( word != "" ) {
				words.push_back(word);
			}
		} // end ss >> word
	} // end while
	std::cout<<"size of words: "<<words.size()<<"\nwords: "<<std::endl;
	for( int k = 0; k < words.size(); k++) {
		std::cout<<words[k]<<", ";
	}

	std::cout<<"now on to MinHeap"<<std::endl;
	// puts strings that are min heap in retMin
	for ( int i = 0; i < words.size(); i++) {
		check = isMinHeap(words[i]);
		if( check == true ) {
			retMin.push_back(words[i]);
		}
	}
	std::cout<<"size of retMin: "<<retMin.size()<<std::endl;
	// sorts retMin
	doSomeSort(retMin);
std::cout<<"after sort in findHeaps"<<std::endl;

	std::cout<<" retMin: ";
for(int f = 0; f < retMin.size(); f++) {
	std::cout<<retMin[f]<<", ";
}

std::cout<<"\n end of findHeaps"<<std::endl;
	return retMin;
}

