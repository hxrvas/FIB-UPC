# Funx Language Interpreter

Funx Language Interpreter is a web interpreter for the programming language Funx.

## What is Funx?

Funx is a simple programming language that lets the user define functions and execute expressions. It lets you define as many functions as you want, but only allows one expression execution at a time. Functions allow if/else statements, as well as assing and while statatements. Recursion is also allowed. Funx only works with integers.

## Tools used

Funx Language Interpreter is made using ANTLR4 and Python for the interpreter, and flask alongside jinja2 for the web app.

## Syntax

You can first declare as many functions as you want, and you can optionally end with an expression, that will be executed.

Function names have to start with an uppercase letter. Variable names have to start with a lowercase letter.

Parenthesis are allowed.

### Function declaration

```
# function that receives two numbers and returns the sum
Sum x y
{
  x + y
}

Sum (2 * 3) 4 
```

```
Out: 10
```

### Operators

```
#addition
a + b
#substraction
a - b
#multiplication
a * b
#module
a % b
#equal
a = b
#not equal
a != b
#less or equal
a <= b
#greater or equal
a >= b
#greater than
a > b
#less than
a < b
```

### Assign statement

```
a <- expression
```

### While statement

```
while expression {
    statements
}
```

### If else expression

```
if expression {
    statements
}
else {
    statements
}
```

### Function call

```
Name parameters
```



### Return statement

```
Any expression inside a function will act as an exit point.
```

### Recursion example

```
Fibo n
{
    if n < 2 { n }
    (Fibo n-1) + (Fibo n-2)
}

Fibo 4
```

```
Out: 3
```

## Usage

To execute the web app, you need Python3, flask and jinja2 installed. Then, execute

```bash
export FLASK_APP=funx
flask run
```

in your console.

Web App can then be accessed on localhost:5000 using a web browser.

### Web app sections

Web app has 4 sections: Functions, Console, Results and Errors.

In the Functions section, all functions that are declared will be displayed, with their correct syntax for function calls. 

In the Results section, the last 5 results will be displayed.

The Console section can be used to type and submit code.

Lastly, the Errors section will display any possible errors that happen during execution.


