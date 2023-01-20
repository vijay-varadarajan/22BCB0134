def perfect(n):
    sumofdivs = 0
    for i in range(1, n):
        if n % i == 0:
            sumofdivs += i
    if n == sumofdivs:
        return True
    else:
        return False

if perfect(int(input("Enter a number: "))):
    print("Perfect number")
else:
    print("Not a perfect number")