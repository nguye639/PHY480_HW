// Le Nguyen
// nguye639@msu.edu
// 02-Feb-2019 created program
// 05-Feb-2019 added vectors

//include header file
#include "sum_header.h"

//create function that will return a vector of values
vector<float> up(int N)
{
  vector<float> sum2;
  float num = 0;

  //Summing up loop
  for(int i= N; i > 0; i--)
  {
    num += (float)1/i;
    sum2.push_back(num);
    
  }
  

return sum2;
}




 
