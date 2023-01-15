from math import lcm
a = list(map(int, input("Enter numbers (a, b, c, ...): ").split(',')))
print("LCM:", lcm(*a))
