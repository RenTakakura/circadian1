#include <stdio.h>
#include <math.h>


double f(double k,double d,double t, double x){
  return  1-(1/M_PI)*(atan(k/d + pow(1-pow(k/d,2.0),0.50)*tan(t+(0.5)*pow(pow(d,2.0)-pow(k,2.0),0.5)*x))-atan(k/d+pow(1-pow(k/d,2.0),0.50)*tan(t)))
    ;
}




int main(void){
  
  
  double dt = 1.0/100.0;
  int maxt =100;
  
  double dx = 1.0/100.0;
  int maxx=100;
  
  FILE *fp;
  
  int i,j; 
  
  double t;
  
  double x;
  
  double k=M_PI*0.10;
  
  double d=M_PI;
  
  
  char filename[100];
  
  sprintf(filename,"tk%lfd%lf.txt",k,d);
  
  fp = fopen("tk.txt","w");
  
  
  for(i=0; i<=100;i++){
    
    t=M_PI*i*dt;
    
    for(j=0; j<=100; j++){
      
      x=j*dx;
      
      fprintf(fp,"%lf %lf %lf %lf\n", t,x,f(k,d,t,x));
      
    }
    
  }
  
}
