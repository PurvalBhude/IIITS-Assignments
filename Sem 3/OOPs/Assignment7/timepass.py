import cv2
import numpy as np
import matplotlib.pyplot as plt

# Function to calculate determinant and perform affine scaling
def scale_image(image, scale_x, scale_y):
    height, width = image.shape[:2]

    # Affine scaling matrix (2x3 matrix)
    scaling_matrix = np.array([[scale_x, 0, 0],
                               [0, scale_y, 0]])

    # Calculate determinant of the top-left 2x2 part of the scaling matrix
    determinant = np.linalg.det(scaling_matrix[:2, :2])

    # Print out the scaling matrix and its determinant
    print(f"Scaling Matrix:\n{scaling_matrix}")
    print(f"Determinant of scaling matrix: {determinant}\n")

    # Apply the affine transformation only if determinant is valid
    if abs(determinant) > 1e-6:
        print("Scaling is valid. Applying transformation.")
        scaled_image = cv2.warpAffine(image, scaling_matrix, (width, height))
    else:
        print("Invalid scaling! Determinant is zero or too close to zero.")
        scaled_image = image  # Return the original image

    return scaled_image, determinant

# Load the image
image = cv2.imread('winner-gold-logo-vector.jpg')  # Replace with the path to your image

# Define different scaling factors to observe how the determinant changes
scaling_factors = [
    (1.0, 1.0),  # No scaling (identity matrix)
    (1.5, 0.5),  # Scaling with different x and y factors
    (2.0, 2.0),  # Uniform scaling (double the size)
    (0.0, 1.0),  # Invalid scaling (collapsing along x-axis)
    (1.0, 0.0),  # Invalid scaling (collapsing along y-axis)
    (0.0, 0.0)   # Fully invalid scaling (collapsed matrix)
]

# Display the original image and scaled images
plt.figure(figsize=(15, 10))
plt.subplot(2, 3, 1)
plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
plt.title("Original Image")

# Limit the number of subplots to match the grid size (2 rows x 3 columns)
for i, (scale_x, scale_y) in enumerate(scaling_factors[:5]):
    print(f"\n--- Scaling Factors: X = {scale_x}, Y = {scale_y} ---")
    scaled_image, determinant = scale_image(image, scale_x, scale_y)

    # Display the scaled image
    plt.subplot(2, 3, i+2)
    plt.imshow(cv2.cvtColor(scaled_image, cv2.COLOR_BGR2RGB))
    plt.title(f"Scale X={scale_x}, Y={scale_y}\nDet: {determinant:.2f}")

plt.tight_layout()
plt.show()
