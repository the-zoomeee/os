# Shell Scripting Syntax and Examples

This `README.md` provides a comprehensive guide to common Shell Scripting syntax and basic examples. Shell scripts are used to automate tasks and execute multiple commands in Linux and Unix-like operating systems.

---

## Table of Contents

1. [Basic Syntax](#basic-syntax)
2. [Variables](#variables)
3. [Control Structures](#control-structures)
4. [Loops](#loops)
5. [Functions](#functions)
6. [Input and Output](#input-and-output)
7. [File Operations](#file-operations)
8. [Error Handling](#error-handling)
9. [Scripting Best Practices](#scripting-best-practices)

---

## Basic Syntax

A basic shell script consists of a sequence of commands that are executed by the shell.

### Creating a Shell Script

1. Open a text editor (e.g., `nano`, `vim`) and create a new file:
   ```bash
   nano my_script.sh
Start the script with the shebang (#!/bin/bash):

bash
Copy code
#!/bin/bash
echo "Hello, World!"
Make the script executable:

bash
Copy code
chmod +x my_script.sh
Run the script:

bash
Copy code
./my_script.sh
Variables
Variables are used to store data in shell scripts.

Example:
bash
Copy code
#!/bin/bash
name="John"
echo "Hello, $name!"
Accessing Variable: Use $variable_name to access the value of a variable.
Declaring Variables: Simply assign a value (variable_name=value) without spaces around =.
Control Structures
if Statement
The if statement is used to execute commands conditionally.

Example:
bash
Copy code
#!/bin/bash
age=20
if [ $age -ge 18 ]; then
    echo "You are an adult."
else
    echo "You are a minor."
fi
test Command
The test command is often used for conditions.

bash
Copy code
if test $age -ge 18; then
    echo "You are an adult."
fi
Comparison Operators:
-eq : Equal
-ne : Not equal
-gt : Greater than
-lt : Less than
-ge : Greater than or equal to
-le : Less than or equal to
Loops
for Loop
The for loop is used to repeat a set of commands a specific number of times.

Example:
bash
Copy code
#!/bin/bash
for i in {1..5}
do
  echo "Number $i"
done
while Loop
The while loop runs as long as a given condition is true.

Example:
bash
Copy code
#!/bin/bash
count=1
while [ $count -le 5 ]
do
  echo "Count is $count"
  ((count++))
done
until Loop
The until loop runs until the given condition becomes true.

Example:
bash
Copy code
#!/bin/bash
count=1
until [ $count -gt 5 ]
do
  echo "Count is $count"
  ((count++))
done
Functions
Functions are used to group commands together and reuse them.

Example:
bash
Copy code
#!/bin/bash
greet() {
    echo "Hello, $1!"
}

greet "Alice"
Defining a Function: Use function_name() {}.
Calling a Function: Use function_name or function_name arguments.
Passing Arguments: $1, $2, etc., represent the first, second, etc., arguments passed to the function.
Input and Output
Reading User Input
You can read input from the user using the read command.

Example:
bash
Copy code
#!/bin/bash
echo "Enter your name:"
read name
echo "Hello, $name!"
read stores user input into a variable.
Output with echo and printf
echo: Displays a message to the console.

bash
Copy code
echo "Hello, World!"
printf: Provides more control over output formatting.

bash
Copy code
printf "Hello, %s!\n" "World"
File Operations
Creating a File
You can create a file using the touch command.

Example:
bash
Copy code
touch my_file.txt
Writing to a File
Use the echo or printf command to write to a file.

Example:
bash
Copy code
echo "This is a file" > my_file.txt
To append to a file:

bash
Copy code
echo "This is an additional line" >> my_file.txt
Reading from a File
You can read from a file using cat, less, or while loop with read.

Example:
bash
Copy code
#!/bin/bash
while IFS= read -r line
do
  echo $line
done < my_file.txt
Checking File Existence
Use if and test to check if a file exists.

Example:
bash
Copy code
#!/bin/bash
if [ -f "my_file.txt" ]; then
    echo "File exists."
else
    echo "File does not exist."
fi
Error Handling
Exit Status
Each command returns an exit status that indicates whether it succeeded or failed.

Exit Status 0 indicates success.
Non-zero exit status indicates failure.
Check the exit status with $?:

bash
Copy code
#!/bin/bash
mkdir my_directory
if [ $? -eq 0 ]; then
    echo "Directory created successfully!"
else
    echo "Failed to create directory."
fi
trap Command
The trap command allows you to handle signals and clean up before exiting.

Example:
bash
Copy code
#!/bin/bash
trap "echo 'Script interrupted!'; exit" SIGINT
echo "Press Ctrl+C to interrupt the script"
while true; do
    sleep 1
done
Scripting Best Practices
Always start with a shebang (#!/bin/bash).
Use comments to explain your code.
bash
Copy code
# This is a comment
Quote variables to prevent issues with spaces:
bash
Copy code
echo "$variable"
Use functions for modularity.
Check command return values with $?.
Test your script thoroughly.