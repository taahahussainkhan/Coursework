# Load necessary library
library(ggplot2)

# Set seed for reproducibility
set.seed(42)

# Create a dataset
n <- 100
x <- seq(-10, 10, length.out = n)
a <- 0.5
b <- 2
c <- 1
noise <- rnorm(n, mean = 0, sd = 5)
y <- a * x^2 + b * x + c + noise

# Create a data frame
data <- data.frame(x = x, y = y)

# Fit a polynomial regression model
model <- lm(y ~ poly(x, 2), data = data)

# Print model summary
summary(model)

# Create a sequence of x values for prediction
x_pred <- seq(min(x), max(x), length.out = 200)
y_pred <- predict(model, newdata = data.frame(x = x_pred))

# Create a data frame for predicted values
pred_data <- data.frame(x = x_pred, y = y_pred)

# Plot the data and the polynomial regression curve
ggplot(data, aes(x = x, y = y)) +
  geom_point(color = 'blue') +  # Original data points
  geom_line(data = pred_data, aes(x = x, y = y), color = 'red', linewidth = 1) +  # Fitted curve
  labs(title = 'Polynomial Regression',
       x = 'x',
       y = 'y') +
  theme_minimal()
