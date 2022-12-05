n,c1,c2,c3,tx2,ty2,tx3,ty3,out2,out3,avg2,avg3=int(input("Enter the no of points to enter- ")),[],[],[],0,0,0,0,[],[],0,0
a, b, c=map(int,input("Enter the values- ").split())
for i in range(n):
    x,y = map(int,input("Enter x and y: ").split())
    if a*x+b*y+c == 0:
        c1.append([x, y])
    elif a*x+b*y+c < 0:
        c2.append([x, y])
    elif a*x+b*y+c > 0:
        c3.append([x, y])
for j in range(len(c2)):
    tx2 += c2[j][0]
    ty2 += c2[j][1]
cen2=[tx2/len(c2), ty2/len(c2)]
for j in range(len(c3)):
    tx3 += c3[j][0]
    ty3 += c3[j][1]
cen3=[tx3/len(c3), ty3/len(c3)]
for k in range(len(c2)):
    avg2 += ((cen2[0] - c2[k][0])**2 + (cen2[1]-c2[k][1])**2)**0.5
a2=avg2/len(c2)  
for k in range(len(c3)):
    avg3+=(((cen3[0]-c3[k][0])**2+(cen3[1]-c3[k][1])**2)**0.5)
a3=avg3/len(c3)
for k in range(len(c2)):
    if (((cen2[0]-c2[k][0])**2+(cen2[1]-c2[k][1])**2)**0.5)>a2:
        out2.append([c2[k][0],c2[k][1]])
for k in range(len(c3)):
    if (((cen3[0]-c3[k][0])**2+(cen3[1]-c3[k][1])**2)**0.5)>a3:
        out3.append([c3[k][0],c3[k][1]])
out2.sort()
out3.sort()
print("Outlier of C2 is- " + str(out2) + "\n" +"Outlier of C3 is- ", out3)