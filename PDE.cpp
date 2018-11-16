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
	double dx = 1/100;
	double dy = 1/100;
	double dt = 0.5*dx/v;
	cout << v << endl;
	cout << dt << endl;
	
	double R0[N][N];
	
	for(int x=0; x<N; x++){
		for(int y=0; y<N; y++){
			if((pow(x-N/2,2)+pow(y-N/2,2))<25){
				R0[x][y] = 100;	
			}
			else {
				R0[x][y] = 10;
			}
			//cout<<R0[x][y]<<" "; 
		}
		//cout<<endl; 
	}
	return 0;
}
