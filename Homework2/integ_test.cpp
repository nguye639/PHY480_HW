//Le Nguyen
//nguye639@msu.edu
//25-Feb-2019 created program
//Moved all function declarations to header file

#include "integ_routines.h"	// prototypes for integration routines

int
main ()
{
  // set up the integration specifiction
  const int max_intervals = 1001;	// maximum number of intervals
  const float lower = 0.0;	// lower limit of integration
  const float upper = M_PI;	// upper limit of integration

 // const double answer = M_PI;	// the "exact" answer for the test 
  float result = 0.;  // approximate answer

  // open the output file stream
  ofstream integ_out ("integ.dat");	// save data in integ.dat
  integ_out << "#  N     trapezoid       Milne        GSL  " << endl;
  integ_out << "#-----------------------------------------" << endl;

  // Simpson's rule requires an odd number of intervals  
  for (int i = 3; i <= max_intervals; i += 2)
  {
    integ_out << setw(4) << log10(i);

    result = simpsons_rule (i, lower, upper, &my_integrand);
    integ_out << "  " << scientific << result;   //(fabs (result - answer)/answer);

    result = milne_rule (i, lower, upper, &my_integrand);
    integ_out << "  " << scientific << result;  //(fabs (result - answer)/answer);
    
    result = GSL_integ (lower, upper, &my_gsl_integrand);
    integ_out << "  " << scientific << result; // (fabs (result - answer)/answer);

    integ_out << endl;
  }

  cout << "data stored in integ.dat\n";
  integ_out.close ();

  return (0);
}


// the function we want to integrate 
double
my_integrand (double x)
{
  return (x*sin(x));
}

double my_gsl_integrand (double x, void *)
{
  return (my_integrand(x));
}

