import matplotlib.pyplot as plt

# Input values
n_values = [1000, 3000, 6000, 10000, 15000, 20000, 25000]
time_values = [0.001441, 0.010001, 0.028182, 0.047659, 0.078468, 0.139747, 0.213696]

# Plot graph
plt.plot(n_values, time_values, 'o-', color='black', linewidth=1.5)

# Add labels and title
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.title("Insertion Sort: Time vs Input Size")

# Enable grid
plt.grid(True)

# Show the plot
plt.show()
