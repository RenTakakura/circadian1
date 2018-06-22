
#include <stdio.h>
#include <math.h>

int main(void){
  
  int step, cnt;
  int maxstep=20000;
  double xex,xex0,dxex,T,T0,t2;
  double dt=10.0/8640;
  double p=5.0/8.0;
  
  FILE *fp;
  
  fp=fopen("loop.txt","w");
  
  cnt=0;
  
  xex=0;
  
  T=0;
  
  T0=0;
  
  for(step=0;step<maxstep;step++){
    
    t2=tan(M_PI*(1.0-p))*tan(M_PI*(1.0-p));
    
    dxex =   2.0*M_PI*dt*sqrt((1.0+t2)/t2)*(1.0 - (1.0/sqrt(1.0+t2))*sin(xex));
    
    xex0=xex;
    
    if(sin(xex)*sin(xex+dxex)<0.0){
      
      T0 = T;
      T = (step+1)*dt;
      cnt++;
      
      fprintf(fp,"%lf %lf \n",T,T-T0);
      
      
    }
    xex=xex+dxex;
  }
  
}
