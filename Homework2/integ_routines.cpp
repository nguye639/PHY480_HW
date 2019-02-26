//Le Nguyen
//nguye639@msu.edu
//25-Feb-2019 created program
//25-Feb-2019 added Milne's rule


// include files
#include "integ_routines.h"   // integration routine prototypes 

// Integration using Simpson's rule
float simpsons_rule ( int num_pts, float x_min, float x_max, 
                      float (*integrand) (float x) )
{  
   float interval = ((x_max - x_min)/float(num_pts - 1));  // called h in notes
   float sum=  0.;  // initialize integration sum to zero		 
   
   double x1, x2;
   for (int n=2; n<num_pts; n+=2)  // step through the integral, 2 points at a time  
   {
     x1 = x_min + interval * (n-1);
     x2 = x1 + interval;
     sum += 4. * integrand(x1) + 2. * integrand(x2);
   }
   sum += integrand(x_min) - integrand(x_max);    
   sum *= interval/3.; 
   return (sum);
}  

// Integration using Milne's rule
float milne_rule ( int num_pts, float x_min, float x_max,
                      float (*integrand) (float x) )
{
   float interval = ((x_max - x_min)/float(num_pts - 1));  // called h in notes
   float sum=  0.;  // initialize integration sum to zero 

               
   double x1, x2, x3, x4, x5;
   for (int n=2; n<num_pts; n+=5)  // step through the integral, 5 points at a time  
   {
     x1 = x_min + interval * (n-1);
     x2 = x1 + interval;
     x3 = x2 + interval;
     x4 = x3 + interval;
     x5 = x4 + interval;

     sum += (14./45) * integrand(x1) + (64./45.) * integrand(x2) + (24./45.)* integrand(x3) + (64./45)*integrand(x4) + (14./45.)*integrand(x5);
   }
   sum += integrand(x_min) - integrand(x_max);
   sum *= interval/5.;

   return (sum);
}








