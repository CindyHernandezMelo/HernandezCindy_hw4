import numpy as np
import matplotlib.pylab as plt

proyectil45 = np.genfromtxt('datos45.txt')

plt.figure()
plt.scatter(proyectil45[:,1], proyectil45[:,2])

plt.show()
