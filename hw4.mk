proyectil45.pdf: datos45.txt Plots_hw4.py
	python Plots_hw4.py
datos45.txt: ODE.cpp
	g++ ODE.cpp
	./a.out

