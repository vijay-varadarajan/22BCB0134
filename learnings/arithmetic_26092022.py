#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 26 14:03:06 2022

@author: matlab
"""

a = float(input("Enter a number: "))
b = float(input("Enter another number: "))

sum = a + b
diff = a - b
prod = a * b
div = a / b
div2 = a // b
mod = a % b

print("Sum is: ", sum)
print("Difference is:", diff)
print("Product is:", prod)
print("Normal Division is:", div)
print("Floor division is:", div2)
print("Remainder after division is:", mod)