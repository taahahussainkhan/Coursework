# Create the data frame
data <- data.frame(
  Age = c(1, 2, 3, 4),
  Years_Exp = c(4, 5, 8, 2),
  Salary = c(1, 6, 8, 12)
)
print(data)
# Install and load the caTools package
# install.packages('caTools') # Uncomment if caTools is not installed
library(caTools)
# Split the data into training and test sets
split = sample.split(data$Salary, SplitRatio = 0.75)
trainingset = subset(data, split == TRUE)
testset = subset(data, split == FALSE)
summary(split)

# Fitting Simple Linear Regression to the Training set
lm.r = lm(formula = Salary ~ Age + Years_Exp , data = trainingset)

# Summary of the model
summary(lm.r)

# Create a data frame with new input values
new_data <- data.frame(Age = 4, Years_Exp = 5)

# Predict using the linear regression model
predicted_salaries <- predict(lm.r, newdata = new_data)

# Display the predicted salaries
print(predicted_salaries)

