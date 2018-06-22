#include <stdio.h>
#include <math.h>


double f(double k,double d, double t0){
  return  0.50 - 2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*(-M_PI+atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(0.50-t0))));
}

double g(double k,double d, double t0){
  return 1.0 +  2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*( - atan(((d+k)/(d-k))*tan(0.250*pow(pow(d,2.0)-pow(k,2.0),0.50)+atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(0.50-t0))))));
}

double h(double k, double d, double t0){
    return tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(0.50-t0));
}



int main(void){
  
  double dt0 = 1.0/100.0;
  int maxt0=50;
  
  FILE *fp;
  
  int i,j; 
  
  double t0;
  
  double k=M_PI*0.50;
  
  double d=2*M_PI+M_PI;
  
  double t1 = 0.50 - 2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*asin(pow((d + k)/(2.0*d),0.50));
  
  double	t2 = 0.50 - 2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*asin(-pow((d + k)/(2.0*d),0.50)+M_PI/2.0);
  
  fp = fopen("suntk.txt","w");
  
  
  for(i=0; i<=50;i++){
    
    t0=i*dt0;
    
    
    fprintf(fp, "%lf %lf %lf %lf %lf %lf %lf %lf\n",t0,t2,f(k,d,t0) - t0,g(k,d,t0) - t0,f(k,d,t1) - t1,g(k,d,t1) - t1,f(k,d,t2) - t2,g(k,d,t2) - t2);
    
  }
  
}
