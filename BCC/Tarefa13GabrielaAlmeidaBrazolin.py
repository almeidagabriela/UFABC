# -*- coding: utf-8 -*-
"""
Tarefa 13

Gabriela Almeida Brazolin - 11201920723
"""

import pandas as pd

tabela = pd.read_csv('tabelaBrasileirao2018.csv')

vitCor = tabela[tabela['Mandante'] == 'Corinthians']
publiVit = vitCor['Público']
publico = publiVit.hist() #Histograma

mediaPub = vitCor['Público'].mean()
print('A média do publico foi de:',mediaPub)