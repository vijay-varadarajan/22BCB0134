dec = int(input("Enter an integer: "))
roman = ""

places = []
for i in range(len(str(dec)),0,-1):
    places.append((dec % (10**(i))) - (dec % (10**(i-1))))

expanded = []
for i in range(len(places)):
    if places[i] > 1000:
        expanded.append(places[i])
        continue
    if '4' in str(places[i]):
        expanded.append((10**(len(places) - (i+1))))
        expanded.append(5*(10**(len(places) - (i+1))))
    elif '9' in str(places[i]):
        expanded.append((10**(len(places) - (i+1))))
        expanded.append(10*(10**(len(places) - (i+1))))
    else:
        expanded.append(places[i])

for num in expanded:
    while num >= 1000:
        roman += 'M'
        num -= 1000

    while num >= 500:
        roman += 'D'
        num -= 500

    while num >= 100:
        roman += 'C'
        num -= 100

    while num >= 50:
        roman += 'L'
        num -= 50

    while num >= 10:
        roman += 'X'
        num -= 10

    while num >= 5:
        roman += 'V'
        num -= 5

    while num >= 1:
        roman += 'I'
        num -= 1

print(roman)