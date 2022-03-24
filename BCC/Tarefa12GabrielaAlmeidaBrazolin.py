# -*- coding: utf-8 -*-
"""
Tarefa 12

Gabriela Almeida Brazolin - RA 11201920723
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Exercicio 1 - Aproximação de PI
#Formula: pi = 4/1 - 4/3 + 4/5 - 4/7 + 4/9

#Variaveis
pi = 0
num = 4.0

for i in range(50):
    den = (2*i+1) #Denominador e definição de numero impar
    val = num/den
    
    if i%2 != 0: #Se o numero for diferente de 0
        pi -= val
    else:
        pi += val
print(pi)

pi = 0
num = 4.0

for i in range(500):
    den = (2*i+1) #Denominador e definição de numero impar
    val = num/den
    
    if i%2 != 0: #Se o numero for diferente de 0
        pi -= val
    else:
        pi += val
print(pi)

pi = 0
num = 4.0

for i in range(1000):
    den = (2*i+1) #Denominador e definição de numero impar
    val = num/den
    
    if i%2 != 0: #Se o numero for diferente de 0
        pi -= val
    else:
        pi += val
print(pi)

pi = 0
num = 4.0

for i in range(10000):
    den = (2*i+1) #Denominador e definição de numero impar
    val = num/den
    
    if i%2 != 0: #Se o numero for diferente de 0
        pi -= val
    else:
        pi += val
print(pi)

print('_'*80) #Separador

#Exercicio 2 - Inflação


tabela = pd.read_csv('inflacaoMensal.csv')

#1º laço para contagem dos anos
#2º laço para soma dos meses

inf = 0

#print(tabela[tabela['Ano'] == 1944])

aInf = np.zeros((888))
inf = np.zeros((74))

aInf[0] = 0
inf[0] = 0

for i in range(1945, 2019):   
    for j in range(0, 11):
        linInf = tabela[np.logical_and(tabela['Ano'] == i, tabela['Mês'] == j)]
        #vInf = linInf['Inflação'].values[j]
        #aInf[j] = vInf
        
    #inf[i] = (((1+(vInf[0])/100))*(1+(vInf[1]/100))*(1+(vInf[2]/100))*(1+(vInf[3]/100))*(1+(vInf[4]/100))*(1+(vInf[5]/100))*(1+(vInf[6]/100))*(1+(vInf[7]/100))*(1+(vInf[8]/100))*(1+(vInf[9]/100))*(1+(vInf[10]/100))*(1+(vInf[11]/100))*(1+(vInf[12]/100))*100)
    #print(inf[i])
    
print('_'*80) #Separador

#Exercicio 3 - Aproximação de uma onda

#Variaveis
t = np.linspace(0, 10, 100000)
pi = np.pi
soma = 0

N = 10
#Laço de repetição para o calculo da somatória
for i in range(N):
    soma += np.sin((2*i - 1)*t) / (2*i - 1)


x = (4/pi) * soma

plt.figure() #Abrir uma figura

plt.plot(t,x, linestyle = '-', color = '#39ff14')

plt.xlabel('t') #rótulo do x
plt.ylabel('x(t)') #rótulo do y

plt.title('Gráfico de x em função de t') #titulo do gráfico

plt.show() #Mostrar gráfico

soma = 0
N = 100
#Laço de repetição para o calculo da somatória
for i in range(N):
    soma += np.sin((2*i - 1)*t) / (2*i - 1)


x = (4/pi) * soma

plt.figure() #Abrir uma figura

plt.plot(t,x, linestyle = '-', color = '#39ff14')

plt.xlabel('t') #rótulo do x
plt.ylabel('x(t)') #rótulo do y

plt.title('Gráfico de x em função de t') #titulo do gráfico

plt.show() #Mostrar gráfico

soma = 0
N = 1000
#Laço de repetição para o calculo da somatória
for i in range(N):
    soma += np.sin((2*i - 1)*t) / (2*i - 1)


x = (4/pi) * soma

plt.figure() #Abrir uma figura

plt.plot(t,x, linestyle = '-', color = '#39ff14')

plt.xlabel('t') #rótulo do x
plt.ylabel('x(t)') #rótulo do y

plt.title('Gráfico de x em função de t') #titulo do gráfico

plt.show() #Mostrar gráfico

soma = 0
N = 10000
#Laço de repetição para o calculo da somatória
for i in range(N):
    soma += np.sin((2*i - 1)*t) / (2*i - 1)


x = (4/pi) * soma

plt.figure() #Abrir uma figura

plt.plot(t,x, linestyle = '-', color = '#39ff14')

plt.xlabel('t') #rótulo do x
plt.ylabel('x(t)') #rótulo do y

plt.title('Gráfico de x em função de t') #titulo do gráfico

plt.show() #Mostrar gráfico