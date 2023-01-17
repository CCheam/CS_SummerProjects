#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;



int main() {
  // ofstream fOut;
  ifstream fIn;
  // variable setup
  string inp_file;
  string out;

  // input ask/collection
  cout << "Please enter the input file: ";
  cin >> inp_file;
  ofstream f(inp_file, ios_base::out | ios_base::app);
  f.open(inp_file);
  if (f.is_open()) {
    cout << "File successfully opened." << endl;
    while (getLine(f, out)) {
      cout << out << endl;
    }
  } else {
    cout << "Error. Please try again." << endl;
  }
  return 0;
}

