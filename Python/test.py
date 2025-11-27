import numpy as np
import matplotlib.pyplot as plt

# Frequency range
omega = np.logspace(-1, 2, 100)  # Log scale: 0.1 to 100
magnitude = 10 / (omega * np.sqrt(1 + omega**2))  # Compute magnitude
magnitude_db = 20 * np.log10(magnitude)  # Convert to dB

# Plot
plt.figure(figsize=(8, 6))
plt.semilogx(omega, magnitude_db)  # X-axis on log scale
plt.title("Magnitude Plot")
plt.xlabel("Frequency (rad/s)")
plt.ylabel("Magnitude (dB)")
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.show()
