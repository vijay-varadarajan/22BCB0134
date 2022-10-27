dob = (input("Enter dob: "))
sum = 0

if len(dob) != 8:
    print("Cannot be processed")
else:
    n = 0
    while n < 8:
        sum += int(dob[n]) * 3
        n += 2
    n = 1
    while n < 8:
        sum += int(dob[n])
        n += 2
    
    if int(str(sum)[-1]) == 0:
        print(f"{dob}, Lucky number")
    else:
        print(f"{dob}, Not a lucky number")