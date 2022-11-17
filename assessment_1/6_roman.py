def main():
    num = int(input("Enter any integer: "))
    roman = ''
    
    if num == 0:
        roman += 'nulla'
    elif num < 0:
        roman += '- '
    num = int(str(num).strip('-'))

    digits = []
    for n in range(len(str(num)), 0, -1):
        digits.append(num % (10**n) - num % (10**(n-1)))

    for n in range(len(digits) + str(num).count('4') + str(num).count('9')):
        if '4' in str(digits[n]) or '9' in str(digits[n]):
            digits.insert(n+1, digits[n] + 10**(len(str(digits[n])) - 1))
            digits[n] = 10**(len(str(digits[n])) - 1)

    print(f"Roman numeral: {digtoroman(digits, roman)}")


def digtoroman(digits, roman):
    
    for digit in digits:
        while digit >= 1000:
            roman += 'M'
            digit -= 1000

        while digit >= 500:
            roman += 'D'
            digit -= 500

        while digit >= 100:
            roman += 'C'
            digit -= 100

        while digit >= 50:
            roman += 'L'
            digit -= 50

        while digit >= 10:
            roman += 'X'
            digit -= 10

        while digit >= 5:
            roman += 'V'
            digit -= 5

        while digit >= 1:
            roman += 'I'
            digit -= 1

    return roman

main()