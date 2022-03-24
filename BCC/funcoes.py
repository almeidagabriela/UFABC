# -*- coding: utf-8 -*-
"""
Aula 09

Funções
"""
import numpy as np

def regressao(x, y):
    '''
    Fazendo o calculo de m, que é igual a varias somatórias que se dividem hehe
    
    aperta TAB para ele dar as opções
    '''
    mediaX = np.mean(x) #media do x
    mediaY = np.mean(y) #media do x
    
    desvioX = x - mediaX
    desvioY = y - mediaY
    
    somaXY = np.sum(desvioX*desvioY)
    somaX2 = np.sum(desvioX**2)
    
    m = somaXY/somaX2
    
    b = mediaY - m*mediaX
    
    return m, b

def correlacao(x, y):
    
    mediaX = np.mean(x) #media do x
    mediaY = np.mean(y) #media do x
    
    desvioX = x - mediaX
    desvioY = y - mediaY
    
    somaXY = np.sum(desvioX*desvioY)
    somaX2 = np.sum(desvioX**2)
    somaY2 = np.sum(desvioY**2)
    
    raizX2 = np.sqrt(somaX2)
    raizY2 = np.sqrt(somaY2)
    
    r = somaXY/(raizX2*raizY2)
    
    return r