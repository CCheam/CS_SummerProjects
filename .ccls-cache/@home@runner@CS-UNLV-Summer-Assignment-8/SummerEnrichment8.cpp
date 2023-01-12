#include <iostream>
#include <fstream>

using namespace std;

int main()
{
       //title screen
	cout << "************************************\n";
	cout << "********       Billy        ********\n";
	cout << "********       Shape        ********\n";
	cout << "********       Maker        ********\n";
	cout << "************************************\n";
	//variable setup
	fstream inp_file;
	char letter;
	int size;
	//input ask/collection
	cout << "Please enter the input file: ";
	cin >>inp_file;
	inp_file.open(inp_file);
	if(){
	cout<<"File successfully opened."
	}
	else{
	cout<<"Error. Please try again."
	}
		/*
			ofstream MyFile("test.txt");

			MyFile << "File go brrrrrrrrrrrrrrrrr\n";

			MyFile.close();
			*/
}
