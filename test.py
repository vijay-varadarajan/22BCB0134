t = int(input())
for i in range(t):
    n = int(input())
    a = input().split()
    b = input().split()
    streak = 0
    for j in range(n):
        nowa = list(a)
        nowb = list(b)
        print("A: ", nowa[j], "B: ", nowb[j])
        if int(nowa[j]) == 0 or int(nowb[j]) == 0:
            streak = 0
        else:
            streak += 1
    print(streak)