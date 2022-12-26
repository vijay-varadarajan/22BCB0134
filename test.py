def main():
    lst = input().rstrip(']').lstrip('[').split(',')
    new_lst = []
    appended = False
    print(lst)
    for i in lst:
        i = i.strip()
        if i.isdigit() == True:
            if checkprime(int(i)) == True:
                for i in lst:
                    if not i.isdigit() and (i[0] == '(' and i[-1] == ')'):
                        new_lst.append(reverse(i))
                    if i[0] == '(' and i[-1] == ')':
                        if '+' in i:
                            comp = i.split('+')
                            conj = 
                        7+5j  =>  5+7j


                appended = True
        if appended:
            break

    print(new_lst)

#['lsgn', 'ijsf', 3, 4, ()]
def checkprime(n):
    for i in range(2 ,n//2):
        if n % i == 0:
            return False
    return True

def reverse(s):
    return s[::-1]

main()