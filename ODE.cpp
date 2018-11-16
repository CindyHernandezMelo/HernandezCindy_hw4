#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <fstream>

using namespace std;



int glob;
#define pi 3.14159
#define g 10
#define c 0.2
#define m 0.2

double dxdt(double t, double x, double xprima);
double dydt(double t, double y, double yprima);

double d2xdt2(double t, double x, double xprima);
double d2ydt2(double t, double y, double yprima);

double dxdt(double t, double x, double xprima){
	return xprima;
}

double dydt(double t, double y, double yprima){
	return yprima;
}

double d2xdt2(double t, double x, double xprima, double yprima, double a){
	return    -c*pow(pow(xprima,2)+pow(yprima,2),0.5)*cos(a*pi/180)/m;
}

double d2ydt2(double t, double y, double xprima, double yprima, double a){
	return -g -c*pow(pow(xprima,2)+pow(yprima,2),0.5)*sin(a*pi/180)/m;
	
}


int main(){
	
	double angulo = 45;
	double h = 0.1;

	double t  = 0;
	double x  = 0;
	double y  = 0;
	double vx = 300*cos(45*pi/180);
	double vy = 300*sin(45*pi/180);
	
	double kx1, ky1, kdx1, kdy1;
	double kx2, ky2, kdx2, kdy2;
	double kx3, ky3, kdx3, kdy3;
	double kx4, ky4, kdx4, kdy4;
	
	ofstream outfile("compare.txt");
	while(t<10){
		
		kx1  =   dxdt(t,x,vx);
		ky1  =   dydt(t,x,vy);
		kdx1 = d2xdt2(t,x,vx,vy,angulo);
		kdy1 = d2ydt2(t,y,vx,vy,angulo);
		
		kx2  =   dxdt(t+h*0.5, x+kx1*0.5, vx+kdx1*0.5);
		ky2  =   dydt(t+h*0.5, y+ky1*0.5, vy+kdy1*0.5);
		kdx2 = d2xdt2(t+h*0.5, x+kx1*0.5, vx+kdx1*0.5, vy+kdy1*0.5,angulo);
		kdy2 = d2ydt2(t+h*0.5, y+ky1*0.5, vx+kdx1*0.5, vy+kdy1*0.5,angulo);
		
		kx3  =   dxdt(t+h*0.5, x+kx2*0.5, vx+kdx2*0.5);
		ky3  =   dydt(t+h*0.5, y+ky2*0.5, vy+kdy2*0.5);
		kdx3 = d2xdt2(t+h*0.5, x+kx2*0.5, vx+kdx2*0.5, vy+kdy2*0.5,angulo);
		kdy3 = d2ydt2(t+h*0.5, y+ky2*0.5, vx+kdx2*0.5, vy+kdy2*0.5,angulo);
		
		kx4  =   dxdt(t+h, x+kx3, vx+kdx3);
		ky4  =   dydt(t+h, y+ky3, vy+kdy3);
		kdx4 = d2xdt2(t+h, x+kx3, vx+kdx3, vy+kdy3,angulo);
		kdy4 = d2ydt2(t+h, y+ky3, vx+kdx3, vy+kdy3,angulo);

		 t =  t + h ;
		 x =  x + ( kx1 +  2*kx2 +  2*kx3 +  kx4)/6.;
		 y =  y + ( ky1 +  2*ky2 +  2*ky3 +  ky4)/6.;
		vx = vx + (kdx1 + 2*kdx2 + 2*kdx3 + kdx4)/6.;
		vy = vy + (kdy1 + 2*kdy2 + 2*kdy3 + kdy4)/6.;
		
		
		
		outfile << t <<" " << x << " " << y << " " << vx << " " << vy <<endl;		
		cout << t <<" " << x << " " << y << " " << vx << " " << vy <<endl;		
				
	}
	outfile.close();
	return 0;
}
