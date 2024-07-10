system("java -version")
install.packages("sparklyr")
install.packages("stats")
packageVersion("sparklyr")
library(sparklyr)
#spark_install("3.0")
spark_available_versions()
spark_installed_versions()
library(sparklyr)
sc <- spark_connect(master = "local", version = "2.3")
spark_connection(TRUE)
cars <- copy_to(sc, mtcars)
spark_web(sc)
system("java -version")
Sys.setenv(JAVA_HOME = "C:/Program Files/Java/jdk1.8.0_202")
library(sparklyr)
sc <- spark_connect(master = "local", version = "3.0")
spark_connection(TRUE)
cars <- copy_to(sc, mtcars)
library(DBI)
dbGetQuery(sc, "SELECT count(*) FROM mtcars")
library(dplyr)
count(cars)
select(cars, hp, mpg) %>%
  sample_n(100) %>%
  collect() %>%
  plot()
spark_web(sc)
model <- ml_linear_regression(cars, mpg ~ hp)
model
model %>%
  ml_predict(copy_to(sc, data.frame(hp = 250 + 10 * 1:10))) %>%
  transmute(hp = hp, mpg = prediction) %>%
  full_join(select(cars, hp, mpg)) %>%
  collect() %>%
  plot()