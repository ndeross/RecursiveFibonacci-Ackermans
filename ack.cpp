//Nicholas DeRoss
// CSCI 230 
// HW3 

#include <iostream>
#include <iomanip>

using namespace std;

void MakeTable();
int Ackerman(int m, int n);

const int MAX_VALUE = 4; 

int main() {
    
    int i; 

  
  cout << " m"
       << "\\"
       << "n" << setw(2) << "|";

  i = 0;

  while (i <= MAX_VALUE)

  {
    cout << setw(5) << i;
    i++;
  }

  cout << endl;

  cout << setfill('-') << setw(6) << "+" << setfill('-') << setw(26) << "-";

  cout << endl;

  cout << setfill(' ');

 // Row One
  cout << setw(6) << "0 |";

  i = 0;

  while (i <= MAX_VALUE) {
    cout << setw(5) << Ackerman(0, i);
    i++;
  }

  cout << endl;

  // Row Two 
  
  cout << setw(6) << "1 |";

  i = 0;

  while (i <= MAX_VALUE) {
    cout << setw(5) << Ackerman(1, i);
    i++;
  }

  cout << endl;

  // Row Three
  cout << setw(6) << "2 |";

  i = 0;

  while (i <= MAX_VALUE) {
    cout << setw(5) << Ackerman(2, i);
    i++;
  }

  cout << endl;

  // Row Four
  cout << setw(6) << "3 |";
  i = 0;

  while (i <= MAX_VALUE) {
    cout << setw(5) << Ackerman(3, i);
    i++;
  }

  cout << endl;

  return 0;
}




// This will compute Ackermans function recursivley  

int Ackerman(int m, int n)

{
  if (m == 0) {
    return n + 1;
  }
  if (n == 0) {
    return Ackerman(m - 1, 1);
  }

  else {
    return Ackerman(m - 1, Ackerman(m, n - 1));
  }
}
