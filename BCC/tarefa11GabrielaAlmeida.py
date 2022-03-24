# -*- coding: utf-8 -*-
"""
Tarefa 11

Gabriela Almeida Brazolin 11201920723
"""
#Exercicio 1

#importando biblioteca numpy

import numpy as np

z = 250

v = np.zeros((z))
y = np.zeros((z))
t = np.zeros((z))

v[0] = 10
y[0] = 0
t[0] = 0

for i in range(1, z): #intervalo de 1 a 250
    v[i] = v[i-1]+0.01*(-9.81) #os [] marcam o indice
    y[i]= y[i-1]+ 0.01*v[i-1]
    t[i]= t[i-1]+0.01
    

import matplotlib.pyplot as plt #importando biblioteca gráfica

plt.figure()
plt.plot(t, y,
        linestyle = '-', color = '#ff4700')
        
plt.xlabel('t(s)') #rótulo do x
plt.ylabel('y(m)') #rótulo do y

plt.title('Gráfico de Metros em função do Tempo') #titulo do gráfico
plt.show()

plt.figure()
plt.plot(t, v,
        linestyle = '-', color = '#00ff47')
        
plt.xlabel('t(s)') #rótulo do x
plt.ylabel('v(m/s)') #rótulo do y

plt.title('Gráfico de Velocidade em função do Tempo') #titulo do gráfico
plt.show()