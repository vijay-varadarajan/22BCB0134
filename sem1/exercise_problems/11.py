A = ord('A')
F = ord('F')
print("Letters from A to F: ", end='')
for i in range(A, F+1):
    print(chr(i), end=', ')
print("\b\b.")