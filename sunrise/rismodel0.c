#include <stdio.h>
#include <math.h>


int main(void){
  
  
  double fxa(double p,double t,double l,double xa,double xex){
    return  -1.0*  l *cos((xex/2.0)-M_PI/4.0)*(cos(M_PI*(1.0-p))-cos(M_PI*(1.0-p)+2*M_PI*t));
  }
  
  
  double fxb(double l,double xa,double xex){
    return  -1.0*  l *cos((xex/2.0)-M_PI/4.0);
  }
  
  double dt = 1.0/1000.0;
  int maxstep =50000;
  
  int step,k,i,j;
  double p,a,T,T0,T1,l,t, xa, xa0, va, va0, xex, kx, kxa, kxb, kxa3, kxa4;
  
  
  p=0.60;
  
  FILE *fp;
  
  
  fp = fopen("toy.txt","w");
  
  l=5.0;
  
  for(step=0; step<maxstep; step++){
    
    xa0 = xa;
    
    t=dt*step;
    
    if(fmod(t,1.0)<=p){
      
      xex  = M_PI/2.0;
      
    }else{
      
      xex  =3.0* M_PI/2.0;
      
    }
    
    kxa =   fxa(p,t,l,xa,xex);
    kxb =   fxb(l,xa,xex); 
    
    fprintf(fp,"%lf %lf %lf %lf %lf\n",step*dt,kxa,kxb,xex,xa);
    
  }
  
}


