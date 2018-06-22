#include <stdio.h>
#include <math.h>

int main(void){
  
  
  double dt = 1.0/1000.0;
  
  FILE *fp;
  
  int step; 
  
  double t,f,T,s,x1,x2,y1,y2,z1,z2;
  
  double k=M_PI/1.10;
  
  double d=M_PI;
  
  
  f=k/d;
  
  fp = fopen("self.txt","w");
  
  for(step=0; step<=1000;step++){
    
    t = step*dt;
    
    T = tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.5)*t);
    
    s = (k/d + 2.0*T)/(k*T/d - 2.0);
    
    x1 = s+pow(1.0+pow(s,2.0),0.50);
    
    y1 = (x1+T)/(1-x1*T);
    
    z1 = 1.0-(1.0/M_PI)*(atan(f+y1) - atan(f+x1));
    
    x2 = s-pow(1.0+pow(s,2.0),0.50);
    
    y2 = (x2+T)/(1.0-x2*T);
    
    z2 = 1.0-(1.0/M_PI)*(atan(f+y2) - atan(f+x2));
    
    fprintf(fp,"%lf %lf %lf \n", t,z1,z2);
    
  }
  
}

