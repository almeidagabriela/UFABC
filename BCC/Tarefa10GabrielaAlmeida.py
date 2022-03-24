# -*- coding: utf-8 -*-
"""
Tarefa 10 - Gabriela Almeida Brazolin
RA: 11201920723
"""
#Importando bibliotecas do python
import matplotlib.pyplot as plt
import pandas as pd

#Exercicio 1 Campeonato Brasileiro

#importando a tabela de jogos do Campeonato Brasileiro
tabela = pd.read_csv('tabelaBrasileirao2018.csv')

#Calcular a porcentagem de jogos que o mandante ganhou o jogo.

mandanteVit = tabela["Placar do Mandante"] > tabela["Placar do Visitante"] #retorna valor booleano (true ou false)
mandVit = mandanteVit[mandanteVit == True] #retorna somente os valores true

#retornam a quantidade de linhas
vitorias = len(mandVit) 
total = len(tabela)

porcentagem = (vitorias*100)/total

print('A porcentagem de vitórias em casa é de:',round(porcentagem, 2),'%') #imprime na tela o resultado

#Calcular a porcentagem de jogos que o mandante não perdeu o jogo.

mandanteEmpVit = tabela["Placar do Mandante"] >= tabela["Placar do Visitante"] #retorna valor booleano (true ou false)
mandEmpVit = mandanteEmpVit[mandanteEmpVit == True] #retorna somente os valores true

#retornam a quantidade de linhas
empatesVitorias = len(mandEmpVit) 
total = len(tabela)

porcentagem = (empatesVitorias*100)/total

print('A porcentagem de empates & vitórias em casa é de:',round(porcentagem, 2),'%') #imprime na tela o resultado

print('-'*80) #separador

#Exercicio 2 Taxa de Inflação

#importando a tabela de inflação
inflacao = pd.read_csv('inflacaoMensal.csv')

ano = inflacao["Ano"]
inflacaoM = inflacao["Inflação"]

plt.figure()
plt.plot(ano, inflacaoM,
        linestyle = '-', color = '#ff4700')
        
plt.xlabel('Ano') #rótulo do x
plt.ylabel('Inflação') #rótulo do y

plt.title('Taxa de inflação mensal em função do tempo') #titulo do gráfico
plt.show()

inflaMax = max(inflacao["Inflação"]) #Retorna a Inflação Máxima
inMax = inflacao[inflacao["Inflação"] == inflaMax] #Retorna a linha com o Ano, Mês e a Inflação

print(inMax) #Imprime os dados

print('-'*80) #separador

#Exercicio 3 Netflix

#importando a tabela de histórico
netflix = pd.read_csv('netflix.csv')

netflix['Categoria'] = 'Filme'  
netflix['Categoria'][netflix['Title'].str.contains(": Temporada|: Stranger|: Parte")] = 'Série'  
netflix['Programa'] = netflix['Title']  
netflix[['Programa','Episódio']] = netflix[netflix['Categoria']=='Série']['Title'].str.split(pat = ': Temporada|: Stranger Things|: Parte', expand = True, n = 1)   
netflix.loc[netflix['Categoria']=='Filme', 'Programa'] = netflix.loc[netflix['Categoria']=='Filme', 'Title']  
netflix = netflix.drop(columns = 'Title')
