#include <stdio.h>

#include <math.h>

int main(void){
  
  int i, j ; 
  
  int maxi = 100;
  
  double t1, T1, s1, x1, y1, z1;
  
  double f, k;
  
  double d=M_PI;
  
  FILE *fp;
  
  fp = fopen("selfmin.txt","w");
  
  for( i=0; i<=maxi; i++){
    
    t1 = 1.0/1.50;
    
    k = d*i/maxi;
    
    f = k/d;
    
    for( j=0; j<=50; j++){
      
      T1 = tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.50)*t1);
      
      
      x1 = (1/(f*T1-pow(1-pow(f,2.0),0.50)))*(f + T1*pow(1-pow(f,2.0),0.50)+pow(pow(T1,2.0)+1,0.50));
      
      
      
      y1 = (x1+T1)/(1-x1*T1);
      
      
      t1 = 1.0-(1.0/M_PI)*(atan(f+pow(1.0-pow(k/d,2.0),0.50)*y1) - atan(f+pow(1-pow(k/d,2.0),0.50)*x1));
      
      if(t1>1.0){
	
	t1 = t1 -1.0;
	
      }
      
      
    }		
    
    fprintf(fp,"%lf %lf %lf %lf %lf %lf\n",d,k,T1,x1,t1,y1);
    
    
    
  }
  
}

