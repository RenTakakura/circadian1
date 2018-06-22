

#include <stdio.h>

#include <math.h>

double fxa(double l,double xa,double xex){
  return    l * sin(xa - xex);
}
 

int main(void){
  
  double dt = 1.0/10000.0;
  int maxstep =100000;
  int maxi=600;
  int maxj=20;
  double p;  
  

  
  int i,j, step, cnt,cnt1;
  double l,ll, xa, xa0, va, va0, vex0, xex0, xex, vex, kxa1, kxa2, kxa3, kxa4, t;
  
  FILE *fp;
  char filename[100];
  
  fp = fopen("statw1.3.txt","w");
  
  xa =  M_PI*(1.0/3.0);
  va =  2.0*M_PI*(1.30);
  xex = 0.0;
  
  for(j=1; j<maxj; j++){
    
    p=0.50+0.0250*j;
    
    cnt1 = 0;
    
    for(i=1;  i<maxi; i++){
      
      l=-0.60*(M_PI)-0.00050*i;
      
      cnt =0;
      
      for(step=0; step<maxstep; step++){
	
	xa0 = xa;
	
	xex0 = xex;
	
	t=tan(M_PI*(1.0-p));
	
	xex=2*atan(1.0/sqrt(1.0+t*t)-sqrt(t*t/(1.0+t*t))/tan(M_PI*(dt*step-p)));
	
	
	kxa1 =   fxa(l,xa,xex)*dt;
	kxa2 =   fxa(l,xa + kxa1/2,xex)*dt;
	kxa3 =   fxa(l,xa + kxa2/2,xex)*dt;
	kxa4 =   fxa(l,xa + kxa3,xex)*dt;
	xa =    xa + (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6 + va*dt;
	
	va0  =   (xa - xa0 )/dt;
	
	vex0 =   (xex - xex0)/dt;
	
	if(step>2000){
	  
	  if(sin(xa-xex) < -1.0000+0.0050){
	    
	    ll=l;  
	    
	    cnt++;
	    
	    break;
	    
	  }            
	  
	}
	
	if(step>80000){
	  
	  if(cnt==0){
	    
	    cnt1++;
	    
	    break;
	    
	    
	  }
	  
	  
	}
	
      }
      if(cnt1>0){
	
	printf("%lf %lf\n",ll,p);
	
	break;
      }
      
    }
    
  }
}
