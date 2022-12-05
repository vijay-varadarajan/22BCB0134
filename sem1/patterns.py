h = int(input("Height: "))

for i in range(0, h):
    for j in range(h-(i+1), 0, -1):
        print(" ", end='')
    for k in range(0, i+1):
        print("*", end='')
    print()