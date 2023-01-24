#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void makeTriangle(ofstream &oFile, int size, char c);
void makeEight(ofstream &, int, char);
void makeSlash(ofstream &oFile, int size, char c);

int main() {

  ofstream fOut("Output.txt", ios_base::out | ios_base::app);

  makeTriangle(fOut, 9, 68);
  
  //makeEight(fOut, 10, 68);
  
  //makeSlash(fOut, 10, 68);

  /*
  // title screen
  cout << "************************************\n";
  cout << "********       Billy        ********\n";
  cout << "********       Shape        ********\n";
  cout << "********       Maker        ********\n";
  cout << "************************************\n";
  // variable setup
  string inp_file;
  string inp;
  char letter;
  int size;
  // input ask/collection
  cout << "Please enter the input file: ";
  cin >> inp_file;
  // Input file specified
  ifstream fIn(inp_file, ios_base::out | ios_base::app);
  ofstream fOut;
  //  Check if open and read line
  if (fIn.is_open()) {
    cout << "File successfully opened." << endl;
    //acts as a for loop with input lines from the file
    while (std::getline(fIn, inp)) {

    // if inp is not an enter
    if (inp.find(" ") <= inp.size()){

      // Shape vars
      string shapeType = inp.substr(0, inp.find(" "));
      string shapeTemp = inp.substr(inp.find(" "), inp.size()-1);
      string shapeSize = shapeTemp.substr(0, shapeTemp.find(" ")); //

      //Figure Eight Check
      if (shapeType.compare("figureEight")) {
        fstream outF(shapeType + "_" + shapeSize + ".txt", ios_base::out |
  ios_base::app);
      }
      // Triangle Check
      else if (shapeType.compare("triangle")) {
        fstream outF(shapeType + "_" + shapeSize + ".txt", ios_base::out |
  ios_base::app);
      }
      // Slash Check
      else if (shapeType.compare("slash")) {
        fstream outF(shapeType + "_" + shapeSize + ".txt", ios_base::out |
  ios_base::app);
      }
    }
  }
  } else {
    cout << "Error. Please try again." << endl;
  } */
  return 0;
}

// Make Triangle
void makeTriangle(ofstream &oFile, int size, char c) {
  int half = (size / 2);
  cout << half << '\n';

  // Looping through Grid
  for (int i = 0; i < size * 2; i++) { // row
    for (int j = 0; j < size * 2; j++) { // column
      // even Numbers
      if (size % 2) {
        if (j == size + i || j == size - i) {
          oFile << c;
        } else if (i == size - 1) {
          oFile << c;
        } else {
          oFile << ' ';
        }
      }
      // odd Numbers
      else {
        if (j == half && i == 0) {
          oFile << c;
        }
        if (j == (half) + i || j == (half) - (i)) {
          oFile << c;
        } else if (i == size - 1) {
          oFile << c;
        } else {
          oFile << ' ';
        }
      }
    }
    oFile << '\n';
    // find center and move out by i each size
  }
  oFile.close();
}

// Make Slash
void makeSlash(ofstream &oFile, int size, char c) {
  // make row
  for (int i = 1; i <= 3; i++) {
    oFile << ' ';
  }

  int number = 1;
  for (int i = 1; i <= size; i++) {
    oFile << number;
    if (number < 9) {
      number++;
    } else {
      number = 0;
    }
  }

  oFile << endl;
  oFile << endl;

  // Part is where the char will go in a line
  double part = size;

  // Loops through all rows based on size
  for (int i = 1; i <= size; i++) {

    // Places the y-axis numbers
    if (i < 10) {
      oFile << ' ';
      oFile << i;
      oFile << ' ';
    } else {
      oFile << i;
      oFile << ' ';
    }

    /* Loops though a line based on "size" and checks if current place is where
     * the "char" is supposed to be based on "part" and subtract from "part" for
     * the next line if it is. If not, it places a space and moves on.*/
    for (int i = 1; i <= size; i++) {
      if (i == part) {
        oFile << c;
        part--;
      } else {
        oFile << ' ';
      }
    }
    oFile << endl;
  }
  oFile << endl;

  // makerow
  for (int i = 1; i <= 3; i++) {
    oFile << ' ';
  }

  number = 1;
  for (int i = 1; i <= size; i++) {
    oFile << number;
    if (number < 9) {
      number++;
    } else {
      number = 0;
    }
  }

  // make row
  for (int i = 1; i <= 3; i++) {
    oFile << ' ';
  }

  number = 1;
  for (int i = 1; i <= size; i++) {
    oFile << number;
    if (number < 9) {
      number++;
    } else {
      number = 0;
    }
  }
  oFile.close();
}

// Make Eight
void makeEight(ofstream &oFile, int size, char c) {
  // Check if the size is greater than 9
  if (size > 9) {
    // edgeWidth = size / 10 with a minimum of 2
    // tbmRowCount = edgeWidth / 2
    int edgeWidth, tbmRowCount, lineSize;
    edgeWidth = size / 10;
    if (edgeWidth < 2) {
      edgeWidth = 2;
    }
    tbmRowCount = edgeWidth / 2;

    // Loop through the rows of the 8
    for (int l = 1; l <= size; l++) {

      // Check if the row is in the top or bottom edge
      if (l <= tbmRowCount ||
          (l > (size / 2) && (l <= ((size / 2) + tbmRowCount))) ||
          l > (size - tbmRowCount)) {

        // Print the top and bottom edges of the 8
        for (int i = 0; i < size; i++) {
          while (i < edgeWidth) {
            oFile << ' ';
            i++;
          }
          oFile << c;
        }
      } else {
        // Print the left and right edges of the 8
        for (int i = 0; i < edgeWidth; i++) {
          oFile << c;
        }
        // Print the space in the middle of the 8
        for (int i = 0; i < size - (edgeWidth); i++) {
          oFile << ' ';
        }
        // Print the right edge of the 8
        for (int i = 0; i < edgeWidth; i++) {
          oFile << c;
        }
      }
      // Add a newline character to separate rows, except for the last one
      if (l != size) {
        oFile << '\n';
      }
    }
  } else {
    cout << "Size is invalid value";
  }
  oFile.close();
}