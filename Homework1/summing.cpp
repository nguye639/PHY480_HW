/*
The graph of the error of summing up vs. summing up is linear with a power of 1; or every order of magnitude taken in steps, is an order of
magnitude increase in error for greater than 10,000 steps. After 10,000 steps machine error starts to kick in when dividing by large N. Less
than 10,000 steps, the error decreases with step with a power of about .1. 

Summing downward is more precise because starting with the smallest number forces the computer to look at the most decimal places. With summing up, the first number is 1, and the computer in single precision will look at the ones place and ignore decimals as it adds smaller numbers.
*/


// Le Nguyen
// nguye639@msu.edu
// 02-Feb-2019 created program
// 05-Feb-2019 created makefile
// 02-May-2019 corrected graph

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

float up(int N);
float down(int N);

//make vector to store values
float down(int N)
{
  
  float num = 0;
  //sum down loop
  for(int i=1; i <= N; i++)
  {
    num += float(1)/i;

  }
return num;
}

//create function that will return a vector of values
float up(int N)
{
  
  float num = 0;

  //Summing up loop
  for(int j= N; j > 0; j--)
  {
    num += float(1)/j;

  }

return num;
}

int main()
{
 //creating output file
 ofstream output;
 output.open("summing.dat");

 //define number of steps
 const int N = 100000000;
 
 //column headers
 output <<"N"<<"     "<<"Sum up"<<"     "<< "Sum down"<<endl; 
 //print out the values into a file
 for(int i= 100; i <= N; i*=10)
   {
     //get the values from the sum_up and sum_down functions
     float sum1 = up(i);
     float sum2 = down(i);

     output << i << "      "<< setprecision(8) <<sum1<<"       " <<sum2<<"     "\
     <<fabs(sum1-sum2)/(.5*(fabs(sum1)+fabs(sum2))) <<endl;
   }

 output.close(); 
 return 0;
}


