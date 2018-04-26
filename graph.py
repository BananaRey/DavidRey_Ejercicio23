import numpy as np
import matplotlib.pyplot as plt

archivo=np.loadtxt('onda.txt')

x=archivo[:,0]
u_0=archivo[:,1]
u_1=archivo[:,2]
u_2=archivo[:,3]
u_3=archivo[:,4]
u_4=archivo[:,5]
u_new=archivo[:,6]

plt.plot(x,u_0, label='u_0')
plt.plot(x,u_1, label='u_1')
plt.plot(x,u_2, label='u_2')
plt.plot(x,u_3, label='u_3')
plt.plot(x,u_4, label='u_4')
plt.plot(x,u_new, label='U_5')
#plt.ylim(0.0,1.0)
plt.title('Onda',fontsize=25)
plt.xlabel('x',fontsize=25)
plt.ylabel('u(x,t)',fontsize=25)
plt.show()
plt.savefig('onda.png')
plt.close()
