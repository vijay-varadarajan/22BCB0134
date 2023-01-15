lst = eval(input())
new_lst = []
if len(lst) % 2 == 0:
    n = len(lst)//2
else:
    n = len(lst)//2 + 1
for i in range(n):
    new_lst.append(max(lst))
    new_lst.append(min(lst))
    lst.remove(max(lst))
    if i == n-1 and n%2 != 0:
        continue
    lst.remove(min(lst))
new_lst.remove(new_lst[-1])
print(new_lst)
