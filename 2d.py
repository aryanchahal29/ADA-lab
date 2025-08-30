import matplotlib.pyplot as plt

# data points
input_sizes = [1000, 3000, 6000, 10000, 15000, 20000, 25000]
times_taken = [0.002421, 0.016322, 0.041844, 0.069382, 0.142883, 0.253269, 0.394183]

plt.figure(figsize=(8, 5))
plt.plot(input_sizes, times_taken, marker='^', linestyle='-', color='green', markersize=6)

plt.xlabel("Input Size (n)", fontsize=11)
plt.ylabel("Execution Time (seconds)", fontsize=11)
plt.title("Selection Sort: Time Complexity Experiment", fontsize=13)

plt.grid(True, which="both", linestyle="--", linewidth=0.7, alpha=0.7)
plt.tight_layout()
plt.show()
