#include <stdio.h>
#include <math.h>

double f(double k,double d){
  return 0.250*pow(pow(d,2.0)-pow(k,2.0),0.50);
}

double g(double k,double d){
  return 2.0*atan(pow((d+k)/(d-k),0.50));
}


int main(void){
  
  
  
  int i; 
  
  double k;
  
  double T=32.0;
  
  double d= (T/24.0)*2*M_PI;
  
  FILE *fp;
  char filename[100];
  sprintf(filename,"critical%lf.txt",T);
  
  fp = fopen(filename,"w");
  
  for(i=0; i <= 20;i++){
    
    k=3.08190+i*0.000010;  
    
    
    fprintf(fp, "%lf %lf %lf %lf %lf\n",k,d,f(k,d),g(k,d),g(k,d)-f(k,d));
    
    
  }
  
  
  
}
