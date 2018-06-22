#include <stdio.h>
#include <math.h>

#define dt 5.0/86400
#define maxstep 150000
#define k 5

int main(void){
  FILE *fp;
  int step;
  double xp , xexp, vin, xin0, vin0, xin1, xin2, xin3, xin4, vin1, vin2, vin3, vin4;
  
  
  fp = fopen("douki-2.txt","w");
  
  
  
  xp =  M_PI/6;
  vin = (6/5)*2*M_PI;
  
  
  for(step=0; step<maxstep; step++){
    
    xexp = fmod(1.0 * step * dt * 2*M_PI,2*M_PI);
    
    
    
    fprintf(fp,"%lf %lf %lf %lf %lf\n", step*dt,xexp,xp,sin(xp),sin(xexp));
    
    xin1 =   vin*dt;
    vin1 =   k*sin(xp - xexp)*dt;
    xin2 =  (vin + vin1/2)*dt;
    vin2 =   k*sin(xp + xin1/2 - xexp)*dt;
    xin3 =  (vin + vin2/2)*dt;
    vin3 =   k*sin(xp + xin2/2 - xexp)*dt;
    xin4 =  (vin + vin3)*dt;
    vin4 =   k*sin(xp + xin3 - xexp)*dt;
    
    xp = fmod(xp + (xin1 + 2*xin2 + 2*xin3 + xin4)/6,2*M_PI);
    vin = vin + (vin1 + 2*vin2 + 2*vin3 + vin4)/6;
    
  }
}
