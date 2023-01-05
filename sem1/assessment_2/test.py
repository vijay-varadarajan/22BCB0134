import re

n = input()
n = re.sub("\u201d", '"', n)
n = re.sub("\u201c", '"', n)
n = eval(n)
p,pal,c,s,l,l1,l2,l3=0,0,0,"",[0,0,0],[],[],[]
for i in n:
    c,s=0,""
    if(type(i)==int):
        l[0]+=1
        for j in range(1,i+1):
            if(i%j==0):
                c+=1
        if(c==2):
            p+=1
        l1.append(i)
        l2.append(-i)
        l3.append(i)
    if(type(i)==str):
        l[1]+=1
        for j in i:
            s=j+s
            l3.append(j)
        if(s.lower()==i.lower()):
            pal+=1
        l1.append(s)
        l2.append(i)
    if(type(i)==complex):
        l[2]+=1
        l1.append(complex(i.imag,i.real))
        l2.append(i.conjugate())
        l3.append(i)
if(l[0]>0 and l[1]>0 and l[2]>0):
    if(p>0 and pal==0):
        l1 = str(l1)
        l1 = l1.replace("'", '\u201d')
        print(l1)
    elif(pal>0 and p==0):
        print(l2)
    elif(p>0 and pal>0):
        print(n[len(n)//2])
    else:
        print(l3)
else:
    print("Invalid Data")
