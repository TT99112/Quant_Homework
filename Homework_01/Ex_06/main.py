import numpy as np
import matplotlib.pyplot as plt

def newton_symbol(N, i):
    if i < 0 or i > N:
        return 0
    result = 1
    for k in range(1, i+1):
        result *= (N - i + k) / k
    return result

def risk_neutral_prob(U, D, R):
    return (1 + R - D) / (U - D)

def call_payoff(S, K):
    return max(S - K, 0)

def calculate_pdf(S0, U, D, R, N, K):
    q = risk_neutral_prob(U, D, R)
    PDF = np.zeros(N+1)
    for i in range(N+1):
        PDF[i] = newton_symbol(N, i) * pow(q, i) * pow(1 - q, N - i)
    return PDF

def plot_pdf(S0, U, D_values, R, N, K):
    outcomes = np.arange(N+1)
    plt.figure(figsize=(10, 6))  # Adjust figure size if needed
    for D in D_values:
        stock_prices = [S0 * pow(U, i) * pow(D, N-i) for i in range(N+1)]
        PDF = calculate_pdf(S0, U, D, R, N, K)
        plt.plot(stock_prices, PDF, marker='o', label=f'D = {D}')
    plt.title('Probability Density Function (PDF)')
    plt.xlim(0,300)
    plt.xlabel('Stock Prices (S)')
    plt.ylabel('Probability')
    plt.grid(True)
    plt.legend()

def plot_S_function(S0, U, D_values, N):
    plt.figure(figsize=(10, 6))
    i_values = np.arange(N+1)
    for D in D_values:
        S_values = S0 * np.power(U, i_values) * np.power(D, N - i_values)
        plt.plot(i_values, S_values, marker='o', label=f'D = {D}')
    plt.title('S(N, i) Function')
    plt.xlabel('i')
    plt.ylabel('S(N, i)')
    plt.grid(True)
    plt.legend()

# Parameters
S0 = 100  # Initial stock price
U = 1.05  # Up factor
D_values = [0.99, 0.97]  # Different values for D
R = 0  # Risk-free rate
N = 100  # Number of periods
K = 100  # Strike price

# Plot PDF
plot_S_function(S0, U, D_values, N)
plot_pdf(S0, U, D_values, R, N, K)
plt.show()