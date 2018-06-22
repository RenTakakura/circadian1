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

double g(double k,double d, double t0){
  return 1.0 +  2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*( - atan(((d-k)/(d+k))*tan(0.250*pow(pow(d,2.0)-pow(k,2.0),0.50)+atan(((d+k)/(d-k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(0.50-t0)))))) - 1.0;
}

double g1(double k,double d, double t0){
  return   0.50 + 2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*(M_PI - (atan(((d+k)/(d-k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(0.50-t0))))) -1.0;
}

double g2(double k,double d, double t0){
  return   0.50 + 2.0*pow(pow(d,2.0)-pow(k,2.0),-0.50)*( - (atan(((d+k)/(d-k))*tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*(0.50-t0))))) -1.0;
}



int main(void){
  
  
  FILE *fp;
  
  int i,j; 
  
  double t0;
  
 double k = 3.0;
 
 double d= (1.50)*2*M_PI;
 
 fp = fopen("map.txt","w");
 
 for(j=500; j >=0;j--){
   
   t0 = -0.50*j/500;  
   
   
   
   if(0.0<f2(k,d,t0) && f2(k,d,t0)<0.50){
     
     fprintf(fp, "%lf %lf %lf %lf %lf\n",k,d,t0,f2(k,d,t0)-1.0,f2(k,d,t0) - t0);
   }
   
   
   if(0.0<f1(k,d,t0) && f1(k,d,t0)<0.50){
     
     fprintf(fp, "%lf %lf %lf %lf %lf\n",k,d,t0,f1(k,d,t0)-1.0,f1(k,d,t0) - t0);
   }
   
   
   
   if(-0.50<f(k,d,t0) && f(k,d,t0)<0.00){
     
     fprintf(fp, "%lf %lf %lf %lf %lf\n",k,d,t0,f(k,d,t0),f(k,d,t0) +1.0 - t0);
     
   }
   
   
   
   
   
 }
 
 
 for(i=0; i<=500;i++){
   
   t0 = 0.50*i/500;  
   
   if(-0.50<g1(k,d,t0) && g1(k,d,t0)<0.00){
     
     fprintf(fp, "%lf %lf %lf %lf %lf\n",k,d,t0,g1(k,d,t0),g1(k,d,t0) + 1.0 - t0);
     
   } 
   
   if(-0.50<g2(k,d,t0) && g2(k,d,t0)<0.00){
     
     fprintf(fp, "%lf %lf %lf %lf %lf\n",k,d,t0,g2(k,d,t0),g2(k,d,t0) + 1.0 - t0);
   }
   
   
   if(0.00<g(k,d,t0) && g(k,d,t0)<0.50){
     
     fprintf(fp, "%lf %lf %lf %lf %lf\n",k,d,t0,g(k,d,t0),g(k,d,t0) + 1.0 - t0);
     
   }
   
 }
 
 
 
}

