# -- coding: utf-8 --
"""

Tarega 20

Gabriela Almeida Brazolin - 11201920723
"""

"""
    Calcular pelo modelo de Lotka-Volterra quantas raposas são necessárias colocar 
    em um ecossistema para que a população de coelhos fique entre 500 e 1500
"""

#importando bibliotecas
import numpy as np
import matplotlib.pyplot as plt
#import random as rd

#Variaveis
coelhos = np.zeros((999))
raposas = np.zeros((999))

coelhos[0] = 1000
raposas[0] = 6950

alfa = 0.00011
beta = 0.00001
delta = 0.00007
gama = 0.00000009

'''
rapInicial = np.arange(1, 5000, 1)
deltaCInicial = alfa*coelhos[0]-beta*rapInicial*coelhos[0]
coelhosSec = coelhos[0] + 0.01*(deltaCInicial)

print(coelhosSec)
'''

#i representa a quantidade de dias variando de 1 a 999
for i in range(1, 999):
    
    deltaC = alfa*coelhos[i-1]-beta*raposas[i-1]*coelhos[i-1]
    deltaR= gama*raposas[i-1]*coelhos[i-1]-delta*raposas[i-1]       

    coelhos[i] = coelhos[i - 1] + 0.01*(deltaC)
    raposas[i] = raposas[i - 1] + 0.01*(deltaR)
    
    print('Coelhos:',coelhos[i],'Raposas:', raposas[i])



dias = np.arange(0, 999, 1)       

plt.figure()
plt.plot(dias , raposas, color='red', linestyle='-')
plt.plot(dias , coelhos, color='blue', linestyle='-')
plt.title('Gráfico da quantidade de coelhos e raposas em função dos dias')
plt.grid()
plt.show()