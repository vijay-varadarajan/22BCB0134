import re

def main():
    string = input()
    prime = True
    if match := re.search(r"[0-9]+", string):
        checkprime(match[0])
        print(f"Yes. {prime}")
    else:
        print("No")

def checkprime(n):
    for i in range(2, (int(n))//2):
        if int(n) % i == 0:
            prime = False