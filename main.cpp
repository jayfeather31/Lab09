//Lab 09
//Spencer Romberg
//COSC 2030 Fall 2018



#include <iostream>
#include <map>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::ignore;
using namespace std;
/*
template < class Key,                              // map::key_type
	class T,                                       // map::mapped_type
	class Compare = less<Key>,                     // map::key_compare
	class Alloc = allocator<pair<const Key, T> >   // map::allocator_type
> class map;*/

//prototype for get_file_name()
string get_file_name();

string get_file_name()
{
	string file_name;
	cout << "Enter the name of the file you wish to check: ";
	cin >> file_name;
	return file_name;
}

int main()
{
	string input;
	string transitional;
	ifstream inFile;
	ofstream outFile;
	map<string, int> lab_nine;
	input = get_file_name();
	inFile.open(input);                  //open the file
	if (inFile.is_open())                //check to see if the file is even open
	{
		while (inFile >> transitional)
		{
			++lab_nine[transitional];
		}


	}
	outFile.open("output.txt");         //open the file for output
	if (outFile.is_open())              //check to see if the new file was open
	{
		for (std::map<string, int>::iterator position = lab_nine.begin(); position != lab_nine.end(); ++position)
		{
			for (int i = 0; i < position->second; i++)
			{
				outFile << position->first;
			}
		}
	}
	outFile.close();



	
	system("pause");
}