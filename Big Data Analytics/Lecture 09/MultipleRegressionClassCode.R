# Create the data frame
data <- data.frame(
  Age=c(32,28,45,36,52,29,42,31,26,38,29,48,35,40,27,44,33,39,25
  ),
  Years_Exp = c(5,3,15,7,20,2,12,4,1,10,3,18,6,14,2,16,7,12,0
  ),
  Salary = c(90000,65000,150000,60000,200000,55000,120000,80000,45000
             ,110000,75000,140000,65000,130000,40000,125000,90000,115000,35000
  )
)

# Create the scatter plot
plot(data$Years_Exp, data$Salary,
     xlab = "Years Experienced",
     ylab = "Salary",
     main = "Scatter Plot of Years Experienced vs Salary")
#install.packages('caTools')
library(caTools)
split = sample.split(data$Salary, SplitRatio = 0.7)
trainingset = subset(data, split == TRUE)
testset = subset(data, split == FALSE)

# Fitting Simple Linear Regression to the Training set
lm.r= lm(formula = Salary ~ Age + Years_Exp,
         data = trainingset)
#Summary of the model
summary(lm.r)
# Create a data frame with new input values
new_data <- data.frame(Age = 24, Years_Exp = 2)

# Predict using the linear regression model
predicted_salaries <- predict(lm.r, newdata = new_data)

# Display the predicted salaries
print(predicted_salaries)

# Visualising the Training set results
#install.packages('ggplot')
install.packages("ggplot2")
library(ggplot2)
ggplot() + geom_point(aes(x = trainingset$Years_Ex, 
                          y = trainingset$Salary), colour = 'red') +
  geom_line(aes(x = trainingset$Years_Ex,
                y = predict(lm.r, newdata = trainingset)), colour = 'blue') +
  
  ggtitle('Salary vs Experience (Training set)') +
  xlab('Years of experience') +
  ylab('Salary')

# Visualising the Test set results
ggplot() + 
  geom_point(aes(x = trainingset$Years_Exp, 
                 y = trainingset$Salary), colour = 'red') +
  geom_line(aes(x = trainingset$Years_Exp,
                y = predict(lm.r, newdata = trainingset)), colour = 'blue') +
  ggtitle('Salary vs Experience (Training set)') +
  xlab('Years of experience') +
  ylab('Salary')