#Python Function
#A function is a block of code that performs a specific task.
#A function is a block of code which only runs when it is called.
#You can pass data, known as parameters, into a function.
#A function can return data as a result.

#Types of function
#There are two types of function in Python programming:

#Standard library functions - These are built-in functions in Python that are available to use.
#User-defined functions - We can create our own functions based on our requirements.


def function_name(arguments):
    # function body 

    return

#def - keyword used to declare a function
#function_name - any name given to the function
#arguments - any value passed to function
#return (optional) - returns value from a function

def my_function():
  print("Hello from a function")

my_function()


#Arguments
#Information can be passed into functions as arguments.
#Arguments are specified after the function name, inside the parentheses. 
#You can add as many arguments as you want, just separate them with a comma.
#The following example has a function with one argument (fname). 
#When the function is called, we pass along a first name, which is used inside the function to print the full name:

#Example:
def my_function(fname):
  print(fname + " Refsnes")

my_function("Emil")
my_function("Tobias")
my_function("Linus")

#Example
def my_function(fname, lname):
  print(fname + " " + lname)

my_function("Emil", "Refsnes")

# function with two arguments
def add_numbers(num1, num2):
    sum = num1 + num2
    print('Sum: ',sum)

# function call with two values
add_numbers(5, 4)
add_numbers(2,2)


#Arbitrary Arguments, *args
#If you do not know how many arguments that will be passed into your function,
#add a * before the parameter name in the function definition.
#This way the function will receive a tuple of arguments, and can access the items accordingly:
def my_function(*kids):
  print("The youngest child is " + kids[2])

my_function("Emil", "Tobias", "Linus")

#keyword arguments , named arguments 
def my_function(child3, child2, child1):
  print("The youngest child is " + child3)

my_function(child1 = "Emil", child2 = "Tobias", child3 = "Linus")

#function with default values 
def my_function(country = "Norway"):
  print("I am from " + country)

my_function("Sweden")
my_function("India")
my_function()
my_function("Brazil")


#Passing a List as an Argument
#You can send any data types of argument to a function (string, number, list, dictionary etc.), 
#and it will be treated as the same data type inside the function.
#E.g. if you send a List as an argument, it will still be a List when it reaches the function:

#example
def my_function(food):
  for x in food:
    print(x)

fruits = ["apple", "banana", "cherry"]

my_function(fruits)

#return value 
def my_function(x):
  return 5 * x

print(my_function(3))
print(my_function(5))
print(my_function(9))


#example:
# function definition
def find_square(num):
    result = num * num
    return result

# function call
square = find_square(3)

print('Square:',square)


#Python Lambda
#A lambda function is a small anonymous function.
#A lambda function can take any number of arguments, but can only have one expression.

x = lambda a : a + 10
print(x(5))

x = lambda a, b : a * b
print(x(5, 6))

#The power of lambda is better shown when you use them as an anonymous function inside another function.
#Say you have a function definition that takes one argument, and that argument will be multiplied with an unknown number:

#Example
def myfunc(n):
  return lambda a : a * n

#Example
def myfunc(n):
  return lambda a : a * n

mydoubler = myfunc(2)

print(mydoubler(11))

#Example:
def myfunc(n):
  return lambda a : a * n

mytripler = myfunc(3)
mydoubler = myfunc(2)
mytripler = myfunc(3)

print(mytripler(11))
print(mydoubler(11))
print(mytripler(11))