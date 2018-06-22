#include <stdio.h>
#include <math.h>

#define dt 5.0/86400
#define maxstep 300000
#define k -50.0

double fv(x,xex){
  return  k * sin(x - xex);
    }



int main(void){
FILE *fp;
  int step;
  double x , xex, v, x1, x2, x3, x4, v1, v2, v3, v4;

 
 fp = fopen("douki-1.txt","w");



 x =  0.166 *2*M_PI;
 v = 0.6*2*M_PI;


  for(step=0; step<maxstep; step++){
  
    xex = fmod(2*M_PI * step * dt,2*M_PI);
    
     

    fprintf(fp,"%lf %lf %lf %lf %lf\n", step*dt,sin(xex),sin(x),x,xex);

    x1 =   v*dt;
    v1 =   fv(x,xex)*dt;
    x2 =  (v + v1/2)*dt;
    v2 =   fv(x+x1/2,xex)*dt;
    x3 =  (v + v2/2)*dt;
    v3 =   fv(x+x2/2,xex)*dt;
    x4 =  (v + v3)*dt;
    v4 =   fv(x+x3,xex)*dt;

    x = fmod(x + (x1 + 2*x2 + 2*x3 + x4)/6,2*M_PI);
    v = v + (v1 + 2*v2 + 2*v3 + v4)/6;
  
  }

}
