def crc_remainder(input_bitstring, polynomial_bitstring, initial_filler):
    polynomial_length = len(polynomial_bitstring)
    bitstring = input_bitstring + initial_filler * (polynomial_length - 1)
    polynomial = int(polynomial_bitstring, 2)

    for i in range(len(input_bitstring)):
        if bitstring[i] == '1':
            segment = int(bitstring[i:i + polynomial_length], 2)
            bitstring = (bitstring[:i] + 
                         bin(segment ^ polynomial)[2:].zfill(polynomial_length) + 
                         bitstring[i + polynomial_length:])
    return bitstring[-(polynomial_length - 1):]

def crc_check(received_data, polynomial_bitstring, initial_filler):
    polynomial_length = len(polynomial_bitstring)
    bitstring = received_data + initial_filler * (polynomial_length - 1)
    polynomial = int(polynomial_bitstring, 2)

    for i in range(len(received_data)):
        if bitstring[i] == '1':
            segment = int(bitstring[i:i + polynomial_length], 2)
            bitstring = (bitstring[:i] + 
                         bin(segment ^ polynomial)[2:].zfill(polynomial_length) + 
                         bitstring[i + polynomial_length:])
    remainder = bitstring[-(polynomial_length - 1):]
    return remainder == '0' * (polynomial_length - 1), remainder

def main():
    # Get input from user for sent data
    sent_data = input("Enter the data to be sent (in binary): ").strip()
    
    # Get the polynomial (divisor) from the user
    polynomial = input("Enter the polynomial (divisor) in binary: ").strip()
    initial_filler = '0'
    
    # Calculate CRC
    crc_value = crc_remainder(sent_data, polynomial, initial_filler)
    encoded_data = sent_data + crc_value
    print(f"Sent Data: {sent_data}")
    print(f"CRC Value: {crc_value}")
    print(f"Encoded Data: {encoded_data}")

    # Simulate transmission and verification
    received_data = input("Enter the received data (in binary): ").strip()
    
    is_valid, remainder = crc_check(received_data, polynomial, initial_filler)
    print(f"CRC Remainder on Receiver Side: {remainder}")
    
    if is_valid:
        print("No error in transmission.")
    else:
        print("Error detected in transmission.")

if __name__ == "__main__":
    main()