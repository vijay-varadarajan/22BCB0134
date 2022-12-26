dob = (input())
sum = 0

if len(dob) != 8:
    print("Invalid input")
else:
    n = 0
    while n < 8:
        sum += int(dob[n]) * 3
        n += 2
    n = 1
    while n < 8:
        sum += int(dob[n])
        n += 2
    
    if sum % 10 == 0:
        print(f"{dob},not Lucky number")
    else:
        print(f"{dob}, lucky number")