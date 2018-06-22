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
  
  
  
  p=0.650;
  
  
  a=1.30;
  
  FILE *fp;
  
  l=2.0;
  
  char filename[100];
  
  sprintf(filename,"tp%lfsuna%lfl%lf.txt",p,a,l);
  
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
    
    if(sin(xa)*sin(xa0)<=0.0){
      
      
      T3=T2;
      
      T2=T1;
      
      T1=T0;
      
      T0=T;
      
      T=step*dt;
      
      if(T>20.0){
	
	fprintf(fp,"%lf %lf %lf %lf %lf\n",l ,step*dt, T, T-T1,T+T3-2*T1);
	
      }
      
    }
    
  }
  
 }



