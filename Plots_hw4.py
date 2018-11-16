import numpy as np
import matplotlib.pylab as plt

proyectil45 = np.genfromtxt('datos45.txt')

plt.figure()
plt.scatter(proyectil45[:,1], proyectil45[:,2])
plt.savefig('proyectil45.pdf')


datosproyectiles = np.genfromtxt('datosangulos.txt')
corte = np.where(datosproyectiles[:,0]==0)

plt.figure()
plt.plot(datosproyectiles[corte[0][0]:corte[0][1],1], datosproyectiles[corte[0][0]:corte[0][1],2],label = '10 grados')
plt.plot(datosproyectiles[corte[0][1]:corte[0][2],1], datosproyectiles[corte[0][1]:corte[0][2],2],label = '20 grados')
plt.plot(datosproyectiles[corte[0][2]:corte[0][3],1], datosproyectiles[corte[0][2]:corte[0][3],2],label = '30 grados')
plt.plot(datosproyectiles[corte[0][3]:corte[0][4],1], datosproyectiles[corte[0][3]:corte[0][4],2],label = '40 grados')
plt.plot(datosproyectiles[corte[0][4]:corte[0][5],1], datosproyectiles[corte[0][4]:corte[0][5],2],label = '50 grados')
plt.plot(datosproyectiles[corte[0][5]:corte[0][6],1], datosproyectiles[corte[0][5]:corte[0][6],2],label = '60 grados')
plt.plot(datosproyectiles[corte[0][6]:,1]           , datosproyectiles[corte[0][6]:,2]           ,label = '70 grados')

plt.legend()
plt.show()
