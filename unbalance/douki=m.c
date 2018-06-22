#include <stdio.h>
#include <math.h>




int main(void){
  
  
  double dt = 10.0/86400;
  double maxstep =100000;
  double k = -300.0;
  
  
  
  FILE *fp;
  int step;
  double xa, xb, va, vb, xex, kxa1, kxa2, kxa3, kxa4, kxb1, kxb2, kxb3, kxb4;
  
  
  
  fp = fopen("douki-m.txt","w");
  
  
  
  xa =  (0.333)*M_PI;
  xb =  (0.667)*M_PI;
  va =  (1.20)*2*M_PI;
  vb =  (1.50)*2*M_PI;
  
  double fxa(xa,xex){
    return va  + k * sin(xa - xex);
  }
  
  double fxb(xb,xex){
    return vb + k*sin(xb - xex);
  }
  
  for(step=0; step<maxstep; step++){
    
    
    xex = 2*M_PI*dt*step;
    
    kxa1 =   fxa(xa,xex)*dt;
    kxa2 =   fxa(xa + kxa1/2,xex)*dt;
    kxa3 =   fxa(xa + kxa2/2,xex)*dt;
    kxa4 =   fxa(xa + kxa3,xex)*dt;
    xa =    xa + (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6;
    
    kxb1 =   fxb(xb,xex)*dt;
    kxb2 =   fxb(xb + kxb1/2,xex)*dt;
    kxb3 =   fxb(xb + kxb2/2,xex)*dt;
    kxb4 =   fxb(xb + kxb3,xex)*dt;
    xb =    xb + (kxb1 + 2*kxb2 + 2*kxb3 + kxb4)/6;
    
    fprintf(fp,"%lf %lf %lf %lf\n", step*dt,sin(xex),sin(xa),sin(xb));
    
  }
  
}
