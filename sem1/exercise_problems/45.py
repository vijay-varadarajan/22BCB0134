def fact(n):
    if n <= 1:
        return 1
    else:
        return n*(fact(n-1))

print("Factorial: ", fact(int(input("Enter an integer to find the factorial of: "))))
