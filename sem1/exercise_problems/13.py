def main():
    n = eval(input("Enter a list of numbers: "))
    print("Prime numbers: ")
    for i in n:
        if prime(i):
            print(i)

def prime(i):
    prime = True
    for j in range(2, i//2):
        if i % j == 0:
            prime = False
            break
    if prime:
        return True
    else:
        return False

main()