#include <stdio.h>
#include <math.h>


int main(void){
  

  double fxa(double l,double xa,double xex){
    return  -1.0*  l *sin(xa - xex);
    
  }
  
  
  double dt = 1.0/500.0;
  int maxstep =25000;
  
  int step,k,i,j,m,n,q,r;
  double p,a,T,T0,T1,l,t, xa, xa0, va, va0, xex, kxa1, kxa2, kxa3, kxa4,S;
  int A[1000];
  int SUM;
  
  
  p=0.50;
  
  for(r=16;r<=16;r++){
    
    a = r*1.0/24.0;
    
    FILE *fp;
    
    char filename[100];
    
    sprintf(filename,"0.02sunT%dsc.txt",r);
    
    fp = fopen(filename,"w");
    
    for(k=0; k<=1200; k++){
      
      l = k*0.010;
      
      xa =  M_PI*(2.0/3.0);
      va =  2.0*M_PI*(a);
      xex = 0.0;
      
      T=0.0;
      T0=0.0;
      T1=0.0;
      
      SUM = 0;
      
      for(n=0;n<=1000;n++){
	
	A[n]=0;
	
      }
      
      for(step=0; step<maxstep; step++){
	
	xa0 = xa;
	
	t=dt*step;
	
	if(fmod(t,1.0)<=p){
	  
	  xex  = M_PI/2.0;
	  
	}else{
	  
	  xex  =3.0* M_PI/2.0;
	  
	}
	
	kxa1 =   fxa(l,xa,xex)*dt;
	kxa2 =   fxa(l,xa + kxa1/2,xex)*dt;
	kxa3 =   fxa(l,xa + kxa2/2,xex)*dt;
	kxa4 =   fxa(l,xa + kxa3,xex)*dt;
	xa =    xa + (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6 + va*dt;
	
	if( (sin(xa)*sin(xa0)<=0.0)&&(step*dt>10.0) ){
	  
	  T1=T0;
	  
	  T0=T;
	  
	  T=step*dt;
	  
	  for(j=0;j<=100;j++){
	    
	    if((j*0.020 -0.010 <= T-T1) && (T-T1 < j*0.020+0.010)){
	      
	      A[j]++;	
	      
	      break;
	      
	    }
	    
	  }		  
	}
	
      }
      
      for(q=0;q<=100;q++){
	
	SUM +=  A[q];
	
      }
      
      for(m=0;m<=100;m++){
	
	S = (A[m]*1.0)/(SUM*1.0);
	
	if(S > 0){
	  
	  fprintf(fp,"%lf %lf %lf %lf\n", l , step*dt , m*0.020, S);
	}
      }
      
    }	  
  }
  
}
