#include <stdio.h>
#include <math.h>


int main(void){
  
  
  double fxa(double l,double xa,double xex){
    return  -1.0*  l *sin(xa - xex);
  }
  
  
  double dt = 1.0/1000.0;
  int maxstep =40000;
  
  int step,k,i,j;
  double p,a,T,T0,T1,T2,T3,l,t, xa, xa0, va, va0, xex, kxa1, kxa2, kxa3, kxa4;
  
  
  
  p=0.50;
  
  
  a=16.0/24.0;
  
  FILE *fp;
  
  for(j=0; j<=8; j++){
    
    l = 0.50*j;
    
    char filename[100];
    
    sprintf(filename,"gT16l%lf.txt",l);
    
    fp = fopen(filename,"w");
    
    xa =  M_PI*(2.0/3.0);
    va =  2.0*M_PI*(a);
    xex = 0.0;
    
    T=0.0;
    T0=0.0;
    T1=0.0;
    T2=0.0;
    T3=0.0;
    
    for(step=0; step<maxstep; step++){
      
      xa0 = xa;
      
      t=dt*step;
      
      if(fmod(t,1.0)<=p){
	
	xex  = M_PI/2.0;
	
      }else{
	
	xex  =3.0* M_PI/2.0;
	
      }
      
      kxa1 =   fxa(l,xa,xex)*dt;
      kxa2 =   fxa(l,xa + kxa1/2,xex)*dt;
      kxa3 =   fxa(l,xa + kxa2/2,xex)*dt;
      kxa4 =   fxa(l,xa + kxa3,xex)*dt;
      xa =    xa + (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6 + va*dt;
      
      
      
      fprintf(fp,"%lf %lf %lf %lf \n",l ,step*dt, sin(xa),sin(xex));
      
      
      
      
      
    }
    
  }
  
}
