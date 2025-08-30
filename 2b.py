import matplotlib.pyplot as plt

# Input sizes and corresponding execution times
n = [1000, 3000, 6000, 10000, 15000, 20000, 25000]
time = [0.000134, 0.000442, 0.000956, 0.001668, 0.002665, 0.003652, 0.005059]

# Plotting the graph
plt.figure(figsize=(7, 5))  # set figure size
plt.plot(n, time, marker='o', color='black', linestyle='-', linewidth=1.5, markersize=6)

# Adding labels and title
plt.xlabel('Number of Elements (n)', fontsize=12)
plt.ylabel('Time Taken (seconds)', fontsize=12)
plt.title('Merge Sort Time vs n', fontsize=14, fontweight='bold')

# Show grid
plt.grid(True, linestyle='--', alpha=0.7)

# Show the plot
plt.show()
