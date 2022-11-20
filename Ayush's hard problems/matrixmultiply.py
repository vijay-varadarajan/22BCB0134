m = int(input("enter the no of rows in matrix A: "))
n = int(input("enter the no of rows in matrix B: "))

print("enter elements of matrix A: ")
A=[]
for i in range (m):    # m is number of rows of matrix A
    row=[]
    for j in range(n):   # n is the number columns of matrix A
        elem = int(input(f"enter element [{i}][{j}]: "))
        row.append(elem)
    A.append(row)
# print(A)

B=[]

q=int(input("enter the no of columns in matrix B: "))
print("enter elements of matrix B: ")

for i in range (n):    # n is number of rows of matrix B
    row=[]
    for j in range(q):   # q is number of columns of matrix B
        inp=int(input(f"enter element [{i}][{j}]: "))
        row.append(inp)
    B.append(row)
# print(B)

AxB = []

for i in range(m):
    row = []
    for j in range(q):
        sum = 0
        for k in range(n):
            if (m == n or n == q) and k == m:
                break
            sum += (A[i][k]*B[k][j])
        row.append(sum)
    AxB.append(row)

for i in AxB:
    print(i)
