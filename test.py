import numpy as np
import sounddevice as sd
import time

def generate_sound(frequency, duration, volume):
    """
    Generate a sound wave with the specified frequency, duration, and volume.

    Parameters:
    frequency (float): The frequency of the sound in Hertz (Hz).
    duration (float): The duration of the sound in seconds.
    volume (float): The volume of the sound in decibels (dB).

    Returns:
    numpy.ndarray: The generated sound wave.
    """
    sample_rate = 44100  # Common sample rate for audio
    t = np.linspace(0, duration, int(duration * sample_rate), False)
    wave = np.sin(2 * np.pi * frequency * t)
    amplified_wave = wave * (10 ** (volume / 20))  # Convert volume to amplitude
    return amplified_wave

def run_sound_treatments():
    """
    Generate and play the specified sound treatments.
    """
    low_freq = 125
    med_freq = 1250
    high_freq = 4500

    low_volume = 0  # 70 dB
    med_volume = 5  # 80 dB
    high_volume = 10  # 90 dB

    short_duration = 2  # 2 sec
    med_duration = 3    # 3 sec
    long_duration = 4  # 4 sec

    print("Running sound treatments...")
    print("Control Group: No sound exposure.")

    print(f"\nLow Frequency ({low_freq}) Treatments:")
    print(f"Low Intensity ({low_volume} dB), Duration: {short_duration} seconds")
    sd.play(generate_sound(low_freq, short_duration, low_volume), blocking=True)
    # print(f"Moderate Intensity ({med_volume} dB), Duration: {med_duration} seconds")
    # sd.play(generate_sound(low_freq, med_duration, med_volume), blocking=True)
    # print(f"High Intensity ({high_volume} dB), Duration: {long_duration} seconds")
    # sd.play(generate_sound(low_freq, long_duration, high_volume), blocking=True)

    print(f"\nMedium Frequency ({med_freq}) Treatments:")
    # print(f"Low Intensity ({low_volume} dB), Duration: {short_duration} seconds")
    # sd.play(generate_sound(med_freq, short_duration, low_volume), blocking=True)
    print(f"Moderate Intensity ({med_volume} dB), Duration: {med_duration} seconds")
    sd.play(generate_sound(med_freq, med_duration, med_volume), blocking=True)
    # print(f"High Intensity ({high_volume} dB), Duration: {long_duration} seconds")
    # sd.play(generate_sound(med_freq, long_duration, high_volume), blocking=True)

    print(f"\nHigh Frequency ({high_freq}) Treatments:")
    # print(f"Low Intensity ({low_volume} dB), Duration: {short_duration} seconds")
    # sd.play(generate_sound(high_freq, short_duration, low_volume), blocking=True)
    # print(f"Moderate Intensity ({med_volume} dB), Duration: {med_duration} seconds")
    # sd.play(generate_sound(high_freq, med_duration, med_volume), blocking=True)
    print(f"High Intensity ({high_volume} dB), Duration: {long_duration} seconds")
    sd.play(generate_sound(high_freq, long_duration, high_volume), blocking=True)

    print("\nNotes:")
    print("- Treatments are played from 6:00 AM to synchronize with the natural photosynthetic cycle.")
    print("- The control group receives no sound exposure.")

if __name__ == "__main__":
    run_sound_treatments()
