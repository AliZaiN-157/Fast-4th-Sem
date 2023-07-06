# # Write the code for Newton Forward difference method 

# # Importing the libraries
import numpy as np
# import pandas as pd


# # Input the data
# x = np.array([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0])
# y = np.array([1.0, 1.005, 1.020, 1.045, 1.080, 1.125, 1.180, 1.245, 1.320, 1.405, 1.500])

# # Input the value of x for which y is to be found
# x0 = 0.5

# # Input the number of data points
# n = len(x)

# # Initialize the difference table
# D = np.zeros((n, n))
# D[:, 0] = y

# # Calculate the difference table
# for i in range(1, n):
#     for j in range(n - i):
#         D[j][i] = D[j + 1][i - 1] - D[j][i - 1]

# # Calculate the value of y at x0
# y0 = D[0][0]
# for i in range(1, n):
#     p = 1
#     for j in range(i):
#         p = p * (x0 - x[j])
#     y0 = y0 + (p * D[0][i]) / np.math.factorial(i)

# # Print the value of y0
# print("The value of y at x0 is: ", y0)

# Create a function for  Newton Forward difference method

def NewtonForward(x, y, x0):
    # Initialize the difference table
    n = len(x)
    D = np.zeros((n, n))
    D[:, 0] = y

    # Calculate the difference table
    for i in range(1, n):
        for j in range(n - i):
            D[j][i] = D[j + 1][i - 1] - D[j][i - 1]

    # Calculate the value of y at x0
    y0 = D[0][0]
    for i in range(1, n):
        p = 1
        for j in range(i):
            p = p * (x0 - x[j])
        y0 = y0 + (p * D[0][i]) / np.math.factorial(i)

    
    return y0

# Call the function
x = [-1.5,-1,-0.5,0,1]
y = [2,6,10.1,13.2,12.2]
print(NewtonForward(x, y,-1.2))
