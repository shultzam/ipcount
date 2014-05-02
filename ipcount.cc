/*
 *	file:	ipcount.cc
 *	author: Allen S
 *	date:   4/25/2014
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <iomanip>

#include <stdlib.h>
#include <stdio.h>
#include <cstddef>

using namespace std;

#define DEBUG

int main()
{
	int array[256];		/* Stores domain count */
	int count = 0;		/* tracks occurences */
	int num = 0;		/* num of IPs */
	int ip;			/* To determine the ip */
	int current, next = 0;	/* Used to accumulate ips */
	int i, j = 1;		/* Used in for loops */

	string line;		/* line is initial, then appended */
	size_t end = 0;
	ifstream infile("ips.txt");
	ofstream outfile("results.txt");
	ofstream list("list.txt");

	for (i = 1; i < 256; i++)
		array[i] = 0;

	if(infile.is_open()){
		while(getline(infile, line)){	
			end = line.find_first_not_of("0123456789");
			if(end <= 3)
				line.resize(end);
			for(string::iterator it = line.begin(); it != line.end(); ++it){
				ip = atoi(line.c_str());
				list << ip << endl;
				array[ip]++;
			}
			end = 0;
		}
	}
	
	else cout << "unable to open file" << endl;
 	
	if(outfile.is_open()){
        	cout << "outfile is open" << endl;
		outfile << "ip" << '\t' << "count" << endl;
		outfile << "--------------" << endl; 
        	for(j = 1; j <= 256; j++){
			if(j < 10)
   				outfile << j << '\t' << array[j] << endl;
			if(j > 255)
				break;
			if(j > 9 && j < 100)
				outfile << j << '\t' << array[j]/2 << endl;
			if(j > 99 && j < 256)
				outfile << j << '\t' << array[j]/3 << endl;
			
		}
	}

	infile.close();
	outfile.close();
	
	return 0;

}	
