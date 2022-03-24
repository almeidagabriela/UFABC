# -*- coding: utf-8 -*-
"""
Tarefa 6

Gabriela Almeida Brazolin
"""
#Calculo da tensão elétrica de um circuito

import numpy as np #importando a biblioteca numpy

e = np.e #atribuindo o número de euler a variavel e
pi = np.pi #atribuindo o valor de pi a variavel pi
t = np.arange(0, 10, 0.05) #atribuindo o intervalo de 0 a 10 com variação de 0.05 segundos a variavel t
cos = np.cos(2*pi*0.8*t) #atribuindo os valores do cosseno

v = e**(-0.5*t)*cos #calculo da tensão do circuito

#Importando a biblioteca para criação de gráficos
import matplotlib.pyplot as plt

plt.figure() #Abrir uma figura

plt.plot(t,v, linestyle = '-', color = '#39ff14')

plt.xlabel('t(s)') #rótulo do x
plt.ylabel('v(volt)') #rótulo do y

plt.title('Gráfico da tensão em função do tempo') #titulo do gráfico

plt.show() #Mostrar gráfico

print('_'*80) #Separador

#Gráfico da temperatura em Fahrenheits em função do tempo

c = np.linspace(-20, 100, 100) #intervalo de -20º a 100º com 100 elementos
f = (9/5 * c) + 32 #calculo da temperatura em fahrenheits

plt.figure() #Abrir uma figura

plt.plot(c,f, linestyle = '-', color = '#ff4700')
         
plt.xlabel('Tc (ºC)') #rótulo do x
plt.ylabel('Tf (ºF)') #rótulo do y

plt.title('Gráfico de ºF em função de ºC') #titulo do gráfico

plt.show() #Mostrar gráfico

print('_'*80) #Separador

#Calculo do crescimento populacional de uma cidade

e = np.e #variavel que contem o número de euler
a = np.arange(1994, 2020, 1) #intervalo de 1994 a 2020 por ano

p = 800000*e**((a-1994)/40) #calculo do crescimento populacional em função do ano

#gráfico do nº de habitantes em função do ano

plt.figure() #Abrir uma figura

plt.plot(a,p, linestyle = '-', color = '#00BFFF')
         
plt.xlabel('Ano') #rótulo do x
plt.ylabel('População') #rótulo do y

plt.title('Crescimento Populacional (1994-2020)') #titulo do gráfico

plt.show() #Mostrar gráfico

max = np.max(p)

print('A previsão do número de habitantes para 2020 é: ', max)