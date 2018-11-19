import numpy as np
print('numpy: '+np.version.full_version)
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D 
import matplotlib.animation as animation
#############placa fija###################
data = np.genfromtxt('todaplacafija.txt')
fps = 20 # frame per sec
frn = int(data.shape[0]/50) # frame number of the animation

x = np.linspace(0,0.5,50)
x, y = np.meshgrid(x, x)
zarray = np.zeros((50, 50, frn))

for i in range(frn):
    zarray[:,:,i] = data[i*50:(i+1)*50,:]
    
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ims = []
for i in range(frn):
    sf = ax.plot_surface(x, y, zarray[:,:,i], cmap='hot' , rstride=1, cstride=1)
    ims.append([sf])

ax.set_zlim(0,100)
ani = animation.ArtistAnimation(fig, ims, interval=1000/fps, blit=True)
plt.show()
###########placa libre #################
data = np.genfromtxt('todaplacalibre.txt')

frn = int(data.shape[0]/50) # frame number of the animation

zarray = np.zeros((50, 50, frn))

for i in range(frn):
    zarray[:,:,i] = data[i*50:(i+1)*50,:]
    
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ims = []
for i in range(frn):
    sf = ax.plot_surface(x, y, zarray[:,:,i], cmap='hot' , rstride=1, cstride=1)
    ims.append([sf])

ax.set_zlim(0,100)
ani = animation.ArtistAnimation(fig, ims, interval=1000/fps, blit=True)
plt.show()

##################placa periodica ################
data = np.genfromtxt('todaplacaperiodica.txt')

frn = int(data.shape[0]/50) # frame number of the animation

zarray = np.zeros((50, 50, frn))

for i in range(frn):
    zarray[:,:,i] = data[i*50:(i+1)*50,:]
    
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ims = []
for i in range(frn):
    sf = ax.plot_surface(x, y, zarray[:,:,i], cmap='hot' , rstride=1, cstride=1)
    ims.append([sf])

ax.set_zlim(0,100)
ani = animation.ArtistAnimation(fig, ims, interval=1000/fps, blit=True)
plt.show()