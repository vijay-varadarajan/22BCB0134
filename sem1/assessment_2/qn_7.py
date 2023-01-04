import itertools as it

string = input().strip().split(' ')
lucky_num = int(input())
str_len = int(input())

value = {}
count = 1
for let in string:
    value[let] = count
    count += 1
print(value)

combs = list(it.combinations(string, str_len))
print(combs)

lucky_combs = []

for comb in combs:
    summ = 0
    for letter in comb:
        summ += value[letter]
    if summ == lucky_num:
        lucky_combs.append(comb)

for comb in lucky_combs:
    print(*comb, sep='')
