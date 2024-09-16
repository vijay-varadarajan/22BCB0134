def calculate_parity_bit(data, parity_type):
    count_ones = data.count('1')
    if parity_type == 'even':
        return '0' if count_ones % 2 == 0 else '1'
    elif parity_type == 'odd':
        return '1' if count_ones % 2 == 0 else '0'
    else:
        raise ValueError("Invalid parity type. Choose 'even' or 'odd'.")

def encode_message(data, parity_type):
    parity_bit = calculate_parity_bit(data, parity_type)
    return parity_bit, data + parity_bit

def check_parity(data, parity_type):
    received_data = data[:-1]
    received_parity_bit = data[-1]
    calculated_parity_bit = calculate_parity_bit(received_data, parity_type)
    return calculated_parity_bit, received_parity_bit == calculated_parity_bit

def main():
    data = input("Enter the binary data: ")
    parity_type = input("Enter the parity type (even/odd): ").lower()

    parity_bit, encoded_message = encode_message(data, parity_type)
    print(f"Parity_bit: {parity_bit}")
    print(f"Encoded message with parity bit: {encoded_message}")

    # Simulate transmission and reception
    received_message = input("Enter the received message: ")

    receiver_side_parity_bit, verification = check_parity(received_message, parity_type)

    print(f"Receiver side calculated parity bit: {receiver_side_parity_bit}")
    if verification:
        print("The message was transmitted correctly.")
    else:
        print("The message has an error.")

if __name__ == "__main__":
    main()