# Create the dataset
dataset <- data.frame(
  Position = c("Business Analyst", "Junior Consultant", "Senior Consultant", "Manager", "Country Manager",
               "Region Manager", "Partner", "Senior Partner", "C-level", "CEO"),
  Level = 1:10,
  Salary = c(45000, 50000, 60000, 80000, 110000, 150000, 200000, 300000, 500000, 1000000)
)

# View the dataset
print(dataset)

# Fitting Polynomial Regression to the dataset
dataset$Level2 <- dataset$Level^2
dataset$Level3 <- dataset$Level^3
dataset$Level4 <- dataset$Level^4

# Fit the model
poly_model <- lm(Salary ~ Level + Level2 + Level3 + Level4, data = dataset)

# Summary of the model
summary(poly_model)

# Load necessary library for visualization
library(ggplot2)

# Scatter plot of the dataset
ggplot(dataset, aes(x = Level, y = Salary)) +
  geom_point(color = "red") +
  stat_smooth(method = lm, formula = y ~ poly(x, 4), se = FALSE, color = "blue") +
  ggtitle("Polynomial Regression: Salary vs Level") +
  xlab("Level") +
  ylab("Salary")
