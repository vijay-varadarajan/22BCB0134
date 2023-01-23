arr = list(eval(input("Enter an array of numbers: ")))

print("Mean: ", sum(arr)/len(arr))

arr.sort()

print("Median: ", arr[len(arr)//2])

elemcount = []
for i in arr:
    elemcount.append(arr.count(i))

print(arr[elemcount.index(max(elemcount))])

