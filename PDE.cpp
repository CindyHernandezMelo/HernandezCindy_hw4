#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <fstream>

using namespace std;

int glob;
#define pi  3.14159
#define k   1.62 // m^2/s
#define cp  820  // 820J/(Kg*C)
#define rho 2710 // 2710 kg/m^3

int main(){
	double v  = k/(cp*rho);
	int    N  = 50;
	double d  = 10;
	double dx = 0.01;
	double dy = 0.01;
	double dt = 0.5*dx/v;
	cout << v << endl;
	cout << dt << endl;
	cout << dt*v/(pow(dx,2)) << endl;
	
	double pasado[N][N];
	double presente[N][N];
	double futuro[N][N];
	
	
	for(int x=0; x<N; x++){
		for(int y=0; y<N; y++){
			if((pow(x-N/2,2)+pow(y-N/2,2))<pow(d/2,2)){
				pasado[x][y] = 100;	
			}
			else {
				pasado[x][y] = 10;
			}
		}
	}
	
	// primer paso
	for(double t = 0; t<2000; t+=1){
		for(int x=1; x<N-1; x++){
			for(int y=1; y<N-1; y++){
				presente[x][y]   = pasado[x][y]+ v/(pow(dx,2))*(pasado[x+1][y]+pasado[x][y+1]-4*pasado[x][y]+pasado[x-1][y]+pasado[x][y+1]);		
				presente[0][y]   = 10;
				presente[50-1][y]= 10;
		}
			presente[x][0]   = 10;
			presente[x][50-1]= 10;		 
	}	
		for(int x=0; x<N; x++){
			for(int y=0; y<N; y++){
				pasado[x][y] = presente[x][y];	
				
				//cout<<pasado[x][y]<<","; 
		}
		//cout<<endl;
		 
	}
	cout<<endl;	
	}
		for(int x=0; x<N; x++){
			for(int y=0; y<N; y++){	
				
				cout<<pasado[x][y]<<","; 
		}
		cout<<endl;
		 
	}
	return 0;
}
