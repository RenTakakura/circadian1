#include <stdio.h>
#include <math.h>

double fxa(double l,double xa,double xex){
  return    l * sin(xa - xex);
}




int main(void){
  
  
  double dt = 5.0/8640.0;
  int maxstep =160000;
  double k[9]={1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8};
  int i;
  for(i=0;i<9;i++){
    2, kxa3, kxa4;
    
    
    FILE *fp;
    char filename[100];
    sprintf(filename,"w%lf.text",k[i]);
    fp = fopen(filename,"w");
    
    
    xa =  M_PI*(1.0/3.0);
    va =  2.0*M_PI*k[i];
    xex = 0.0;
    int step;
    double xa, xa0, va, va0, xex, xex0, vex, kxa1, kxa
      
      
      
      for(step=0; step<maxstep; step++){
	
	xa0 = xa;
	
	kxa1 =   fxa(xa,xex)*dt;
	kxa2 =   fxa(xa + kxa1/2,xex)*dt;
	kxa3 =   fxa(xa + kxa2/2,xex)*dt;
	kxa4 =   fxa(xa + kxa3,xex)*dt;
	xa =    xa + (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6 + va*dt;
	
	va0 =   (xa - xa0 )/dt;
	
	xex0 =   (2.0*M_PI*dt* (1 - sin(xex)*0.50))*1.1550;
	
	vex =   xex0/dt; 
	
	fprintf(fp,"%lf %lf %lf %lf %lf %lf\n", step*dt,sin(xex),sin(xa),va0,vex,va0-vex);
	
	xex = xex + xex0;
	
      }
    
  }
}
