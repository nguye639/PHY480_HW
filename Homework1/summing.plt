set title 'Error vs Step'
set xlabel 'Step'
set ylabel 'Error'

set logscale

f(x) = a*x+b
fit [1000:1000000] f(x) "summing.dat" using ($1):($4) via a,b

plot "summing.dat" using ($1):($4),\
a*x+b 

set out "summing.ps"
set term postscript color enhanced
replot

