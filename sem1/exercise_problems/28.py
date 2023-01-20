import math

numbers = eval(input("Enter numbers: "))
print("GCD: ", math.gcd(*numbers))
print("LCM: ", math.lcm(*numbers))
