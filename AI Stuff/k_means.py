#%% Important Libraries
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs

#%% Importing the Synthetic dataset
features, true_label = make_blobs(n_samples=200, centers=3, cluster_std=2.75, random_state=42)
#%% Plotting the Data
plt.figure(figsize=(8, 8))
plt.scatter(features[:, 0], features[:, 1], c=true_label, cmap='rainbow')
plt.show()

# %%
