t = int(input())

for i in range(t):
    s = input()
    cnt = ord(s[0]) - 97
    print(s)
    if len(s) <= 4 or len(s) > 10:
        print("string length is in unacceptable range.\n")
        continue
    for i in range(len(s)):
        c = chr(ord(s[i]) + cnt + i)
        if (ord(c) <= 122):
            print(c, end='')
        else:
            while (ord(c) > 122):
                c = chr(96 + (ord(c) % 122))
            print(c, end='')
    print()
    
        
