#include <stdio.h>
#include <math.h>

double p(double k,double d, double t0){
  
  return 1-pow(sin(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0)),2.0)*4*d*k/(pow(d+k,2.0));
  
}

double	q(double k,double d, double t0){
  return  1 + pow(sin(0.250*pow(pow(d,2.0)-pow(k,2.0),0.50)+atan(tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0))*(d-k)/(d+k))),2.0)*4*d*k/(pow(d-k,2.0));
}

double f(double k,double d, double t0){
  return   2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*(M_PI - (atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0)))));
}

double g(double k,double d, double t0){
  return 0.50 +  2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*( - atan(((d+k)/(d-k))*tan(0.250*pow(pow(d,2.0)-pow(k,2.0),0.50)+atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0))))));
}

int main(void){
  
  double dt0 = 1.0/1000.0;
  int maxt0=50;
  
  FILE *fp;
  
  int i,j; 
  
  double t0,t1,t2,t3,t4,t5,t6,t7;
  
  double k;
  
  double d= 2*M_PI*(20.0/24.0);
  
  double p0, q0;
  
  
  fp = fopen("suneq.txt","w");
  
  for(j=0; j <=500;j++){
    
    k= j*d/500;
    
    t1 =  - 2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*(asin(-pow(pow(d+k,2.0)/(4*d*k),0.50)));
    
    t2 =  - 2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*(asin(pow(pow(d+k,2.0)/(4*d*k),0.50)));
    
    t3 = -0.50;
    
    t4 = 0.0;
    
    t5 = - M_PI/(pow(pow(d,2.0)-pow(k,2.0),0.50));
    
    t7 = - 2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*atan(tan(-M_PI*0.50 - pow(pow(d,2.0)-pow(k,2.0),0.50)*0.25)*(d+k)/(d-k));
    
    
    
    
    for(i=0; i<=500;i++){
      
      
      t0= -1.0*i*dt0;
      
      if((p0*q0 - 1 )* (p(k,d,t0)*q(k,d,t0) - 1)<=0){
	
	t6 = t0 + dt0;
	
	
	fprintf(fp, "%lf %lf %lf %lf \n",k,t0,g(k,d,t0)-t0,f(k,d,t0) - t0);
	
      }
      
      p0 = p(k,d,t0);
      
      q0 = q(k,d,t0);    
      
      
      
    }
    
  }
  
}
