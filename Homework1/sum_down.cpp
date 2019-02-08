// Le Nguyen
// nguye639@msu.edu
// 02-Feb-2019 created program
// 05-Feb-2019 added vectors

//include header file
#include "sum_header.h"

//make vector to store values
vector <float> down(int N)
{
  vector <float> sum1;
  float num = 0;
  //sum down loop
  for(int i=1; i <= N; i++)
  {
    num += (float)1/i;
    sum1.push_back(num);
    
  }
return sum1;
}
  







 
