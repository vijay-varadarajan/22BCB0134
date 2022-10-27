num = int(input("Number: "))
factors = []

for n in str(num):
    if num % int(n) == 0:
        factors.append(n)

if len(factors) == 0:
    print("No factors")
else:
    print("Factors:", *factors[::-1])
