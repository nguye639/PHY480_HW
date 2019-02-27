//Le Nguyen
//nguye639@msu.edu
//25-Feb-2019 created program
//Moved all function declarations to header file

#include "integ_routines.h"	// prototypes for integration routines

int
main ()
{
  // set up the integration specifiction
  const int max_intervals = 10001;	// maximum number of intervals
  const float lower = 0.0;	// lower limit of integration
  const float upper = M_PI;	// upper limit of integration

  const double answer = 2.43532;	// the "exact" answer for the test 
  float result = 0.;  // approximate answer

  // open the output file stream
  ofstream integ_out1 ("integ1.dat");	// save data in integ.dat
  integ_out1 << "#  N     simpson        GSL  " << endl;
  integ_out1 << "#-----------------------------------------" << endl;

  for (int i = 3; i <= max_intervals; i += 2)
  {
    integ_out1 << setw(4) << log10(i);

    result = simpsons_rule (i, lower, upper, &my_integrand);
    integ_out1 << "  " << scientific << log10(fabs (result - answer)/answer);
    
    result = GSL_integ (lower, upper, &my_gsl_integrand);
    integ_out1 << "  " << scientific << log10(fabs (result - answer)/answer);

    integ_out1 << endl;
  }
  
  integ_out1.close ();

  ofstream integ_out2 ("integ2.dat");    // save data in integ.dat
  integ_out2 << "#  N     Milne    " << endl;
  integ_out2 << "#-----------------------------------------" << endl;

for (int i = 3; i <= max_intervals; i += 4)
  {
    integ_out2 << setw(4) << log10(i);

    result = milne_rule (i, lower, upper, &my_integrand);
    integ_out2 << "  " << scientific << log10(fabs (result - answer)/answer);
   
    integ_out2 << endl;
  }

  integ_out2.close ();

  return (0);
}

// the function we want to integrate 
double
my_integrand (double x)
{
  return (sqrt(x)*sin(x));
}

double my_gsl_integrand (double x, void *)
{
  return (my_integrand(x));
}

