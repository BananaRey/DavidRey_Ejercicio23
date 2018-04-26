#include <iostream>
#include <cstdlib>
#include <stdio.h>    
#include <math.h> 
#define _USE_MATH_DEFINES

using namespace std;

double x_en_t0(double x,double y);

int main(){
//se hacen las constantes
 double C=0.1;
 double T=10;
 double Delta_x=0.01;
 double Delta_t=0.0001;


 double t=0;
 double intervalo = M_PI;
 int n_x= (intervalo/Delta_x)+1;
 int n_t= (T/Delta_t)+1;

//las cinco contenedoras
double *u_0;
 u_0= new double[n_x];

double *u_1;
 u_1= new double[n_x];

double *u_2;
 u_2= new double[n_x];

double *u_3;
 u_3= new double[n_x];

double *u_4;
 u_4= new double[n_x];
 
 double *u_j1;
 u_j1= new double[n_x]; 
 
 double *u_j2;
 u_j2= new double[n_x]; 
 
 double *u_j3;
 u_j3= new double[n_x]; 


//se hace la condicion inicial
 for(int i=0;i<n_x;i++){
 u_j1[i]=sin(2*((i*Delta_x)-(M_PI/2)));
 u_j2[i]=sin(2*((i*Delta_x)-(M_PI/2)));
 u_0[i]=sin(2*((i*Delta_x)-(M_PI/2)));
 }
// se evoluciona
 for(int n=1;n<n_t;n++){
  for(int i=1;i<n_x;i++){
   u_j3[i]=((C*Delta_t*Delta_t)/(Delta_x*Delta_x))*(u_j2[i+1]-2*u_j2[i]+u_j2[i-1])+2*u_j2[i]-u_j1[i];	
        if(n==(int)n_t/5){
	 u_1[i]=u_j3[i];	
         }
         if(n==((int)n_t*(2/5))){
	 u_2[i]=u_j3[i];	
         }
         if(n==(int)n_t*(3/5)){
	 u_3[i]=u_j3[i];	
         }
         if(n==(int)n_t*(4/5)){
	 u_4[i]=u_j3[i];	
         }

     }
//se actualiza
    for(int k=0;k<n_x;k++){
   u_j1[k]=u_j2[k];
   u_j2[k]=u_j3[k];               
   }
  }
//se imprime
 for(int i=0;i<n_x;i++){ 
cout<<i*Delta_x-(M_PI/2)<<" "<<u_0[i]<<" "<<u_1[i]<<" "<<u_2[i]<<" "<<u_3[i]<<" "<<u_4[i]<<" "<<u_j3[i]<<endl;

 }
 
return(0);
}
//funcion en t=0
double x_en_t0(double x,double y){
 if((-0.5)<=x and x<=0.5){
  return(0.5);
   }
  else{
   return(0);
   } 
}
