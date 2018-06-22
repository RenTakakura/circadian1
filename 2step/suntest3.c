#include <stdio.h>
#include <math.h>




double f(double k,double d, double t0){
  return 0.50 +  2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*( - atan(((d+k)/(d-k))*tan(0.250*pow(pow(d,2.0)-pow(k,2.0),0.50)+atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0)))))) ;
}

double f0(double k,double d, double t0){
  return 0.50 +  2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*(M_PI - atan(((d+k)/(d-k))*tan(0.250*pow(pow(d,2.0)-pow(k,2.0),0.50)+atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0)))))) ;
}



double f1(double k,double d, double t0){
  return   2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*(M_PI - (atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0))))) ;
}

double f2(double k,double d, double t0){
  return   2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*( - (atan(((d-k)/(d+k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(-t0))))) ;
}

double g(double k,double d, double t0){
  return 1.0 +  2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*( - atan(((d-k)/(d+k))*tan(0.250*pow(pow(d,2.0)-pow(k,2.0),0.50)+atan(((d+k)/(d-k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(0.50-t0)))))) ;
}

double g1(double k,double d, double t0){
  return   0.50 + 2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*(M_PI - (atan(((d+k)/(d-k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(0.50-t0)))));
}

double g2(double k,double d, double t0){
  return   0.50 + 2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*( - (atan(((d+k)/(d-k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(0.50-t0))))) ;
}





int main(void){
  
  
  FILE *fp;
  
  int i,j; 
  
  double t0,t1,T0,T1;
  
  double k = 4.00;
  
  double d= (1.50)*2*M_PI;
  
  fp = fopen("map2.txt","w");
  
  for(j=-500; j <=500;j++){
    
    t0 = 0.50*j*0.002;  
    
    if(t0<0.0){   
      
      if(0.0<f2(k,d,t0) && f2(k,d,t0)<0.50){
	
	t1 = f2(k,d,t0);
	
	T0 = f2(k,d,t0) - t0;
      }
      
      
      if(0.0<f1(k,d,t0) && f1(k,d,t0)<0.50){
	
	t1 = f1(k,d,t0);
	
	T0 = f1(k,d,t0) - t0;
      }
      
      
      
      if(0.50<f(k,d,t0) && f(k,d,t0)<1.00){
	
	t1 = f(k,d,t0) - 1.0;
	
	T0 = f(k,d,t0) - t0;
      }
      
    }else{
      
      
      if(0.50<g1(k,d,t0) && g1(k,d,t0)<1.00){
	
	t1 = g1(k,d,t0) - 1.0;
	
	T0 = g1(k,d,t0) - t0;
      }
      
      
      
      if(0.50<g2(k,d,t0) && g2(k,d,t0)<1.00){
	
	t1 = g2(k,d,t0) - 1.0;
	
	T0 = g2(k,d,t0) - t0;
      }
      
      
      if(1.00<g(k,d,t0) && g(k,d,t0)<1.50){
	
	t1 = g(k,d,t0) - 1.0;
	
	T0 = g(k,d,t0) - t0;
      }
      
    }
    
    
    if(t1<0.0){   
      
      if(0.0<f2(k,d,t1) && f2(k,d,t1)<0.50){
	
	T1 = f2(k,d,t1) - t1;
      }
      
      
      if(0.0<f1(k,d,t1) && f1(k,d,t1)<0.50){
	
	T1 = f1(k,d,t1) - t1;
      }
      
      
      
      if(0.50<f(k,d,t1) && f(k,d,t1)<1.00){
	
	T1 = f(k,d,t1) - t1;
	
      }
      
    }else{
      
      
      if(0.50<g1(k,d,t1) && g1(k,d,t1)<1.00){
	
	T1 = g1(k,d,t1) - t1;
	
      }
      
      
      
      if(0.50<g2(k,d,t1) && g2(k,d,t1)<1.00){
	
	T1 = g2(k,d,t1) - t1;
      }
      
      
      if(1.00<g(k,d,t1) && g(k,d,t1)<1.50){
	
	T1 = g(k,d,t1) - t1;
	
      }
      
    }
    
    fprintf(fp, "%lf  %lf %lf %lf %lf %lf\n",k,d,t0,t1,T0,T1);
  }
  
}

