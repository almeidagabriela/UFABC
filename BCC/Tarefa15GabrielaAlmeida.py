# -*- coding: utf-8 -*-
"""
Tarefa 15

Gabriela Almeida Brazolin - 11201920723
"""

def intervalo(a, b, x):
    if x >= a and x <= b:
        msg = 'o valor '+str(x)+' está no intervalo de '+str(a)+' e '+str(b)
        return True, msg
    else:
        msg = 'o valor '+str(x)+' não está no intervalo de '+str(a)+' e '+str(b)
        return False, msg
    
a = -2.5
b = 6.3
x = 9.1

verifica, msg = intervalo(a, b, x)

print(verifica, msg)

a = -10
b = 7
x = 2.2

verifica, msg = intervalo(a, b, x)

print(verifica, msg)

a = 67.2
b = 87.2
x = 8.1

verifica, msg = intervalo(a, b, x)

print(verifica,'e', msg)