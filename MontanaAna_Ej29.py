import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits.mplot3d import axes3d
from matplotlib import cm

datos = np.genfromtxt('datosonda.dat')





fig = plt.figure(figsize=(10,5))
ax = fig.add_subplot(1,2,1, projection='3d')
xx, yy = np.mgrid[0:datos.shape[0], 0:datos.shape[1]]
ax.plot_surface(xx, yy, datos ,rstride=1, cstride=1, cmap=cm.coolwarm, linewidth=0)

plt.xlabel("Tiempo[s]")
plt.ylabel("Posicion[m]")
plt.subplot(122)
plt.plot(datos[0:,], label="Tiempo incial")
plt.plot(datos[-1:,], label="Tiempo final")
plt.xlabel("Posicion[m]")
plt.ylabel("Desplazamiento[m]")
plt.legend(loc= 10)
plt.savefig("plotonda.png")
