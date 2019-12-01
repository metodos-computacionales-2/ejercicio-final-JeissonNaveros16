#include <iostream>
#include <cstdlib>
#include <math.h>

double logfunc(double r, double c);
double fixed_points(double R, double x0);
double estable(double R, double x);

int main()
{   
    for(double r = 0.2; r<2.9; r+=0.1)
    {
        double xf = fixed_points(r, 1.2);
        std::cout << r << "  " << xf << "\n";
    }
    
    return 0;
}

double logfunc(double r, double c)
{
    return r*c*(1-c);
}

double fixed_points(double R, double x0)
{
    //Condición inicial
    double x_past = x0;
    double x_new = logfunc(R, x_past);
    
    //Busqueda de Fixed points
    while( fabs(x_new - x_past) > 0.0001 )
    {
        double temp = x_new;
        x_new = logfunc(R, x_new);
        x_past = temp;
    }
    return x_new;
}

double estable(double R, double x)
{
    double n_t = 0.001;
    double x_t = x + n_t;
    double x_t1 = logfunc(R, x_t);
    double n_t1 = x_t1 - x;
    double f_prim = n_t1/n_t;
    return f_prim;
}