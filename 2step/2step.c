//2step model
//phi output (for animation)

#include <stdio.h>
#include <math.h>

#define k     -M_PI

//def external force
double fxa(double xa,double xex){
  return    k * sin(xa - xex);
}

int main(void){
  
  //def variables
  int step, maxstep =25000;
  double t, xa, xa0, va, va0, xex, kxa1, kxa2, kxa3, kxa4,v,dt = 1.0/500.0;

  //open file  
  FILE *fp;
  fp = fopen("12sample_pi.dat","w");

  //def variables
  xa =  M_PI*(2.0/3.0);
  va =  2.0*M_PI*(12.0/24.0);
  xex = 0.0;

  //time development
  for(step=0; step<maxstep; step++){
    
    xa0 = xa;
    
    t=dt*step;
    
    if(fmod(t,1.0)<=0.5){
      
      xex  = M_PI/2.0;
      
    }else{
      
      xex  =3.0* M_PI/2.0;
      
    }


    //RungeKutta
    kxa1 =   fxa(xa,xex)*dt;
    kxa2 =   fxa(xa + kxa1/2,xex)*dt;
    kxa3 =   fxa(xa + kxa2/2,xex)*dt;
    kxa4 =   fxa(xa + kxa3,xex)*dt;
    v =   (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6 + va*dt;
    xa =    xa + v;
    
    
    
    fprintf(fp,"%lf %lf %lf %lf %lf %lf\n", step*dt,cos(xex),sin(xex),cos(xa),sin(xa),v/dt);
    
  }
  
}
