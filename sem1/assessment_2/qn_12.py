key = {1: 'A', 2: 'B', 3: 'B', 4: 'A', 5: 'C'}
cands = int(input("Number of candidates: "))
opts = []
for i in range(cands):
    choices = input().split()
    opts.append(tuple(choices))
print(opts)

marks = {}
for i in range(cands):
    for j in range(len(opts[i])):
        if opts[i][j] == 'X':
            continue
        elif opts[i][j] == key[j+1]:
            ...