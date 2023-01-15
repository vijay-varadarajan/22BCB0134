from math import gcd
a = list(map(int, input("Enter numbers(a, b, c, ...): ").split(',')))
print("GCD:", gcd(*a))
