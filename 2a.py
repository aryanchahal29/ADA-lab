import matplotlib.pyplot as plt

# Data
n = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000]
time = [0.000012, 0.000020, 0.000032, 0.000106, 0.000269, 0.000967, 0.001489, 0.001926, 0.002205]

# Plot
plt.figure(figsize=(8, 5))  # bigger figure size
plt.plot(n, time, marker='o', color='black', linewidth=1.5, markersize=6, label="Merge Sort")

# Labels & Title
plt.xlabel('Number of Elements (n)', fontsize=12)
plt.ylabel('Time Taken (seconds)', fontsize=12)
plt.title('Merge Sort Time vs n', fontsize=14)

# Grid & Legend
plt.grid(True, linestyle="--", alpha=0.6)
plt.legend()

# Show plot
plt.show()
