# Step 1: Create the dataset
data <- data.frame(
  Study_Hours = c(29, 15, 33, 28, 39),
  Pass_Fail = c(0, 0, 1, 1, 1)
)

# Step 2: Fit a logistic regression model
model <- glm(Pass_Fail ~ Study_Hours, data = data, family = binomial)

# Step 3: Predict the probability of passing for 33 hours of study
new_data <- data.frame(Study_Hours = 33)
predicted_probability <- predict(model, newdata = new_data, type = "response")

# Print the predicted probability
print(predicted_probability)

# Step 4: Determine the minimum number of study hours for 95% probability of passing
# The logistic regression equation is:
# log(p / (1 - p)) = beta_0 + beta_1 * Study_Hours
# For p = 0.95:
# log(0.95 / 0.05) = beta_0 + beta_1 * Study_Hours
# Solve for Study_Hours

coefficients <- coef(model)
beta_0 <- coefficients[1]
beta_1 <- coefficients[2]
print(beta_0)
print(beta_1)
required_hours <- (log(0.95 / 0.05) - beta_0) / beta_1
print(required_hours)

# Step 5: Plot the logistic regression curve
# Load necessary library for plotting
library(ggplot2)

# Create a sequence of Study_Hours for plotting
study_hours_seq <- seq(min(data$Study_Hours), max(data$Study_Hours), length.out = 100)

# Predict the probabilities for the sequence
predicted_probabilities <- predict(model, newdata = data.frame(Study_Hours = study_hours_seq), type = "response")

# Create a dataframe for plotting
plot_data <- data.frame(Study_Hours = study_hours_seq, Probability = predicted_probabilities)

# Plot
ggplot(data, aes(x = Study_Hours, y = Pass_Fail)) +
  geom_point() +
  geom_line(data = plot_data, aes(x = Study_Hours, y = Probability), color = 'blue') +
  labs(title = 'Logistic Regression Curve',
       x = 'Study Hours',
       y = 'Probability of Passing') +
  theme_minimal()
