import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits.mplot3d import axes3d, Axes3D

proyectil45 = np.genfromtxt('datos45.txt')

plt.figure()
plt.plot(proyectil45[:,1], proyectil45[:,2])
plt.xlabel('Trayectoria (m)')
plt.ylabel('Altura (m)')
plt.savefig('proyectil45.pdf')


datosproyectiles = np.genfromtxt('datosangulos.txt')
corte = np.where(datosproyectiles[:,0]==0)

plt.figure()

for i in range(6):
    plt.plot(datosproyectiles[corte[0][i]:corte[0][i+1],1], datosproyectiles[corte[0][i]:corte[0][i+1],2],label = '%d°'%((i+1)*10))
i = 6;
plt.plot(datosproyectiles[corte[0][i]:,1], datosproyectiles[corte[0][i]:,2],label = '%d°'%((i+1)*10))
plt.xlabel('Trayectoria (m)')
plt.ylabel('Altura (m)')
plt.savefig('proyectilangulos.pdf')
plt.legend()

nombrespromedio = ['promediofija', 'promediolibre', 'promedioperiodica']
nombresplacas   = ['placafija'   , 'placalibre'   , 'placaperiodica'   ]
estados         = ['inicial', 'intermedio1', 'intermedio2', 'final']
N = 50

for i in range(3):
    promedio = np.genfromtxt('%s.txt'%nombrespromedio[i])
    plt.figure()
    plt.plot(promedio[:,0],promedio[:,1])
    plt.xlabel('Tiempo (s)')
    plt.ylabel('Temperatura (°C)')
    plt.title(nombrespromedio[i])
    plt.savefig('%s.pdf'%nombrespromedio[i])

    x,y = np.meshgrid(np.linspace(1,0.5,N),np.linspace(1,0.5,N))
    datosplaca = np.genfromtxt('%s.txt'%nombresplacas[i])
    for j in range(4):
        
        z = datosplaca[j*N:(j+1)*N,:]
        fig = plt.figure()
        ax = Axes3D(fig) #<-- Note the difference from your original code...
        ax.plot_surface(x, y, z, cmap='hot' )
        #ax.set_zlim(10, 100)
        plt.title('%s %s'%(nombresplacas[i],estados[j]))
        plt.savefig('%s%s.pdf'%(nombresplacas[i],estados[j]))


