# -*- coding: utf-8 -*-
"""
Gabriela Almeida Brazolin

Tarefa 9
"""

#numero de linha = anos
#colunas = estados
#porcentagem de anafalbetismo da população daquele estado

#carregar arquivo
#fazer gráfico da taxa de anafalbetismo em sp em função dos anos

import matplotlib.pyplot as plt
import pandas as pd

anafalbetismo = pd.read_csv('analfabetismo.csv')

ano = anafalbetismo['Ano']
sp = anafalbetismo['São Paulo']

#Gráfico
plt.figure()
plt.plot(ano, sp,
        linestyle = '-', color='red', markersize=10)
plt.xlabel('Ano')
plt.ylabel('Anafalbetismo')
plt.title('Taxa de anafalbetismo em São Paulo')
plt.show()