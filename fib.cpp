// Nicholas DeRoss
// CSCI 230 
// HW3 

#include <iostream>
#include <time.h>

using namespace std;

int Fib(int n, long &count);
int FibLoop(int n, long &loop);
const int US_TO_SEC = 1000000;
const int LOOP_LIMIT = 20; 

int main() {
  int i;
  long count;
  long loop;
  clock_t start, stop, time;

  count = 1;
  loop = 0;

// Recursive fib sequence start 

  for (i = 1; i <= LOOP_LIMIT; i++) {
    cout << "Fib(" << i << ") = " << Fib(i, count) << " calls " << count
         << endl;
  }
  
  
count = 0; 

// Although the numbers are only set to calculated from Fib(1) to Fib(20)
// this block will compute the time it takes to calculate Fib(50) without
// any cout statements using recursion 

  start = clock();
  Fib(50, count);
  stop = clock();
  time = stop - start;
  cout << "It  took " << time << " microseconds or " << time / US_TO_SEC
       << " seconds to reach Fib(50)." << endl;
       


// Loop fib sequence start 

  cout << endl;
  for (i = 1; i <= LOOP_LIMIT; i++) {
    cout << "Fib(" << i << ") = " << FibLoop(i, loop) << " loops " << loop
         << endl;
  }


// Although the numbers are only set to calculated from Fib(1) to Fib(20) 
// this block will compute the time it takes to calculate Fib(50) without 
// any cout statements using the loop  

  start = clock();
  FibLoop(50, loop);
  stop = clock();
  time = stop - start;
  cout << "It took " << time << " microseconds or " << time / US_TO_SEC
       << " seconds to reach Fib(50)." << endl;

  return 0;
} 


//This function will compute the Fibannaci number using 
// recursion 

int Fib(int n, long &count) {
  long int returnValue;

  if (n == 1 or n == 2) {
    returnValue = 1;
    count++;
  } else {
    returnValue = Fib(n - 1, count) + Fib(n - 2, count);
    count++;
  }
  return returnValue;
}


// This Function will calculate the Fibannaci number 
// for the given input using an interation based loop system 

int FibLoop(int n, long &loop)

{
  int num1 = 1;
  int num2 = 1;
  long FibNumber = 1;

  for (int i = 2; i <= n; i++) {
    if (i == 3) {
      loop = 1;
    }
    FibNumber = num2 + num1;
    num1 = num2;
    num2 = FibNumber;
    loop++;
  }
  return FibNumber;
}