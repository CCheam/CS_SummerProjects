#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream MyFile("test.txt");

	MyFile << "File go brrrrrrrrrrrrrrrrr\n";

	MyFile.close();
}
