import matplotlib.pyplot as plt

# Bubble Sort results
sizes = [1000, 3000, 6000, 10000, 15000, 20000, 25000]
exec_times = [0.003393, 0.025266, 0.063643, 0.153351, 0.372289, 0.677883, 1.088778]

plt.figure(figsize=(7, 5))
plt.plot(sizes, exec_times, marker='D', linestyle='-', color='red', linewidth=1.6)

plt.xlabel("Input Size (n)", fontsize=11)
plt.ylabel("Execution Time (seconds)", fontsize=11)
plt.title("Bubble Sort: Time vs Input Size", fontsize=13)

plt.grid(linestyle="--", alpha=0.6)
plt.tight_layout()
plt.show()

