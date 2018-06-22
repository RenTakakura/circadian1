
    
#include <stdio.h>

#include <math.h>

double fxa(double l,double xa,double xex){
  return    l * sin(xa - xex);
}


int main(void){
  
  
  double dt = 5.0/8640.0;
  double dl=0.50;
  int maxstep =160000;
  double k[9]={1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8};
  int i,j,m,n,q,flg;
  
for(i=0;i<9;i++){
  
  int step;
  double T, T0, l, xa, xa0, va, va0, xex, xex0, vex, kxa1, kxa2, kxa3, kxa4;
  
  FILE *fp;
  char filename[100];
  sprintf(filename,"w%lf",k[i]);
  fp = fopen(filename,"w");
  double TT[100];
  int cnt[100];
  
  for(q=0;q<100;q++){
    TT[q]=0.0;
    cnt[q]=0;
  }
  for(j=0;j<41;j++){
    
    m=0;
    
    l =  j*dl;
    
    xa =  M_PI*(1.0/3.0);
    va =  2.0*M_PI*k[i];
    xex = 0.0;
    
    for(step=0; step<maxstep; step++){
      
      xa0 = xa;
      
      kxa1 =   fxa(l,xa,xex)*dt;
      kxa2 =   fxa(l,xa + kxa1/2,xex)*dt;
      kxa3 =   fxa(l,xa + kxa2/2,xex)*dt;
      kxa4 =   fxa(l,xa + kxa3,xex)*dt;
      xa =    xa + (kxa1 + 2*kxa2 + 2*kxa3 + kxa4)/6 + va*dt;
      
      va0 =   (xa - xa0 )/dt;
      
      xex0 =   (2.0*M_PI*dt* (1 - sin(xex)*0.50))*1.1550;
      
      
      if(sin(xa)*sin(xa0)< 0.0){
	
	T0 = T;
	
	T = step*dt;
      }
      
      fprintf(fp, "%lf %lf\n" ,l,T-T0);
      
      flg=0;
      
      for(n=0;n<=m;n++){
	
	if(fabs((T-T0)-TT[n])<0.0000050){
	  
	  flg=1;
	  cnt[n]++;
	  
	  break;
	}
      }
      
      if(flg=0){
	
	TT[++m]=T-T0;
	
      }
      
      xex = xex + xex0;
      
    }
    
    for(q=0;q<=m;q++){
      TT[q]=0.0;
      cnt[q]=0;
    }
  }
 }
}
