import matplotlib.pyplot as plt

def read_sample_paths(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
        sample_paths = {}
        current_sample_path = None
        for line in lines:
            line = line.strip()
            if line.endswith("sample path:"):
                current_sample_path = line.split()[0]
                sample_paths[current_sample_path] = []
            else:
                try:
                    sample_paths[current_sample_path].append(float(line))
                except ValueError:
                    continue
    return sample_paths

def plot_distribution(sample_path, title):
    plt.figure(figsize=(8, 6))
    plt.hist(sample_path, bins=30, edgecolor='black', alpha=0.7)
    plt.title(title)
    plt.xlabel('Value')
    plt.ylabel('Frequency')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    # Read sample paths from file
    sample_paths = read_sample_paths("sample_paths.txt")

    # Plot distributions for each sample path
    for key, value in sample_paths.items():
        plot_distribution(value, f"{key} Distribution")
