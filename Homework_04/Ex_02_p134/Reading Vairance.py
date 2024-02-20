import matplotlib.pyplot as plt

# Read variance data from files
bs_variance_file = open("bs_variance.txt", "r")
vasicek_variance_file = open("vasicek_variance.txt", "r")
hw_variance_file = open("hw_variance.txt", "r")

bs_variance = float(bs_variance_file.readline().split(":")[1].strip())
vasicek_variance = float(vasicek_variance_file.readline().split(":")[1].strip())
hw_variance = float(hw_variance_file.readline().split(":")[1].strip())

# Close files
bs_variance_file.close()
vasicek_variance_file.close()
hw_variance_file.close()

# Plot histograms of distributions (you need to provide the data files for the distributions)
# Example:
# plt.hist(bs_distribution, bins=30, density=True, alpha=0.5, label='Black-Scholes')
# plt.hist(vasicek_distribution, bins=30, density=True, alpha=0.5, label='Vasicek')
# plt.hist(hw_distribution, bins=30, density=True, alpha=0.5, label='Hull-White')
# plt.legend()
# plt.xlabel('Value')
# plt.ylabel('Frequency')
# plt.title('Histogram of Distributions')
# plt.show()

# Visualize variances
models = ['Black-Scholes', 'Vasicek', 'Hull-White']
variances = [bs_variance, vasicek_variance, hw_variance]

plt.bar(models, variances, color=['blue', 'green', 'red'])
plt.xlabel('Model')
plt.ylabel('Variance')
plt.title('Variance of Models')
plt.show()