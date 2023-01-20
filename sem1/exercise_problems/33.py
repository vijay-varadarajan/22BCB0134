m, n = int(input("M: ")), int(input("n: "))
k = int(input("K: "))

count = 0
for i in range(m, n+1):
    if i >= (n-m)//2 + m and count < k:
        count += 1
        continue
    if k < (n-m):
        print(i, end = ' ')
    else:
        print("Invalid k value")
        break
