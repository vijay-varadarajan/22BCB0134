# Program to compute expressions using given values of variables
x = int(input("x: "))
y = int(input("y: "))

print("Expression 1: a =", (x**2 + 2*x*y)/x)
print("Expression 2: b =", (y**3 + 2*(x+y)))
print("Expression 3: c =", x**2 + 2*(y+x) +3*(y/x))
