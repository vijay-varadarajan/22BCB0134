num = int(input("Number: "))
factors = ''

for n in str(num):
    if num % int(n) == 0:
        factors += n

if len(factors) == 0:
    print("No factors")
else:
    reverse = 0
    factors = int(factors)
    while factors > 0:
        remainder = factors % 10
        reverse = reverse * 10 + remainder
        factors //= 10

    print("Factors:", reverse)
