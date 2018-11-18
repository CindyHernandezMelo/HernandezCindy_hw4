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
	double dx = 50*0.01/N;
	double dy = 50*0.01/N;
	double dt = 0.001*dx/v;
	cout << v << endl;
	cout << dt << endl;
	cout << dt*v/(pow(dx,2)) << endl;
	cout << dx << endl;

	double pasado[N][N];
	double presente[N][N];
	double futuro[N][N];
	int pixeles_placa = 0;

	for(int x=0; x<N; x++){
		for(int y=0; y<N; y++){
			if((pow(x-N/2,2)+pow(y-N/2,2))<pow(N/d,2)){
				pasado[x][y] = 100;
			}
			else {
				pasado[x][y] = 10;
				pixeles_placa ++;
			}
		//	cout<< pasado[x][y]<<" ";
		}
		//cout<< endl;
	}

	// primer paso
	int contador = 0;
	double diferencia = 1;
	ofstream promediofija("promediofija.txt");
	ofstream placafija("placafija.txt");
	while(abs(diferencia)>pow(10,-3)){
		for(int x=0; x<N; x++){
			for(int y=0; y<N; y++){
				if((pow(x-N/2,2)+pow(y-N/2,2))<pow(d/2,2)){
					presente[x][y] = 100;
				}
				else if (x>0 && y>0) {
					presente[x][y] =pasado[x][y]+ dt*v/(pow(dx,2))*(pasado[x+1][y]+pasado[x][y+1]-4*pasado[x][y]+pasado[x-1][y]+pasado[x][y-1]);
				}
				presente[ 0][y] = 10;
				presente[N-1][y] = 10;
			}
			presente[x][ 0] = 10;
			presente[x][N-1] = 10;
		}
		double promedio_pasado =0;
		double promedio_presente=0;
		for(int x=0; x<N; x++){
			for(int y=0; y<N; y++){
				promedio_pasado += pasado[x][y]/pixeles_placa;
				promedio_presente += presente[x][y]/pixeles_placa;
						if(contador == 0 ||contador==646 || contador==1293|| contador ==1939){
							placafija << pasado[x][y] << " ";
						}

				pasado[x][y] = presente[x][y];
			}
			if(contador == 0 ||contador==646 || contador==1293|| contador ==1939){
					placafija << endl;;
			}

		}
		diferencia = promedio_pasado - promedio_presente;
		promediofija << dt*contador<<" " <<promedio_pasado <<endl;
		contador ++;
	}

		pixeles_placa = 0;

		for(int x=0; x<N; x++){
			for(int y=0; y<N; y++){
				if((pow(x-N/2,2)+pow(y-N/2,2))<pow(N/d,2)){
					pasado[x][y] = 100;
				}
				else {
					pasado[x][y] = 10;
					pixeles_placa ++;
				}
			//	cout<< pasado[x][y]<<" ";
			}
			//cout<< endl;
		}

		// primer paso
		contador = 0;
		diferencia = 1;
		ofstream promediolibre("promediolibre.txt");
		ofstream placalibre("placalibre.txt");
		while(abs(diferencia)>pow(10,-3)){
			for(int x=0; x<N; x++){
				for(int y=0; y<N; y++){
					if((pow(x-N/2,2)+pow(y-N/2,2))<pow(d/2,2)){
						presente[x][y] = 100;
					}
					else if (x>0 && y>0) {
						presente[x][y] =pasado[x][y]+ dt*v/(pow(dx,2))*(pasado[x+1][y]+pasado[x][y+1]-4*pasado[x][y]+pasado[x-1][y]+pasado[x][y-1]);
					}
					presente[ 0][y] = presente[ 1][y];
					presente[N-1][y] = presente[N-2][y];
				}
				presente[x][ 0] = presente[x][ 1];
				presente[x][N-1] = presente[x][N-2];
			}
			double promedio_pasado =0;
			double promedio_presente=0;
			for(int x=0; x<N; x++){
				for(int y=0; y<N; y++){
					promedio_pasado += pasado[x][y]/pixeles_placa;
					promedio_presente += presente[x][y]/pixeles_placa;
							if(contador == 0 ||contador==4444 || contador==8890|| contador ==13334){
								placalibre << pasado[x][y] << " ";
							}

					pasado[x][y] = presente[x][y];
				}
				if(contador == 0 ||contador==4444 || contador==8890|| contador ==13334){
						placalibre << endl;;
				}
			}
			diferencia = promedio_pasado - promedio_presente;
			promediolibre << dt*contador<<" " <<promedio_pasado <<endl;
			contador ++;
		}


				pixeles_placa = 0;

				for(int x=0; x<N; x++){
					for(int y=0; y<N; y++){
						if((pow(x-N/2,2)+pow(y-N/2,2))<pow(N/d,2)){
							pasado[x][y] = 100;
						}
						else {
							pasado[x][y] = 10;
							pixeles_placa ++;
						}
					//	cout<< pasado[x][y]<<" ";
					}
					//cout<< endl;
				}
				// primer paso
				contador = 0;
				diferencia = 1;
				ofstream promedioperiodica("promedioperiodica.txt");
				ofstream placaperiodica("placaperiodica.txt");
				while(abs(diferencia)>pow(10,-3)){
					for(int x=0; x<N; x++){
						for(int y=0; y<N; y++){
							if((pow(x-N/2,2)+pow(y-N/2,2))<pow(d/2,2)){
								presente[x][y] = 100;
							}
							else if (x>0 && y>0) {
								presente[x][y] =pasado[x][y]+ dt*v/(pow(dx,2))*(pasado[x+1][y]+pasado[x][y+1]-4*pasado[x][y]+pasado[x-1][y]+pasado[x][y-1]);
							}
							presente[ 0][y] = presente[N-3][y];
							presente[N-1][y] = presente[2][y];
						}
						presente[x][ 0] = presente[x][N-3];
						presente[x][N-1] = presente[x][2	];
					}
					double promedio_pasado =0;
					double promedio_presente=0;
					for(int x=0; x<N; x++){
						for(int y=0; y<N; y++){
							promedio_pasado += pasado[x][y]/pixeles_placa;
							promedio_presente += presente[x][y]/pixeles_placa;
									if(contador == 0 ||contador==4254 || contador==8568|| contador ==12852){
										placaperiodica << pasado[x][y] << " ";
									}

							pasado[x][y] = presente[x][y];
						}
						if(contador == 0 ||contador==4254 || contador==8568|| contador ==12852){
								placaperiodica << endl;;
						}
					}
					diferencia = promedio_pasado - promedio_presente;
					promedioperiodica << dt*contador<<" " <<promedio_pasado <<endl;
					contador ++;
				}


	return 0;
}
