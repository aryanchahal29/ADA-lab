import matplotlib.pyplot as plt

# Data points (replace with actual C program results if needed)
sizes = [10, 50, 100, 500, 1000, 3000, 5000, 7000, 10000, 20000]
times = [0.00000001, 0.00000001, 0.00000002, 0.00000002, 0.00000003,
         0.00000003, 0.00000004, 0.00000004, 0.00000004, 0.00000004]

# Create figure + axis
fig, ax = plt.subplots(figsize=(9, 5))

# Plot with style
ax.plot(sizes, times, 's--g', linewidth=1.5, markersize=5)  # green squares with dashed line

# Titles and labels
ax.set_title("Binary Search Performance", fontsize=14, fontweight='bold')
ax.set_xlabel("Array Size (n)", fontsize=12)
ax.set_ylabel("Execution Time (sec)", fontsize=12)

# Grid styling
ax.grid(True, linestyle=":", alpha=0.7)

# Add values above points
for x, y in zip(sizes, times):
    ax.annotate(f"{y:.6f}", (x, y), textcoords="offset points", xytext=(0, 6), ha="center", fontsize=8)

plt.tight_layout()
plt.show()
