// Le Nguyen
// nguye639@msu.edu
// 02-Feb-2019 completed 1-6 on to-do list


// include files
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;
	      

//*********************************************************************//
// inline square function
inline double sqr(double x)
{

return x*x;

}

int main ()
{

// creating file to output to
  ofstream output;
  output.open("area_new.dat");

  double radius;    // every variable is declared as int or double or ...

  cout << "Enter the radius of a circle: ";	// ask for radius
  cin >> radius;

// checking to make sure the radius is positive  
  if(radius < 0)
  {
  output << "Radius must be positive";
  }

// if it is positive, the calculation goes through
  else
  {

// using math.h defined pi value and  sqaure function to calculate area
  double area = M_PI * sqr(radius);	// standard area formula

// output to file with 16 digits
  output << "radius = " << setprecision(16) << radius << ",  area = "<< setprecision(16) << area << endl;

// close file
  output.close();
  }

  return 0;			// "0" for successful completion
}

//*********************************************************************//
