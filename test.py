'''# Test ur program
n = int(input())
out = 1
if n%2 != 0:
    for i in range(2, n+1, 2):
        out *= i
else:
    for i in range(1, n+1, 2):
        out *= i
print(out)
'''
'''
m = int(input())
n = int(input())
choice = int(input())

if choice == 1:
    for i in range(n):
        print(f"{i+1} x {m} = {m*(i+1)}")
if choice == 2:
    for i in range(n):
        print(f"{m} % {i+1} = {m/(i+1):.{(i+1)//2}f}")
'''