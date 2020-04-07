#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 21 15:01:07 2019

@author: gianluca
"""

n = int(input('n = ? '))

i = 2
Fp = 1
Fpp = 0

if n >= 2:
    while i <= n:
        F = Fp + Fpp
        Fpp = Fp
        Fp = F
        i = i+1
else:
    F = n
    
print(F)