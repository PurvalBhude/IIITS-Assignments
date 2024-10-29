import cv2
import numpy as np
import matplotlib.pyplot as plt

# Function to plot transformations on a single figure
def plot_transformations(original_image, transformed_images, titles):
    # Create a new figure to hold all transformations
    plt.figure(figsize=(12, 10))

    # Plot the original image
    plt.subplot(3, 2, 1)
    plt.imshow(cv2.cvtColor(original_image, cv2.COLOR_BGR2RGB))
    plt.title("Original Image")
    plt.axis("off")

    for i, img in enumerate(transformed_images):
        plt.subplot(3, 2, i + 2)
        plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
        plt.title(titles[i])
        plt.axis("off")

    # Add eigenvalue and eigenvector section
    plt.subplot(3, 2, 6)
    plt.axis("off")
    eigenvalue_info = (
        "Eigenvalues and Eigenvectors:\n"
        "1. Scaling (Equal): λ₁ = λ₂ = k\n"
        "2. Scaling (Unequal): λ₁ = k₁, λ₂ = k₂\n"
        "3. Horizontal Shear: λ₁ = λ₂ = 1\n"
        "4. Vertical Shear: λ₁ = λ₂ = 1\n\n"
        "Example Eigenvectors:\n"
        "Equal Scaling: v₁ = [1, 0], v₂ = [0, 1]\n"
        "Unequal Scaling: v₁ = [1, 0], v₂ = [0, 1]\n"
        "Horizontal Shear: v₁ = [1, 0]\n"
        "Vertical Shear: v₁ = [0, 1]"
    )
    plt.text(0, 1, eigenvalue_info, fontsize=10, va='top')

    plt.tight_layout()
    plt.show()

# Load an image
img = cv2.imread('winner-gold-logo-vector.jpg')  # Update with your image path
if img is None:
    raise ValueError("Image not found. Please check the path.")

# Resize the image for better visualization
img = cv2.resize(img, (300, 300))

# Define a function to apply the transformation to the image
def apply_transformation(image, transformation_matrix):
    transformed_image = cv2.warpAffine(image, transformation_matrix, (image.shape[1], image.shape[0]))
    return transformed_image

# Prepare to store transformed images
transformed_images = []
titles = []

# Example 1: Scaling (Equal)
k = 2  # Scale factor
scale_matrix_equal = np.array([[k, 0, 0], [0, k, 0]], dtype=np.float32)  # Scaling matrix

# Transform the image
image_equal = apply_transformation(img, scale_matrix_equal)
titles.append("Scaling (Equal)\nEigenvalues: λ₁ = λ₂ = 2\nEigenvectors: v₁ = [1, 0], v₂ = [0, 1]")
transformed_images.append(image_equal)

# Example 2: Scaling (Unequal)
k1 = 2  # Scale factor for x
k2 = 0.5  # Scale factor for y
scale_matrix_unequal = np.array([[k1, 0, 0], [0, k2, 0]], dtype=np.float32)  # Scaling matrix

# Transform the image
image_unequal = apply_transformation(img, scale_matrix_unequal)
titles.append("Scaling (Unequal)\nEigenvalues: λ₁ = 2, λ₂ = 0.5\nEigenvectors: v₁ = [1, 0], v₂ = [0, 1]")
transformed_images.append(image_unequal)

# Example 3: Horizontal Shear
shear_factor_horizontal = 0.5  # Shear factor for horizontal shear
shear_matrix_horizontal = np.array([[1, shear_factor_horizontal, 0], [0, 1, 0]], dtype=np.float32)  # Shear matrix

# Transform the image
image_horizontal_shear = apply_transformation(img, shear_matrix_horizontal)
titles.append("Horizontal Shear\nEigenvalues: λ₁ = λ₂ = 1\nEigenvector: v₁ = [1, 0]")
transformed_images.append(image_horizontal_shear)

# Example 4: Vertical Shear
shear_factor_vertical = 0.5  # Shear factor for vertical shear
shear_matrix_vertical = np.array([[1, 0, 0], [shear_factor_vertical, 1, 0]], dtype=np.float32)  # Shear matrix

# Transform the image
image_vertical_shear = apply_transformation(img, shear_matrix_vertical)
titles.append("Vertical Shear\nEigenvalues: λ₁ = λ₂ = 1\nEigenvector: v₁ = [0, 1]")
transformed_images.append(image_vertical_shear)

# Plot all transformations in one window
plot_transformations(img, transformed_images, titles)
