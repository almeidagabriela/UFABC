# -*- coding: utf-8 -*-
"""
Tarefa 14

Gabriela Almeida Brazolin - 11201920723
"""
#Importando Bibliotecas
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Exercicio 1

#Importando arquivo
balance = pd.read_csv('balance.csv')

#Variaveis para o gráfico
x = balance['Time[s]']
y = balance['My[Nm]']

plt.figure() #Abrir uma figura

plt.plot(x,y, linestyle = '-', color = '#39ff14')

plt.xlabel('Tempo(s)') #rótulo do x
plt.ylabel('My(Nm)') #rótulo do y

plt.title('Gráfico de My(Nm) em função do Tempo') #titulo do gráfico

plt.show() #Mostrar gráfico

mediaY = y.mean() #Média
desvioY = y.std() #Desvio Padrão

print('Média:', mediaY,'e Desvio Padrão:', desvioY)

print('_'*80) #Separador

#Exercicio 2

#Importando arquivo
inflacaoMensal = pd.read_csv('inflacaoMensal.csv')

mes3 = inflacaoMensal[inflacaoMensal['Mês'] == 3]

mediana3 = mes3['Inflação'].median() #Mediana
media3 = mes3['Inflação'].mean() #Média
desvio3 = mes3['Inflação'].std() #Desvio Padrão

print('Mediana:', mediana3, 'Média:', media3, 'Desvio Padrão:', desvio3)

mes3['Inflação'].hist() #Histograma

print('_'*80) #Separador

#Exercicio 3

mesM = inflacaoMensal[np.logical_and(inflacaoMensal['Ano'] > 1995, inflacaoMensal['Mês'] == 3)] #Mes de março a partir de 1995

medianaM = mesM['Inflação'].median() #Mediana
mediaM = mesM['Inflação'].mean() #Média
desvioM = mesM['Inflação'].std() #Devio Padrão
mesM['Inflação'].hist() #Histograma

#No segundo ihá o valor da inflação em 1994, que é um valor acima de 1, quando retirado a mediana automativamente se altera, e a média idem, tendo um valor a menos acima de 1.

print('_'*80) #Separador

#Exercicio 4
N = 100

x = np.random.rand(N) #Gerar 100 numeros aleatorio entre 0 e 1

plt.figure()
plt.hist(x, 20) #Vetor x, Dividir em 20 vezes
plt.show()

print('Média:', x.mean())

N = 1000

x = np.random.rand(N) #Gerar 1000 numeros aleatorio entre 0 e 1

plt.figure()
plt.hist(x, 20) #Vetor x, Dividir em 20 vezes
plt.show()

print('Média:', x.mean())

N = 10000

x = np.random.rand(N) #Gerar 10000 numeros aleatorio entre 0 e 1

plt.figure()
plt.hist(x, 20) #Vetor x, Dividir em 20 vezes
plt.show()

print('Média:', x.mean())