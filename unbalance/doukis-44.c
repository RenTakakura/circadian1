    
#include <stdio.h>

#include <math.h>

double fxa(double l,double xa,double xex){
  
  return    l * sin(xa - xex);
  
}


int main(void){
  
  double dt = 1.0/1000.0;
  int maxstep =50000;
  int step;
  int maxi=600;
  int maxj=20;
  double p;  
  
  
  int j,m;
  double l;
  double xa, xa0, va, xex0, xex, v; 
  double kxa1, kxa2, kxa3, kxa4, t;
  
  for(m=0;m<10;m++){
    
    l=-0.60*(M_PI)-0.010*m;

    
    for(j=0;j<20;j++){
      
      p=0.50+0.0250*j;
      
      FILE *fp;
      
      char filename[100];
      
      sprintf(filename,"gw1.3p%lfl%lf.txt",p,l);
      
      fp = fopen(filename,"w");
      
      xa =  M_PI*(1.0/3.0);
      
      va =  2.0*M_PI*(1.30);
      
      xex = 0.0;
      
      for(step=0; step<maxstep; step++){
	
	xa0 = xa;
	
	xex0 = xex;
	
	t=tan(M_PI*(1.0-p));
	
	xex=2*atan(1.0/sqrt(1.0+t*t)-sqrt(t*t/(1.0+t*t))/tan(M_PI*(dt*step-p)));
	
	kxa1 =   fxa(l,xa,xex)*dt;
	
	kxa2 =   fxa(l,xa + kxa1/2,xex)*dt;
	
	kxa3 =   fxa(l,xa + kxa2/2,xex)*dt;
	
	kxa4 =   fxa(l,xa + kxa3,xex)*dt;
	
	xa =    xa + (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6 + va*dt;
	
	v =   ((xa-xex)-(xa0 - xex0))/dt;
        
	fprintf(fp,"%lf %lf %lf \n", step*dt,sin(xa-xex),v);
	
	
      }
      
    }
    
  }
  
}
