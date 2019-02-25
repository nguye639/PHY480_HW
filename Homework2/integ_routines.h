//Le Nguyen
//nguye639@msu.edu
//25-Feb-2019 created file

//initializes used libraries and functions
#ifndef header
#define header

// include files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <gsl/gsl_integration.h>
using namespace std;

extern float simpsons_rule ( int num_pts, float x_min, float x_max, 
                       float (*integrand) (float x) );    // Simpson's rule 
   
extern float Milne_rule ( int num_pts, float x_min, float x_max,
                       float (*integrand) (float x) );    // Milne's rule 


#endif
