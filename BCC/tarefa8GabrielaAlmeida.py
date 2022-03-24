# -*- coding: utf-8 -*-
"""
Gabriela Almeida Brazolin - 11201920723

Tarefa 8
"""

#Exercicio 1: Calcular o IMC

m = 52 #Massa corporal
h = 1.58 #Altura em metros

imc = m/h**2 #Calculo do IMC

if imc < 17: #Se o imc for menor que 17kg/m^2
    print('A pessoa com IMC:',imc ,'está muito abaixo do peso') #imprimir resultado

if imc >= 17 and imc <= 18.5: #Se o imc for maior/igual que 17 kg/m^2 e menor/igual que 18,5 kg/m^2
    print('A pessoa com IMC:',imc ,'está abaixo do peso') #imprimir resultado

if imc > 18.5 and imc <= 25: #Se o imc for maior que 18.5 kg/m^2 e menor/igual que 25 kg/m^2
    print('A pessoa com IMC:',imc ,'está com peso normal') #imprimir resultado
    
if imc > 25 and imc <= 30: #Se o imc for maior que 25 kg/m^2 e menor/igual que 30 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado

if imc > 30 and imc <= 35: #Se o imc for maior que 30 kg/m^2 e menor/igual que 35 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado
    
if imc > 35 and imc <= 40: #Se o imc for maior que 35 kg/m^2 e menor/igual que 40 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado
    
if imc > 40: #Se o imc for maior que 40 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado
    

m = 83 #Massa corporal
h = 1.75 #Altura em metros

imc = m/h**2 #Calculo do IMC

if imc < 17: #Se o imc for menor que 17kg/m^2
    print('A pessoa com IMC:',imc ,'está muito abaixo do peso') #imprimir resultado

if imc >= 17 and imc <= 18.5: #Se o imc for maior/igual que 17 kg/m^2 e menor/igual que 18,5 kg/m^2
    print('A pessoa com IMC:',imc ,'está abaixo do peso') #imprimir resultado

if imc > 18.5 and imc <= 25: #Se o imc for maior que 18.5 kg/m^2 e menor/igual que 25 kg/m^2
    print('A pessoa com IMC:',imc ,'está com peso normal') #imprimir resultado
    
if imc > 25 and imc <= 30: #Se o imc for maior que 25 kg/m^2 e menor/igual que 30 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado

if imc > 30 and imc <= 35: #Se o imc for maior que 30 kg/m^2 e menor/igual que 35 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado
    
if imc > 35 and imc <= 40: #Se o imc for maior que 35 kg/m^2 e menor/igual que 40 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado
    
if imc > 40: #Se o imc for maior que 40 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado
    
m = 60 #Massa corporal
h = 1.60 #Altura em metros

imc = m/h**2 #Calculo do IMC

if imc < 17: #Se o imc for menor que 17kg/m^2
    print('A pessoa com IMC:',imc ,'está muito abaixo do peso') #imprimir resultado

if imc >= 17 and imc <= 18.5: #Se o imc for maior/igual que 17 kg/m^2 e menor/igual que 18,5 kg/m^2
    print('A pessoa com IMC:',imc ,'está abaixo do peso') #imprimir resultado

if imc > 18.5 and imc <= 25: #Se o imc for maior que 18.5 kg/m^2 e menor/igual que 25 kg/m^2
    print('A pessoa com IMC:',imc ,'está com peso normal') #imprimir resultado
    
if imc > 25 and imc <= 30: #Se o imc for maior que 25 kg/m^2 e menor/igual que 30 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado

if imc > 30 and imc <= 35: #Se o imc for maior que 30 kg/m^2 e menor/igual que 35 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado
    
if imc > 35 and imc <= 40: #Se o imc for maior que 35 kg/m^2 e menor/igual que 40 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado
    
if imc > 40: #Se o imc for maior que 40 kg/m^2
    print('A pessoa com IMC:',imc ,'está acima do peso') #imprimir resultado
    
print('_'*70) #Separador

#Exercicio 2: Acidez

import numpy as np
import matplotlib.pyplot as plt

#Variaveis
x = np.arange(0, 9, 1) #intervalo dos valores de x
a = x**3 + 3*x**2 - 54 #calculo da acidez em função de x
xmin = x[ a == 0]
amin = 0

plt.figure()

plt.plot(x, a)
plt.plot(xmin, amin, marker='o', markersize=5, color='#ff0000')
plt.xlabel('x')
plt.ylabel('a')


plt.grid()
plt.show()

print('_'*70) #Separador

#Exercicio 3: Gráfico de uma função

x = np.arange(-10, 11, 1)  #intervalo dos valores de x
#np.abs: módulo
fx = np.abs(x-2)+np.abs(2*x+1)-x-6 

plt.figure()

plt.plot(x, fx)
plt.xlabel('x')
plt.ylabel('f(x)')

plt.grid()
plt.show()

xmin = np.logical_and(fx > 0, x > 0) #valor booleano de f(x) e x
xmi = x[xmin == True] #recebe valores onde a variavel xmin é true
print('O menor valor de x dada as condições é:',np.min(xmi)) #imprime

print('_'*70) #Separador

#Exercicio 4: Gráfico de uma função

x = np.arange(-7, 7, 1); #intervalo de x
fx = x**2 - np.sin(0.784*x**2)-2 #função de f(x)

plt.figure()

plt.plot(x, fx)
plt.xlabel('x')
plt.ylabel('f(x)')

plt.grid()
plt.show()

fxmin = x[fx == 0] #achar x quando f(x) for 0

print('As raizes da função são', fxmin)