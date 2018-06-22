#include <stdio.h>
#include <math.h>


int main(void){
  
  
  double fxa(double p,double t,double l,double xa,double xex){
    return  -1.0*  l *cos((xex/2.0)-M_PI/4.0)*(cos(M_PI*(1.0-p))-cos(M_PI*(1.0-p)+2*M_PI*t))* sin(xa - xex);
  }
  
  
  double dt = 1.0/1000.0;
  int maxstep =50000;
  
  int step,k,i,j;
  double p,a,T,T0,T1,l,t, xa, xa0, va, va0, xex, kx, kxa1, kxa2, kxa3, kxa4;
  
  for(i=30;i<=30;i++){
    
    p=0.010*i;
    
    for(j=3;j<=3;j++){
      
      a=1.0+0.10*j;
      
      FILE *fp;
      
      char filename[100];
      
      sprintf(filename,"p%lfrisa%lftoy.txt",p,a);
      
      fp = fopen(filename,"w");
      
      xa =  M_PI*(2.0/3.0);
      va =  2.0*M_PI*(a);
      xex = 0.0;
      
      for(k=0; k<=50; k++){
	
	T=0.0;
	T0=0.0;
	T1=0.0;
	
	l=0.10*k;
	
	for(step=0; step<maxstep; step++){
	  
	  xa0 = xa;
	  
	  t=dt*step;
	  
	  if(fmod(t,1.0)<=p){
	    
	    xex  = M_PI/2.0;
	    
	  }else{
	    
	    xex  =3.0* M_PI/2.0;
	    
	  }
	  
	  kxa1 =   fxa(p,t,l,xa,xex)*dt;
	  kxa2 =   fxa(p,t,l,xa + kxa1/2,xex)*dt;
	  kxa3 =   fxa(p,t,l,xa + kxa2/2,xex)*dt;
	  kxa4 =   fxa(p,t,l,xa + kxa3,xex)*dt;
	  kx =   (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6;
	  xa =    xa + kx + va*dt;
	  
	  
	  fprintf(fp,"%lf %lf %lf %lf %lf\n",l ,step*dt,kx,sin(xex),sin(xa));
	  
	}
	
      }
    }
  }
}
