t = int(input())
arr = ['2', '4', '6', '8', 'A', 'C', 'E', '0']
for i in range(t):
    x, y = map(str, input().split())
    if (len(x) != len(y)):
        print("The strings are of unequal length")
        continue
    elif (len(x) < 5 or len(y)< 5 or len(x) >10 or len(y) > 10):
        print("The strings' length is not in the specified range")
        continue

    for j in range(len(x)):
        ind = (int(x[j]) * int(y[j])) % 8
        print(arr[7 - ind], end='')

    print()