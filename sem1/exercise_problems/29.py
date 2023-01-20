m, n = int(input()), int(input())
odds, evens = 0, 0 
for i in range(m+1, n):
    if i % 2 == 1:
        odds += 1
    else:
        evens += 1
print("ODDS:", odds)
print("EVENS: ", evens)
