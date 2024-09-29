'''
# frame lost

import random
import time

def go_back_n_arq_with_frame_loss(window_size=4, total_frames=10):
    """
    Simulates the Go-Back-N ARQ (Automatic Repeat Request) protocol with frame loss.

    Parameters:
        window_size (int): The size of the sliding window.
        total_frames (int): The total number of frames to be sent.
    """
    next_frame_to_send = 1
    ack_received = 0

    print("Go-Back-N ARQ with Frame Loss Simulation\n")

    while ack_received < total_frames:
        # Send frames within the window
        for i in range(window_size):
            if next_frame_to_send > total_frames:
                break

            print(f"Sending Frame {next_frame_to_send}...")

            # Simulate frame transmission with a 50% chance of loss
            if random.choice([True, False]):
                print(f"Frame {next_frame_to_send} is lost.")
                break  # Stop sending more frames; go back to retransmit
            else:
                print(f"Frame {next_frame_to_send} sent successfully.")
                next_frame_to_send += 1

        # Simulate acknowledgment reception with a 50% chance of failure
        if random.choice([True, False]):
            ack_received += 1
            print(f"Acknowledgment received for frames up to {ack_received}.")
        else:
            print("No acknowledgment received. Retransmitting frames...")
            next_frame_to_send = ack_received + 1

        print()  # Print a blank line for clarity
        time.sleep(1)  # Simulate network delay

if __name__ == "__main__":
    # Seed the random number generator
    random.seed(time.time())

    # Simulate Go-Back-N ARQ with frame loss (window size of 4 and 10 frames to send)
    go_back_n_arq_with_frame_loss()

# ack lost
'''
import random
import time

def go_back_n_arq_with_ack_loss(window_size, frames=10):
    """
    Simulates Go-Back-N ARQ (Automatic Repeat Request) protocol with ACK loss.

    Parameters:
        window_size (int): The size of the sliding window.
        frames (int): The total number of frames to be sent.
    """
    next_frame_to_send = 1
    ack_received = 0

    print("Go-Back-N ARQ with ACK Loss Simulation\n")

    while ack_received < frames:
        # Send frames within the window
        for i in range(window_size):
            if next_frame_to_send <= frames:
                print(f"Sending Frame {next_frame_to_send}...")
                print(f"Frame {next_frame_to_send} sent successfully.")
                next_frame_to_send += 1
            else:
                break

        # Simulate ACK loss
        if random.choice([True, False]):
            print(f"ACK for frames up to {ack_received + 1} is lost.")
            print("No acknowledgment received. Retransmitting...\n")
            next_frame_to_send = ack_received + 1
        else:
            print(f"Acknowledgment for frames up to {next_frame_to_send - 1} received.")
            ack_received = next_frame_to_send - 1

        print()  # Print a newline for better readability
        time.sleep(1)  # Simulate network delay

if __name__ == "__main__":
    # Seed the random number generator
    random.seed(time.time())

    # Simulate Go-Back-N ARQ with ACK loss, window size 4
    go_back_n_arq_with_ack_loss(4)
