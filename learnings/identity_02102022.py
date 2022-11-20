x = [1, 2, 3]
y = x

print(x is y)
print(x is not y)

print(id(x))
print(id(y))

z = [1, 2, 3]

print(x is z)
print(x is not z)

print(id(z),"\n")

a = (1, 2, 5)
b = (1, 2, 5)

print(id(a))
print(id(b))