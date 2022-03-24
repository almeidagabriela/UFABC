# -*- coding: utf-8 -*-
"""
Tarefa 19

Gabriela Almeida Brazolin - 11201920723
"""

#Importando as bibliotecas
import numpy as np

'''
    Usando o Método de Monte Carlo para estimar o valor de PI
    
    Area do Circulo: A = PI*r**2
    
    Sortear n números entre 0 e 1
    
    A proporção entre os pontos dentro do circulo e os pontos totais é igual a area do circulo sobre a area total (do quadrado)
    A distancia entre o centro e o ponto precisa ser menor que o raio para fazer parte do circulo. (usa-se pitagoras para calcular a distancia)
'''

#Sortear varios pares de números
x = np.random.rand(10000000)
y = np.random.rand(10000000)

#Quantos estão dentro do circulo

#Centro do Circulo
cx = 0.5
cy = 0.5

dist = np.sqrt((x-cx)**2+(y-cy)**2)

#condicao = dist[dist <= 0.5]
#print(condicao)

totN = 0

for i in range(len(dist)):
    #Se a distancia for menor que 0.5 o ponto está dentro do circulo
    if dist[i] <= 0.5: 
        totN = totN + 1
        
#Achando a proporção
propC = totN/len(dist)

#Estimando PI
pi = 4*propC

print(pi)