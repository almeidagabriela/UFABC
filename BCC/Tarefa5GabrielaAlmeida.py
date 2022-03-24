# -*- coding: utf-8 -*-
"""
Created on Fri Jul  5 20:18:24 2019

@author: almeida.gabriela

Tarefa 5
"""

#Fazer o gráfico da altura em função do tempo

#Importar a biblioteca numpy
import numpy as np

#Variaveis
t = np.arange(0, 5, 0.1) #Criação de um vetor de 0 a 5 com intervelo de 0.1s

h = -(t**2) + 4*t #Definir a altura em função de t

#Importando a biblioteca para criação de gráficos
import matplotlib.pyplot as plt

plt.figure() #Abrir uma figura

plt.plot(t,h, linestyle = '-', color = 'orange')

plt.xlabel('t(s)') #rótulo do x
plt.ylabel('h(m)') #rótulo do y

plt.title('Gráfico da altura em função do tempo') #titulo do gráfico

plt.ylim(0,5) #limite max intervalo de y

plt.show() #Mostrar gráfico

hmax = np.max(h)

print('A altura max de h é =', hmax, 'metros') #Determinando o ponto maximo da altura