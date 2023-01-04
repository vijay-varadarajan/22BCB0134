import re, sys

def main():
    inp = input().strip().rstrip(']').lstrip('[').split(',')
    if len(inp) <3:
        sys.exit('\u201dInvalid Data\u201d')
        
    integers = []
    reals = []
    imaginaries = []
    strings = []
    
    primenumber, palindrome = False, False
    for element in inp:
        element = element.strip()
        integer = re.findall(r"^ *([+-]?[0-9]+) *$", element)
        if integer:
            for num in integer:
                integers.append(num)
                if int(num) > 0 and checkprime(num):
                    primenumber = True
                    break
        string = re.findall('^(?:[\u201d]{1}|[\u201c]{1})([A-Za-z0-9_]+)(?:[\u201d]{1}[\u201c]{1})$', element)
        if string:    
            for word in string:
                strings.append(word)
                if checkpalindrome(word.lower()):
                    palindrome = True
                    break
        complx = re.search(r"^\((([+-]?[0-9]+)([+-]?[0-9]+)[j])\)$", element)
        if complx:
            reals.append(complx.group(2))
            imaginaries.append(complx.group(3))
            
    if primenumber and not palindrome:
        print(ifprime(reals, imaginaries, integers, strings))
    elif not primenumber and palindrome:
        print(ifpalindrome(reals, imaginaries, integers, strings))
    elif primenumber and palindrome:
        print(ifboth(inp))
    else:
        print(ifnone(reals, imaginaries, integers, strings))
        
def checkprime(n):
    for i in range(2, int(n)//2 + 1):
        if int(n) % i == 0:
            return False
    return True
    
def checkpalindrome(text):
    if text == text[::-1]:
        return True
    return False
    
def ifprime(reals, imaginaries, integers, strings):
    output = '['
    for word in strings:
        output += f"\u201c{word[::-1]}\u201d,"
    for num in integers:
        output += f"{str(int(num))},"
    for i in range(len(reals)):
        imag = str(imaginaries[i])
        if imag[0]  == '+':
            imag = imag.lstrip('+')
        output += f"({imag}{reals[i]}j),"
    output += '\b]'
    return output
    
def ifpalindrome(reals, imaginaries, integers, strings):
    output = '['
    for i in range(len(reals)):
        output += f"({reals[i]}{-int(imaginaries[i])}j),"
    for word in strings:
        output += f"\u201d{word}\u201d,"
    for num in integers:
        output += f"{-int(num)},"
    output += "\b]"
    return output
    
def ifboth(inp):
    return inp[len(inp)//2]
    
def ifnone(reals, imaginaries, integers, strings):
    output = '['
    for word in strings:
        for letter in word:
            if str(letter).isupper():
                output += f"\u201c{letter}\u201d,"
            else:
                output += f"\u201d{letter}\u201d,"
    for num in integers:
        output += f'{int(num)},'
    for i in range(len(reals)):
        output += f"({reals[i]}{imaginaries[i]}j),"
    output += "\b]"
    
if __name__ == "__main__":
    main()