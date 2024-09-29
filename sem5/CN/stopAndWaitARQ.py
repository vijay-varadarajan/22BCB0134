# frame lost

'''
import random
import time

def stop_and_wait_arq_with_frame_loss(frames=5):
    """
    Simulates Stop-and-Wait ARQ (Automatic Repeat Request) protocol with frame loss.
    Parameters:
        frames (int): The total number of frames to be sent.
    """
    frame_sent = 0

    print("Stop-and-Wait ARQ with Frame Loss Simulation\n")

    while frame_sent < frames:
        print(f"Sending Frame {frame_sent + 1}...")

        # Simulate frame transmission with a 50% chance of loss
        if random.choice([True, False]):
            print(f"Frame {frame_sent + 1} is lost.\n")
        else:
            print(f"Frame {frame_sent + 1} sent successfully.")
            ack_received = True

            # Simulate receiving acknowledgment
            if ack_received:
                print(f"Acknowledgment received for Frame {frame_sent + 1}\n")
                frame_sent += 1
            else:
                print(f"Timeout! Resending Frame {frame_sent + 1}...\n")
        
        time.sleep(1)  # Simulate network delay

if __name__ == "__main__":
    # Seed the random number generator
    random.seed(time.time())

    # Simulate Stop-and-Wait ARQ with frame loss for 5 frames
    stop_and_wait_arq_with_frame_loss()


# ACK lost
'''

import random
import time

def stop_and_wait_arq_with_ack_loss(frames=5):
    """
    Simulates Stop-and-Wait ARQ (Automatic Repeat Request) protocol with ACK loss.

    Parameters:
        frames (int): The total number of frames to be sent.
    """
    frame_sent = 0
    ack_received = False

    print("Stop-and-Wait ARQ with ACK Loss Simulation\n")

    while frame_sent < frames:
        print(f"Sending Frame {frame_sent + 1}...")
        print(f"Frame {frame_sent + 1} sent successfully.")

        # Simulate ACK loss with a 50% chance
        if random.choice([True, False]):
            print(f"ACK for Frame {frame_sent + 1} is lost.")
            ack_received = False
        else:
            print(f"Acknowledgment received for Frame {frame_sent + 1}\n")
            ack_received = True

        if not ack_received:
            print(f"Timeout! Resending Frame {frame_sent + 1}...\n")
        else:
            frame_sent += 1
            ack_received = False

        time.sleep(1)  # Simulate network delay

if __name__ == "__main__":
    # Seed the random number generator
    random.seed(time.time())

    # Simulate Stop-and-Wait ARQ with ACK loss for 5 frames
    stop_and_wait_arq_with_ack_loss()
