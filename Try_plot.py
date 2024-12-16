import numpy as np
import matplotlib.pyplot as plt

# Generate x values from 0 to 2π
x = np.linspace(0, 2 * np.pi, 100)

# Compute the sine of x
y = np.sin(x)

# Create the plot
plt.plot(x, y, label='Sine Wave')

# Add labels and title
plt.title('Sine Wave')
plt.xlabel('x values (radians)')
plt.ylabel('sin(x)')

# Add a legend
plt.legend()

# Show the grid
plt.grid(True)

# Display the plot
plt.show()