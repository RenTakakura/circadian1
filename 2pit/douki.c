#include <stdio.h>
#include <math.h>

#define k     -10.0
double fxa(double xa,double xex){
  return    k * sin(xa - xex);
}




int main(void){
  
  
  double dt = 1.0/500.0;
  int maxstep =5000;
  
  
  
  
  FILE *fp;
  int step;
  double xa, xa0, va, va0, xex, kxa1, kxa2, kxa3, kxa4;
  
  
  
  fp = fopen("sample10.0.dat","w");
  
  
  
  xa =  M_PI*(2.0/3.0);
  va =  2.0*M_PI*(1.50);
  xex = 0.0;
  
  
  
  for(step=0; step<maxstep; step++){
    
    xa0 = xa;
    
    xex = 2.0*M_PI*dt*step;
    
    kxa1 =   fxa(xa,xex)*dt;
    kxa2 =   fxa(xa + kxa1/2,xex)*dt;
    kxa3 =   fxa(xa + kxa2/2,xex)*dt;
    kxa4 =   fxa(xa + kxa3,xex)*dt;
    xa =    xa + (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6 + va*dt;
    
    va0 = (xa - xa0 )/dt;
    
    fprintf(fp,"%lf %lf %lf %lf %lf \n", step*dt,cos(xex),sin(xex),cos(xa),sin(xa));
    
  }
  
}
