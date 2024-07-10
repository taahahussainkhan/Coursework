system("java -version")
Sys.setenv(JAVA_HOME = "C:/Program Files/Java/jdk1.8.0_202")
library(sparklyr)
sc <- spark_connect(master = "local", version = "3.0")
spark_connection(TRUE)
cars <- copy_to(sc, mtcars)
print(cars)
spark_web(sc)
library(DBI)
dbGetQuery(sc, "SELECT count(*) FROM mtcars")
count(cars)
library(dplyr)
count(cars)
select(cars, hp, mpg) %>%
  sample_n(100) %>%
  collect() %>%
  plot()

