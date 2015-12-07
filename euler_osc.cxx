#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    double* const xf = new double[2];
    xf[0] = 1; xf[1] = 0;
    double* const xb = new double[2];
    xb[0] = 1; xb[1] = 0;
    
    const double dt = M_PI/10;
    const double t_end = 5*M_PI;
    double t = 0;
    
    double f_t, b_t;
    
    ofstream out("d");
    for (t; t<=t_end; t+=dt) {
      out << t << "\t" << xf[0] << "\t" << xb[0] << endl;
      f_t = xf[0];
      xf[0] = xf[0]+dt*xf[1];
      xf[1] = xf[1]-dt*f_t;
      b_t = xb[0];
      xb[0] = (xb[0]+dt*xb[1])/(1+dt*dt);
      xb[1] = (-dt*b_t+xb[1])/(1+dt*dt);
    }
    out << t << "\t" << xf[0] << "\t" << xb[0] << endl;
    out.close();
    
    return 0;
}