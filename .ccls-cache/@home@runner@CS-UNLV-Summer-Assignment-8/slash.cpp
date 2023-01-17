#include <fstream>
#include <iostream>

using namespace std;

/* Loops and places numbers based on "size" and if size goes over 9, it goes
 * back 0 and continues*/
void rowsize(double size) {
  cout << " ";
  cout << " ";
  cout << " ";

  int number = 1;
  for (int i = 1; i <= size; i++) {
    cout << number;
    if (number < 9) {
      number++;
    } else {
      number = 0;
    }
  }
}

void makeSlash(/*ofstream& oFile,*/ int size, char c) {

  rowsize(size);

  cout << endl;
  cout << endl;

  // Part is where the char will go in a line
  double part = size;

  // Loops through all rows based on size
  for (int i = 1; i <= size; i++) {

    // Places the y-axis numbers
    if (i < 10) {
      cout << " ";
      cout << i;
      cout << " ";
    } else {
      cout << i;
      cout << " ";
    }

    /* Loops though a line based on "size" and checks if current place is where
     * the "char" is supposed to be based on "part" and subtract from "part" for
     * the next line if it is. If not, it places a space and moves on.*/
    for (int i = 1; i <= size; i++) {
      if (i == part) {
        cout << c;
        part--;
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
  rowsize(size);
}

//int main() { makeSlash(7, 'c'); }