# dependencies
# python-pip python-matplotlib python-numpy

import numpy as np
import matplotlib.pyplot as plt

# Generate random data
x = np.random.randn(1000)
y = np.random.randn(1000)

# Create 2D histogram and draw it
plt.hist2d(x, y, bins=40, cmap='plasma')

# Add colorbar
plt.colorbar(label='Frequency')

# Labels and title
plt.title('2D Histogram')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')

# Show plot
plt.show()
