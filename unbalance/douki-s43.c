
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
  double T[30];
  
  
  int i,j, k,m;
  double l;
  double xa, xa0, va, va0, vex0, xex0, xex, vex; 
  double kxa1, kxa2, kxa3, kxa4, t;
  
  for(j=0;j<20;j++){
    
    p=0.50+0.0250*j;
    
    FILE *fp;
    
    char filename[100];
    
    sprintf(filename,"statw1.3p%lf.txt",p);
    
    fp = fopen(filename,"w");
    
    
    
    for(m=0;m<10;m++){
      
      l=-0.60*(M_PI)-0.010*m;
      
      i=0;
      
      for(k=0;k<30;k++){
	
	T[k]=0;
	
      }
      
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
	
	va0  =   (xa - xa0 )/dt;
	
	vex0 =   (xex - xex0)/dt;
	
	if(sin(xa0 - xex0)*sin(xa-xex)<0){
	  
	  T[i]=step*dt;
	  
	  if(i>1 && T[i]-T[i-1]>1.0){
	    
	    fprintf(fp,"%lf %lf %lf %lf\n", step*dt,sin(xa-xex),l,T[i]-T[i-1]);
	    
	  }
	  
	  if(i>6){
	    
	    break;
	    
	  }
	  
	  i++;
	  
	}
	
      }
      
    }
    
  }
  
}
