import matplotlib.pyplot as plt

# Input data
sizes = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000]
times = [0.000000, 0.000000, 0.000001, 0.000002, 0.000005,
         0.000013, 0.000019, 0.000023, 0.000026, 0.000028]

# Create the figure and axis
fig, ax = plt.subplots(figsize=(9, 5))

# Plot line graph with markers
ax.plot(sizes, times, 'o-r', linewidth=1.5, markersize=6)

# Labels and title
ax.set_title("Time Complexity of Linear Search", fontsize=14, fontweight='bold')
ax.set_xlabel("Array Length", fontsize=12)
ax.set_ylabel("Execution Time (sec)", fontsize=12)
ax.grid(True, linestyle="--", alpha=0.6)

# Annotating points with values
for x, y in zip(sizes, times):
    ax.annotate(f"{y:.6f}", (x, y), textcoords="offset points", xytext=(0, 8), ha='center', fontsize=8)

plt.tight_layout()
plt.show()
