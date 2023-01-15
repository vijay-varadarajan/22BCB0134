a = eval(input("Enter 3 integers a, b, c: "))
for num in range(len(a)):
    if a[num] > a[num+1] and a[num] > a[num+2]:
        print(a[num], "is the greatest.")
        break
    elif a[num+1] > a[num] and a[num+1] > a[num+2]:
        print(a[num+1], "is the greatest.")
        break
    else:
        print(a[num+2], "is the greatest.")
        break

