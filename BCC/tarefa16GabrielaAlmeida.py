# -*- coding: utf-8 -*-
"""
Tarefa 16

Gabriela Almeida Brazolin - 11201920723
"""
#Importando as biliotecas do python
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

#Exercicio 1

def funcaoUm(t, A, b, c):
    '''
    Função para o calculo de x em função de t
    '''
    x = A*np.sqrt(1+b*(t**2))+c
    
    '''
    Gráfico de x em função de t
    '''
    #Gráfico
    plt.figure()
    plt.plot(t, x,
            linestyle = '-', color='red')
    plt.xlabel('t')
    plt.ylabel('x')
    plt.title('Gráfico de x em função de t')
    plt.show()
    
    return x

#Valores Letra a
t = np.linspace(0, 10, 1000)
a = funcaoUm(t, 2, 0.5, 0) #Chamando a função "funcaoUm"
#print(a)

#Valores Letra b
t = np.arange(0, 15, 0.2)
b = funcaoUm(t, 10, 0.2, 1) #Chamando a função "funcaoUm"

#Valores Letra c
t = np.linspace(-0.5, 0.5, 500)
c = funcaoUm(t, -3, -1.5, -10) #Chamando a função "funcaoUm"

print('_'*80) #Separador

#Exercicio 2
def caraOuCoroa():
    '''
    Função que retorna um número aleatório entre 0 e 1
    se o número for menor que 0.5, então ele é Cara
    se o número for maior que 0.5, então ele é Coroa
    
    n = variavel que retorna um número aleatorio entre 0 e 1
    '''
    n = np.random.rand(1) #número aleatorio entre 0 e 1
    
    if n < 0.5:
        print('Cara - Nº sorteado:',n)
    elif n > 0.5:
        print('Coroa - Nº sorteado:',n)

#Chamando a função 10 vezes
caraOuCoroa()
caraOuCoroa()
caraOuCoroa()
caraOuCoroa()
caraOuCoroa()
caraOuCoroa()
caraOuCoroa()
caraOuCoroa()
caraOuCoroa()
caraOuCoroa()

print('_'*80) #Separador

#Exercicio 3

def moda(dtFrame, coluna):
    '''
    Função que calcula a moda de uma coluna de determinado dataFrame
    Imprimindo a sua moda e retornando o valor da moda
    '''
    moda = dtFrame[coluna].value_counts().index[0]
    print('A moda é:',moda)
    return moda
    
dtFrame = pd.read_csv('tabelaBrasileirao2018.csv')
coluna = 'Mandante'
moda(dtFrame, coluna)

print('_'*80) #Separador

#Exercicio 4

def inclinacao(x1, y1, x2,y2, N):
    '''
    Função que calcula a inclinação de uma reta
    e encontra o ponto em que a reta cruza o eixo y
    
    m = inclinação da reta
    b = ponto que cruza o eixo y
    '''
    m = (y2 - y1)/(x2 - x1)
    b = y1 - m*x1
    
    pontosX = np.linspace(x1,x2, N)
    pontosY = np.linspace(y1,y2, N)
    
    #Gráfico
    plt.figure()
    plt.plot(pontosX, pontosY,
            linestyle = '-', color='red')
    plt.plot(x1, y1,
            marker = 'd', color='blue')
    plt.plot(x2, y2,
            marker = 'd', color='orange')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Gráfico de inclinação de uma reta')
    plt.show()
    
    return m, b
    
a = inclinacao(-19, 2,10,-10, 1000)