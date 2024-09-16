def calculate_parity_bits(m):
    # Calculate the number of parity bits needed
    for i in range(m):
        if 2**i >= m + i + 1:
            return i

def get_parity_positions(n):
    # Get positions of parity bits
    return [2**i for i in range(n)]

def insert_parity_bits(data, parity_positions):
    # Insert parity bits into the data
    j = 0
    m = len(data)
    res = ''
    for i in range(1, m + len(parity_positions) + 1):
        if i in parity_positions:
            res += '0'
        else:
            res += data[j]
            j += 1
    return res

def calculate_parity(data, parity_positions):
    # Calculate parity bits values
    n = len(parity_positions)
    data = list(data)
    for i in range(n):
        parity_pos = parity_positions[i]
        parity = 0
        for j in range(1, len(data) + 1):
            if j & parity_pos == parity_pos:
                parity ^= int(data[j - 1])
        data[parity_pos - 1] = str(parity)
    return ''.join(data)

def encode(data):
    m = len(data)
    n = calculate_parity_bits(m)
    parity_positions = get_parity_positions(n)
    data_with_parity = insert_parity_bits(data, parity_positions)
    encoded_data = calculate_parity(data_with_parity, parity_positions)
    return encoded_data

def decode(received_data):
    n = calculate_parity_bits(len(received_data))
    if n is None:
        raise ValueError("Invalid data length for Hamming code.")
    parity_positions = get_parity_positions(n)
    error_pos = 0
    
    for i in range(n):
        parity_pos = parity_positions[i]
        parity = 0
        for j in range(1, len(received_data) + 1):
            if j & parity_pos == parity_pos:
                parity ^= int(received_data[j - 1])
        if parity != 0:
            error_pos += parity_pos
            
    if error_pos != 0:
        print(f"Error detected at bit position: {error_pos}")
        received_data = list(received_data)
        received_data[error_pos - 1] = '1' if received_data[error_pos - 1] == '0' else '0'
        received_data = ''.join(received_data)
        print(f"Corrected received data: {received_data}")
    else:
        print("No error detected.")
    
    decoded_data = ''.join([received_data[i - 1] for i in range(1, len(received_data) + 1) if i not in parity_positions])
    return decoded_data

if __name__ == "__main__":
    data = input("Enter the data to be encoded: ")
    encoded_data = encode(data)
    print(f"Encoded data: {encoded_data}")
    
    received_data = input("Enter the received encoded data: ")
    decoded_data = decode(received_data)
    print(f"Decoded data: {decoded_data}")