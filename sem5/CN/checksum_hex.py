def hex_to_binary(hex_string: str) -> str:
    return bin(int(hex_string, 16))[2:].zfill(8)

def calculate_checksum(hex_data: list) -> int:
    checksum = 0
    for hex_value in hex_data:
        binary_value = hex_to_binary(hex_value)
        checksum += int(binary_value, 2)
    return checksum & 0xFF

def verify_checksum(hex_data: list, received_checksum: int) -> bool:
    calculated_checksum = calculate_checksum(hex_data)
    return calculated_checksum == received_checksum

def main():
    # Get input from user for sent data
    sent_data = input("Enter the data to be sent (in hex, separated by commas): ").strip().split(',')
    sent_data = [x.strip() for x in sent_data]
    checksum = calculate_checksum(sent_data)
    print(f"Sent Data: {sent_data}")
    print(f"Calculated Checksum: {checksum:02X}")

    # Simulate transmission and verification
    received_data = input("Enter the received data (in hex, separated by commas): ").strip().split(',')
    received_data = [x.strip() for x in received_data]
    received_checksum = checksum  # In a real scenario, this would be received along with the data

    if verify_checksum(received_data, received_checksum):
        print("No error in transmission.")
    else:
        print("Error detected in transmission.")

if __name__ == "__main__":
    main()