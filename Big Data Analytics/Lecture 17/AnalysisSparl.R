install.packages("ggplot2")
install.packages("corrr")
install.packages("dbplot")
install.packages("rmarkdown")
library(sparklyr)
library(dplyr)
Sys.setenv(JAVA_HOME = "C:/Program Files/Java/jdk1.8.0_202")
sc <- spark_connect(master = "local", version = "3.0")
cars <- copy_to(sc, mtcars)
summarize_all(cars, mean)

summarize_all(cars, mean) %>%
show_query()

cars %>%
  mutate(transmission = ifelse(am == 0, "automatic", "manual")) %>%
  group_by(transmission) %>%
  summarise_all(mean)

summarise(cars, mpg_percentile = percentile(mpg, 0.25))

summarise(cars, mpg_percentile = percentile(mpg, 0.25)) %>%
  show_query()


