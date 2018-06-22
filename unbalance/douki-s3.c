#include <stdio.h>

#include <math.h>

#define l     -10.00
double fxa(double xa,double xex){
  return    l * sin(xa - xex);
}


int main(void){

  
  double dt = 5.0/8640.0;
  int maxstep =160000;
  
  
  
  
  FILE *fp;
  int step;
  double T, T0, xa, xa0, va, va0, xex, xex0, x0ex, vex, kxa1, kxa2, kxa3, kxa4;
  
  
  
  fp = fopen("time2w1.1-l10.0.txt","w");
  
  
  
  xa =  M_PI*(1.0/3.0);
  va =  2.0*M_PI*(1.10);
  xex = 0.0;
  
  
  
  for(step=0; step<maxstep; step++){
    
    xa0 = xa;
    x0ex = xex;
    
    kxa1 =   fxa(xa,xex)*dt;
    kxa2 =   fxa(xa + kxa1/2,xex)*dt;
    kxa3 =   fxa(xa + kxa2/2,xex)*dt;
    kxa4 =   fxa(xa + kxa3,xex)*dt;
    xa =    xa + (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6 + va*dt;
    
    va0 =   (xa - xa0 )/dt;
    
    
    
    xex0 =   2.0*M_PI*dt* (1 - sin(xex)*0.25850)*1.034722;
    
    xex = xex + xex0;
    
    if(sin(xex)*sin(x0ex)< 0.0){
      
      T0 = T;
      
      T = step*dt;
      
      fprintf(fp,"%lf %lf \n", T, T-T0);
      
    }
    
  }
  
}
