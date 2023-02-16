import csv

one = {'A':1, 'B':2, 'C':3}
two = {'A':4, 'B':5, 'C':6}
file = open('test.csv', 'w')
writer = csv.DictWriter(file, fieldnames=['A', 'B', 'C'])
writer.writeheader()
writer.writerow(one)
writer.writerow(two)
file.close()

file = open('test.csv', 'r')
reader = csv.DictReader(file)
for row in reader:
    print(row)
file.close()

file = open('test.csv', 'r')
read = csv.reader(file)
for row in read:
    print(row)
file.close()

file = open('test.csv', 'a')
write = csv.writer(file)
write.writerow([1,2,3,4])
file.close()
