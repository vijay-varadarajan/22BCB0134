def calculate_checksum(data: str) -> int:
    checksum = 0
    for char in data:
        checksum += int(char, 2)
    return checksum & 0xFF

def verify_checksum(data: str, received_checksum: int):
    calculated_checksum = calculate_checksum(data)
    return calculated_checksum, calculated_checksum == received_checksum

def main():
    # Get input from user for sent data
    sent_data = input("Enter the data to be sent (in binary): ").strip()
    checksum = calculate_checksum(sent_data)
    print(f"Sent Data: {sent_data}")
    print(f"Calculated Checksum: {checksum}")

    # Simulate transmission and verification
    received_data = input("Enter the received data (in binary): ").strip()
    received_checksum = checksum  # In a real scenario, this would be received along with the data

    calculated_checksum, verification = verify_checksum(received_data, received_checksum)
    
    print(f"Calculated Checksum: {calculated_checksum}")
    if verification:
        print("No error in transmission.")
    else:
        print("Error detected in transmission.")

if __name__ == "__main__":
    main()