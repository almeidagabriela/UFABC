# -*- coding: utf-8 -*-
"""
Tarefa 4 Gabriela Almeida Brazolin
"""
print('-' * 80) #Separador
print('Tarefa 4 - Gabriela Almeida Brazolin - 11201920723')
print('-' * 80) #Separador

import numpy as np #importando a biblioteca matemática numpy

#Calcular o volume de uma esfera

#Variaveis
pi = np.pi #variavel pi contendo o valor de pi salvo na biblioteca np

r = 0.32 #variavel r contendo o valor do raio de 0,32m

#Calculo do Volume
vol = (4*pi*r**3) / 3

print('Volume da esfera de raio = ',r,' é: ', vol) #imprimindo o resultado no console

r = 1 #variavel r contendo o valor do raio de 1m

#Calculo do Volume
vol = (4*pi*r**3) / 3

print('Volume da esfera de raio = ',r,' é: ', vol) #imprimindo o resultado no console

r = 1.9 #variavel r contendo o valor do raio de 1,9m

#Calculo do Volume
vol = (4*pi*r**3) / 3

print('Volume da esfera de raio = ',r,' é: ', vol) #imprimindo o resultado no console

print('_' * 80) #Separador

#Calcular a teperatura em Fahrenheit dada a temperatura em Celsius

tc = -10 #Variavel contendo o valor da temperatura em celsius

tf = (tc * 9/5) + 32 #Calculo para transformação do valor de celsius para fahrenheit

print( tc, 'graus Celsius em Fahrenheit é: ', tf)

tc = 30 #Variavel contendo o valor da temperatura em celsius

tf = (tc * 9/5) + 32 #Calculo para transformação do valor de celsius para fahrenheit

print( tc, 'graus Celsius em Fahrenheit é: ', tf)

tc = 5 #Variavel contendo o valor da temperatura em celsius

tf = (tc * 9/5) + 32 #Calculo para transformação do valor de celsius para fahrenheit

print( tc, 'graus Celsius em Fahrenheit é: ', tf)

print('_' * 80) #Separador

#Calcular o lado do triangulo a partir da lei dos cossenos

#Variaveis
a = 1 #Lado do triangulo
b = 2 #Lado do triangulo
t = 30 #Variavel que contem o valor de teta (angulo)

cosT = np.cos(t) #função que retorna o valor do cosseno da variavel t

c = np.sqrt(a**2 + b**2 - 2*a*b*cosT) #Lei dos cossenos

print('O tamanho do lado c para a =',a,'b =',b,' e angulo =',t,' é = ', c)

#Variaveis
a = 3 #Lado do triangulo
b = 1 #Lado do triangulo
t = 45 #Variavel que contem o valor de teta (angulo)

cosT = np.cos(t) #função que retorna o valor do cosseno da variavel t

c = np.sqrt(a**2 + b**2 - 2*a*b*cosT) #Lei dos cossenos

print('O tamanho do lado c para a =',a,'b =',b,' e angulo =',t,' é = ', c)

#Variaveis
a = 10 #Lado do triangulo
b = 11 #Lado do triangulo
t = 15 #Variavel que contem o valor de teta (angulo)

cosT = np.cos(t) #função que retorna o valor do cosseno da variavel t

c = np.sqrt(a**2 + b**2 - 2*a*b*cosT) #Lei dos cossenos

print('O tamanho do lado c para a =',a,'b =',b,' e angulo =',t,' é = ', c)

print('_' * 80) #Separador

#Série de Fibonacci

raiz = np.sqrt(5) #atribuindo a raiz de 5 a variavel

i = 30 #Atribuindo o valor 30 a variavel i, a qual determina a posição do numero de fibonacci

fi = np.floor((((1+raiz)/2)**i - ((1-raiz)/2)**i)/raiz) #Fórmula geral para a Série de Fibonacci

print('O número na posição', i,'na sequência de Fibonacci é', fi)

i = 31 #Atribuindo o valor 31 a variavel i, a qual determina a posição do numero de fibonacci

fi = np.floor((((1+raiz)/2)**i - ((1-raiz)/2)**i)/raiz) #Fórmula geral para a Série de Fibonacci

print('O número na posição', i,'na sequência de Fibonacci é', fi)

i = 32 #Atribuindo o valor 32 a variavel i, a qual determina a posição do numero de fibonacci

fi = np.floor((((1+raiz)/2)**i - ((1-raiz)/2)**i)/raiz) #Fórmula geral para a Série de Fibonacci

print('O número na posição', i,'na sequência de Fibonacci é', fi)

print('-' * 80) #Separador