Resultados_hw4.pdf: proyectil45.png proyectilangulos.png promediofija.png promediolibre.png promedioperiodica.png placafijainicial.png placafijaintermedio1.png placafijaintermedio2.png placafijafinal.png placalibreinicial.png placalibreintermedio1.png placalibreintermedio2.png placalibrefinal.png placaperiodicainicial.png placaperiodicaintermedio1.png placaperiodicaintermedio2.png placaperiodicafinal.png Resultados_hw4.tex animaciones.py
	pdflatex Resultados_hw4.tex
	python animaciones.py 
	rm *.png
	rm *.txt


proyectil45.png proyectilangulos.png promediofija.png promediolibre.png promedioperiodica.png placafijainicial.png placafijaintermedio1.png placafijaintermedio2.png placafijafinal.png placalibreinicial.png placalibreintermedio1.png placalibreintermedio2.png placalibrefinal.png placaperiodicainicial.png placaperiodicaintermedio1.png placaperiodicaintermedio2.png placaperiodicafinal.png: Plots_hw4.py datos45.txt datosangulos.txt promediofija.txt placafija.txt todaplacafija.txt promediolibre.txt placalibre.txt todaplacalibre.txt promedioperiodica.txt placaperiodica.txt todaplacaperiodica.txt 
	python Plots_hw4.py
	

datos45.txt datosangulos.txt: ODE.cpp
	g++ ODE.cpp
	./a.out
	rm a.out

promediofija.txt placafija.txt todaplacafija.txt promediolibre.txt placalibre.txt todaplacalibre.txt promedioperiodica.txt placaperiodica.txt todaplacaperiodica.txt: PDE.cpp
	g++ PDE.cpp
	./a.out
	rm a.out




