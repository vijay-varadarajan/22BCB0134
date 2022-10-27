num = int(input("Number: "))
rev = ''

for i in range(len(str(num))):
    rev += str((num % 10**(i+1)) - (num % 10**(i))).strip('0')

print("Reverse:", rev)

