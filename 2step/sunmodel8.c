#include <stdio.h>
#include <math.h>


int main(void){
  
  
  double fxa(double l,double xa,double xex){
    return  -1.0*  l *sin(xa - xex);
  }
  
  
  double dt = 1.0/500.0;
  int maxstep =40000;
  
  int step,k,i,j;
  double p,a,T,T0,T1,l,t, xa, xa0, va, va0, xex, kxa1, kxa2, kxa3, kxa4;
  
  
  
  p=0.50;
  
  for(j=1; j<=2;j++){
    
    a=0.10*j;
    
    FILE *fp;
    
    char filename[100];
    
    sprintf(filename,"doukia%lf.txt",a);
    
    fp = fopen(filename,"w");
    
    xa =  M_PI*(2.0/3.0);
    va =  2.0*M_PI*(a);
    xex = 0.0;
    
    for(k=0; k<=1000; k++){
      
      T=0.0;
      T0=0.0;
      T1=0.0;
      
      l=0.010*k;
      
      for(step=0; step<maxstep; step++){
	
	xa0 = xa;
	
	t=dt*step;
	
	xex  = 2*M_PI*dt*step;
	
	kxa1 =   fxa(l,xa,xex)*dt;
	kxa2 =   fxa(l,xa + kxa1/2,xex)*dt;
	kxa3 =   fxa(l,xa + kxa2/2,xex)*dt;
	kxa4 =   fxa(l,xa + kxa3,xex)*dt;
	xa =    xa + (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6 + va*dt;
	
	if(sin(xa)*sin(xa0)<=0.0){
	  
	  
	  
	  T1=T0;
	  
	  T0=T;
	  
	  T=step*dt;
	  
	  if(T>10.0){
	    
	    fprintf(fp,"%lf %lf %lf %lf\n",l ,step*dt, T, T-T1);
	    
	  }
	  
	}
	
      }
      
    }
    
  }
}
