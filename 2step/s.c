#include <stdio.h>

#include <math.h>

int main(void){
  
  int i, j ; 
  
  int maxi = 100;
  
  double t1, T1, s1, x1, y1, z1;
  
  double f, k;
  
  double d=M_PI/2.0;
  
  FILE *fp;
  
  fp = fopen("selfmax.txt","w");
  
  for( i=0; i<=maxi; i++){
    
    t1 = 1.0/1.250;
    
    k = d*i/maxi;
    
    f = k/d;
    
    for( j=0; j<=50; j++){
      
      T1 = tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.5)*t1);
      
      s1 = (k/d + 2.0*T1)/(k*T1/d - 2.0);
      
      x1 = s1+pow(1.0+pow(s1,2.0),0.50);
      
      y1 = (x1+T1)/(1-x1*T1);
      
      z1 = 1.0-(1.0/M_PI)*(atan(f+y1) - atan(f+x1));
      
      t1 = z1; 
      
    }
    
    fprintf(fp,"%lf %lf %lf \n",d,k,t1);
    
  }
  
}

int main(void){	
  
  int p, q; 
  
  int maxp = 100;
  
  double t2, T2, s2, x2, y2, z2;
  
  double f, k;
  
  double d=M_PI/2.0;
  
  FILE *fp;
  
  fp = fopen("selfmin.txt","w");
  
  for( p=0; p<=maxp; p++){
    
    t2 = 1.0/1.250;		
    
    k = d*p/maxp;
    
    f = k/d;
    
    for( q=0; q<=50; q++){
      
      T2 = tan(0.50*pow(pow(d,2.0)-pow(k,2.0),0.5)*t1);
      
      s2 = (k/d + 2.0*T2)/(k*T2/d - 2.0);
      
      x2 = s2+pow(1.0+pow(s2,2.0),0.50);
      
      y2 = (x2+T2)/(1-x2*T2);
      
      z2 = 1.0-(1.0/M_PI)*(atan(f+y2) - atan(f+x2));
      
      t2 = z2; 
      
    }
    
    fprintf(fp,"%lf %lf %lf \n",d,k,t2);
    
  }
  
  
  
}




