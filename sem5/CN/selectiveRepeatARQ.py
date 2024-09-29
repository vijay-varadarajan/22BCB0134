# frame lost
'''
import random
import time

def selective_repeat_arq_with_frame_loss(window_size, frames=10):
    """
    Simulates Selective Repeat ARQ with frame loss.

    Parameters:
        window_size (int): The size of the sliding window.
        frames (int): The total number of frames to be sent.
    """
    sent_frames = {}
    ack_received = set()

    print("Selective Repeat ARQ with Frame Loss Simulation\n")

    for i in range(1, frames + 1):
        sent_frames[i] = False

    frame_to_send = 1

    while len(ack_received) < frames:
        # Send frames in the window
        for i in range(window_size):
            if frame_to_send <= frames and not sent_frames[frame_to_send]:
                print(f"Sending Frame {frame_to_send}...")
                if random.choice([True, False]):  # Simulating frame loss
                    print(f"Frame {frame_to_send} is lost.")
                else:
                    print(f"Frame {frame_to_send} sent successfully.")
                    sent_frames[frame_to_send] = True  # Mark as sent
                frame_to_send += 1
            else:
                break

        # Receive acknowledgments
        for frame in range(1, frames + 1):
            if sent_frames[frame] and frame not in ack_received:
                if random.choice([True, False]):
                    print(f"ACK for Frame {frame} received.")
                    ack_received.add(frame)  # Acknowledge frame
                else:
                    print(f"ACK for Frame {frame} lost. Frame {frame} will be resent.")
                    sent_frames[frame] = False  # Mark frame to be resent
        
        # Adjust window to slide forward based on ACKs received
        first_unacked = min([f for f in range(1, frames + 1) if f not in ack_received], default=frames+1)
        frame_to_send = first_unacked
        
        print(f"Window slides after successful ACKs. Current ACKed frames: {sorted(ack_received)}\n")
        time.sleep(1)

if __name__ == "__main__":
    random.seed(time.time())

    # Simulate Selective Repeat ARQ with frame loss, window size 4
    selective_repeat_arq_with_frame_loss(4)


# ACK lost

'''
import random
import time

def selective_repeat_arq_with_ack_loss(window_size, frames=10):
    """
    Simulates Selective Repeat ARQ with ACK loss.

    Parameters:
        window_size (int): The size of the sliding window.
        frames (int): The total number of frames to be sent.
    """
    sent_frames = {}
    ack_received = set()

    print("Selective Repeat ARQ with ACK Loss Simulation\n")

    for i in range(1, frames + 1):
        sent_frames[i] = False

    frame_to_send = 1

    while len(ack_received) < frames:
        # Send frames in the window
        for i in range(window_size):
            if frame_to_send <= frames and not sent_frames[frame_to_send]:
                print(f"Sending Frame {frame_to_send}...")
                print(f"Frame {frame_to_send} sent successfully.")
                sent_frames[frame_to_send] = True  # Mark as sent
                frame_to_send += 1
            else:
                break

        # Receive acknowledgments with possibility of ACK loss
        for frame, status in sent_frames.items():
            if status and frame not in ack_received:
                if random.choice([True, False]):
                    print(f"ACK for Frame {frame} received.")
                    ack_received.add(frame)
                else:
                    print(f"ACK for Frame {frame} lost. Frame {frame} will be resent.")

        # Retransmit lost frames
        for frame in range(1, frame_to_send):
            if frame not in ack_received:
                print(f"Retransmitting Frame {frame}...")
                print(f"Frame {frame} sent successfully.")

        print(f"Window slides after successful ACKs. Current ACKed frames: {sorted(ack_received)}\n")
        time.sleep(1)

if __name__ == "__main__":
    random.seed(time.time())

    # Simulate Selective Repeat ARQ with ACK loss, window size 4
    selective_repeat_arq_with_ack_loss(4)
