# -*- coding: utf-8 -*-
"""
Tarefa 17

Gabriela Almeida Brazolin - 11201920723
"""
#importando as bibliotecas
import pandas as pd

import funcoes as f1 #Chamando o arquivo FUNÇÕES

#Calculando a correlação

tabela = pd.read_csv('tabelaBrasileirao2018.csv')

renda = tabela['Renda (R$)']
publico = tabela['Público']

r = f1.correlacao(renda, publico)

print('Correlação:',r)