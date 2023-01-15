n = list(eval(input("Enter a list of numbers: ")))
elem = n[-1]
print("Index of '-1' element: ", n.index(elem))
n.remove(elem)
print("Removing '-1' element:", *n, sep=', ')
