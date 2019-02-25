//Le Nguyen
//nguye639@msu.edu
//25-Feb-2019 created program

// include files
#include "integ_routines.h"   // integration routine prototypes 

// Integration using Simpson's rule
float simpsons_rule ( int num_pts, float x_min, float x_max, 
                      float (*integrand) (float x) )
{  
   float interval = ((x_max - x_min)/float(num_pts - 1));  // called h in notes
   float sum=  0.;  // initialize integration sum to zero		 
   
   for (int n=2; n<num_pts; n+=2)                // loop for odd points  
   {
     float x = x_min + interval * float(n-1);
     sum += (4./3.)*interval * integrand(x);
   }
   for (int n=3; n<num_pts; n+=2)                // loop for even points  
   {
     float x = x_min + interval * float(n-1);
     sum += (2./3.)*interval * integrand(x);
   }   
   // add in the endpoint contributions   
   sum +=  (interval/3.) * (integrand(x_min) + integrand(x_max));	
   
   return (sum);
}  

