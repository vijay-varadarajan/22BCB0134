def main():
    perc, room, count = int(input()), 0, 0
    if perc < 50:
        for i in range(1, 500):
            if perfect(i):
                room = i
                count += 1
            if count == int(str(perc - (perc % 10))[0]):
                break
    else:
        for i in range(500, 1000):
            if ramanujan(i):
                room = i
                count += 1
                print(count)
            if (len(str(count+2)) == 2 and len(str(perc)) == 2) or (len(str(count)) == 2 and len(str(perc)) == 3):
                break
        if room == 0:
            for i in range(500, 1000):
                if perfect_square(i):
                    room = i
    print(room)


def perfect(n):
    sumofdivs = 0
    for i in range(1, n):
        if n % i == 0:
            sumofdivs += i
    if n == sumofdivs:
        return True
    else:
        return False

def ramanujan(n):
    for i in range(1, n//5):
        for j in range(1, n//5):
            if i**3 + j**3 == n:
                return True
    return False

def perfect_square(n):
    for i in range(1, n):
        if i**2 == n:
            return True
    return False

main()