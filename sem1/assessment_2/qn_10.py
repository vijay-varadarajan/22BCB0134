import string

def main():
    strng = input().lower()
    
    invalid = False
    for letter in strng:
        if letter not in string.ascii_lowercase:
            invalid = True
    if invalid:
        print("Invalid input")
    else:
        palind = False
        for i in range(len(strng), 0, -1):
            for j in range(len(strng) - i + 1):
                if palindrome(strng[j:i+j]):
                    palind = True
                    print(i)
                    break
            if palind:
                break

def palindrome(string):
    if string == string[::-1]:
        return True
    return False

main()