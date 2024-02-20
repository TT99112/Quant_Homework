import numpy as np
import matplotlib.pyplot as plt

# Given parameters
S0 = 100  # Initial stock price
T = 1  # Time to maturity
r = 0.06  # Risk-free rate
volatilities = [0.2, 0.3, 0.5]  # Volatilities (20%, 30%, 50%)
K_range = np.arange(80, 121, 1)  # Range of strike prices
epsilon = 0.01  # Bump size for Delta calculation

# Function to calculate digital option PV and Delta using CRR model
def digital_option_pv_delta(S0, K, T, r, sigma, epsilon):
    # Calculate u, d, and q from CRR model
    dt = T  # Assuming one period model for simplicity
    u = np.exp(sigma * np.sqrt(dt))
    d = 1 / u
    q = (np.exp(r * dt) - d) / (u - d)

    # Digital option payoff at maturity
    Su = S0 * u  # Stock price if up
    Sd = S0 * d  # Stock price if down
    Cu = 1 if Su >= K else 0  # Payoff if up
    Cd = 1 if Sd >= K else 0  # Payoff if down

    # Present value of the digital option
    PV = np.exp(-r * dt) * (q * Cu + (1 - q) * Cd)

    # Calculating Delta by bumping the underlying stock price
    Su_bumped = (S0 + epsilon) * u
    Sd_bumped = (S0 + epsilon) * d
    Cu_bumped = 1 if Su_bumped >= K else 0
    Cd_bumped = 1 if Sd_bumped >= K else 0
    PV_bumped = np.exp(-r * dt) * (q * Cu_bumped + (1 - q) * Cd_bumped)

    Delta = (PV_bumped - PV) / epsilon

    return PV, Delta

# Arrays to hold results
PVs = np.zeros((len(volatilities), len(K_range)))
Deltas = np.zeros((len(volatilities), len(K_range)))

# Calculate PV and Delta for each volatility and strike price
for i, sigma in enumerate(volatilities):
    for j, K in enumerate(K_range):
        PV, Delta = digital_option_pv_delta(S0, K, T, r, sigma, epsilon)
        PVs[i, j] = PV
        Deltas[i, j] = Delta

# Plotting
fig, ax1 = plt.subplots()

colors = ['blue', 'green', 'red']
for i, sigma in enumerate(volatilities):
    ax1.plot(K_range, PVs[i], label=f'PV, σ={sigma*100}%', color=colors[i])

ax1.set_xlabel('Strike Price (K)')
ax1.set_ylabel('Digital Option PV', color='black')
ax1.tick_params(axis='y')
ax1.legend(loc='upper left')

ax2 = ax1.twinx()
for i, sigma in enumerate(volatilities):
    ax2.plot(K_range, Deltas[i], '--', label=f'Delta, σ={sigma*100}%', color=colors[i])

ax2.set_ylabel('Delta', color='black')
ax2.tick_params(axis='y')
ax2.legend(loc='upper right')

plt.title('Digital Option PV and Delta vs. Strike Price for Various Volatilities')
plt.show()