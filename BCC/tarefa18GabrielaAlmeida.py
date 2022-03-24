# -*- coding: utf-8 -*-
"""
Tarefa 18

Gabriela Almeida Brazolin - 11201920723
"""
#importando bibliotecas
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Importando o arquivo criado "func"
import func as f1

'''
    Exercicio 1
    
    Gerar o gráfico de dispersão do tamanho do pé em função da altura da pessoa.
    Feito isso, calcular a correlação e plotar a reta de regressão entre os dados.
'''
tabela = pd.read_csv('BDSinfo.csv', delimiter='\t') #DELIMITANDO OS DADOS

x = tabela['Height']
y = tabela['FootLen']

m, b = f1.regressao(x, y)
y1 = m*x + b

plt.figure()
plt.plot(x , y, marker='o', color='red', linestyle='')
plt.plot(x, y1, linewidth = 3) #Reta de regressão
plt.grid()
plt.show()

r = f1.correlacao(x, y)

print('Correlação:',r)

print('_'*80) #Separador

'''
    Exercicio 2
    
    Gráfico da dispersão entre o crescimento do PIB e a inflação anual de 1961 a 2018
    Mostrar a correlação entre as duas grandezas
'''

#Chamando arquivos de tabelas
pib = pd.read_csv('pibAnual.csv')
inflacao = pd.read_csv('inflaAnual.csv')

#Filtrando o intervalo de 1961 a 2018
infla = inflacao[np.logical_and(inflacao['Ano'] > 1960, inflacao['Ano'] <= 2018)]

#Filtrando os dados da inflação
inflaAno = infla['Inflação']

#Filtrando os dados do PIB
pibAno = pib['Variação anual do PIB real (%)']

x = pibAno
y = inflaAno

plt.figure()
plt.plot(x , y, marker='o', color='orange', linestyle='')
plt.grid()
plt.show()

r = f1.correlacao(x, y)

print('Correlação:',r)

print('_'*80) #Separador

'''
    Exercicio 3
    
    Gráfico da dispersão entre o número de medicamentos que a pessoa toma em função da idade da pessoa.
    Mostrar a correlação e plotar a regressão entre os dados.
'''

tabela1 = pd.read_csv('BDSinfo.csv', delimiter='\t') #DELIMITANDO OS DADOS

x = tabela1['Age']
y = tabela1['Nmedication']

m, b = f1.regressao(x, y)
y1 = m*x + b

plt.figure()
plt.plot(x , y, marker='o', color='blue', linestyle='')
plt.plot(x, y1, linewidth = 3, color='red') #Reta de regressão
plt.grid()
plt.show()

r = f1.correlacao(x, y)

print('Correlação:',r)

print('_'*80) #Separador