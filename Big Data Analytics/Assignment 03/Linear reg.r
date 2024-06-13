# Load necessary libraries
library(ggplot2)

# 1. Create a simple dataset with a linear relationship
set.seed(123)  # For reproducibility
n <- 100  # Number of observations
x <- rnorm(n, mean = 5, sd = 2)  # Predictor variable
y <- 3 + 2 * x + rnorm(n, mean = 0, sd = 2)  # Response variable with some noise

# Combine into a dataframe
data <- data.frame(x = x, y = y)

# 2. Fit a linear regression model
model <- lm(y ~ x, data = data)

# Print the summary of the model
summary(model)

# 3. Visualize the results
# Scatter plot with regression line
ggplot(data, aes(x = x, y = y)) +
  geom_point() +  # Scatter plot of the data
  geom_smooth(method = "lm", col = "blue") +  # Add regression line
  labs(title = "Linear Regression Example",
       x = "Predictor (x)",
       y = "Response (y)") +
  theme_minimal()
