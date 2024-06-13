# Set seed for reproducibility
set.seed(123)

# Create a dataset
n <- 100
dataset <- data.frame(
  predictor1 = rnorm(n, mean = 50, sd = 10),
  predictor2 = rnorm(n, mean = 30, sd = 5),
  predictor3 = rnorm(n, mean = 20, sd = 3),
  response = rnorm(n, mean = 100, sd = 15)
)

# Introduce a linear relationship
dataset$response <- 50 + 0.5 * dataset$predictor1 + 0.3 * dataset$predictor2 - 0.2 * dataset$predictor3 + rnorm(n, mean = 0, sd = 5)

# Fit a multiple regression model
model <- lm(response ~ predictor1 + predictor2 + predictor3, data = dataset)

# Summarize the results
summary(model)

