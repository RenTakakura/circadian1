#include <stdio.h>
#include <math.h>



double f(double k,double d, double t0){
  return 0.50 +  2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*( - atan(((d+k)/(d-k))*tan(0.250*pow(pow(d,2.0)-pow(k,2.0),0.50)+atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0)))))) - 1.0;
}

double f0(double k,double d, double t0){
  return 0.50 +  2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*(M_PI - atan(((d+k)/(d-k))*tan(0.250*pow(pow(d,2.0)-pow(k,2.0),0.50)+atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0)))))) - 1.0;
}



double f1(double k,double d, double t0){
  return   2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*(M_PI - (atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0))))) ;
}

double f2(double k,double d, double t0){
  return   2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*( - (atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0))))) ;
}


int main(void){
  
  
  FILE *fp;
  
  int i,j; 
  
  double t0;
  
  double k = 2.0;
  
  double d= (1.30)*2*M_PI;
  
  fp = fopen("map1.txt","w");
  
  for(i=-500;i<=0;i++){
    
    t0 = i*0.5/500;  
    
    
    
    fprintf(fp, "%lf %lf %lf %lf %lf\n",k,d,t0,f1(k,d,t0),f2(k,d,t0));
    
    
    
  }
  
  
  
  
}
