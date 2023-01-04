pwds = input().split(',')
upcase = ('A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z')
locase = ('a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z')
nums = (0,1,2,3,4,5,6,7,8,9)
splchars = ('$','#','@')
valids = []
for pwd in pwds:
    count = 0
    if 6 <= len(pwd) <= 12:
        count += 1
    for lo in locase:
        if lo in pwd:
            count += 1
            break
    for num in nums:
        if str(num) in pwd:
            count += 1
            break
    for char in splchars:
        if char in pwd:
            count += 1
            break
    if count == 4:
        valids.append(pwd)
    else:
        continue
if not valids:
    print("invaild")
else:
    print(*valids, sep=',')