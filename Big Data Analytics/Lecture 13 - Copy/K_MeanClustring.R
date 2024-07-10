# Load necessary library
library(ggplot2)

# Define the dataset
points <- data.frame(
  x = c(2, 2, 8, 5, 7, 6, 1, 4),
  y = c(10, 5, 4, 8, 5, 4, 2, 9),
  labels = c("A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2")
)

# Initial cluster centers (A1, B1, C1)
initial_centers <- data.frame(
  x = c(2, 5, 1),
  y = c(10, 8, 2)
)

# Perform K-means clustering with specified initial centers
set.seed(123)
kmeans_result <- kmeans(points[, c("x", "y")], centers = initial_centers, iter.max = 10)

# Add cluster assignment to data
points$cluster <- as.factor(kmeans_result$cluster)

# Ensure the centers have column names 'x' and 'y'
centers <- data.frame(x = kmeans_result$centers[, 1], y = kmeans_result$centers[, 2])
print(centers)
# Visualize the clusters
ggplot(points, aes(x = x, y = y, color = cluster)) +
  geom_point(size = 3) +
  geom_text(aes(label = labels), vjust = -1, hjust = 1) +
  geom_point(data = centers, aes(x = x, y = y), color = "black", size = 5, shape = 8) +
  labs(title = "K-means Clustering",
       x = "X Coordinate",
       y = "Y Coordinate") +
  theme_minimal()
