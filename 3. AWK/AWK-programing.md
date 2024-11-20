
# AWK Programming Syntax and Examples

AWK is a powerful text-processing language used for pattern scanning and processing. It allows you to process text files, extract data, and perform various operations.

---

## Table of Contents

1. [Basic Syntax](#basic-syntax)
2. [AWK Patterns](#awk-patterns)
3. [AWK Actions](#awk-actions)
4. [Variables in AWK](#variables-in-awk)
5. [Built-in Variables](#built-in-variables)
6. [Control Flow](#control-flow)
7. [AWK Functions](#awk-functions)
8. [AWK Regular Expressions](#awk-regular-expressions)
9. [Input/Output](#input-output)
10. [AWK Example Scripts](#awk-example-scripts)

---

## Basic Syntax

AWK programs are written as a series of **patterns** and **actions**.

```
awk 'pattern { action }' file_name
```

- **Pattern**: Specifies the condition to be met for the action to be executed.
- **Action**: A block of code enclosed in `{}` to be executed if the pattern matches.

### Example:
```bash
awk '{ print $1 }' file.txt
```

- This will print the first column (field) of each line in `file.txt`.

---

## AWK Patterns

Patterns are used to match text or records in a file.

### 1. **Matching lines based on a condition:**
```bash
awk '$1 > 10 { print $1 }' file.txt
```

This will print the first field of lines where the first field is greater than 10.

### 2. **Matching specific string:**
```bash
awk '$1 == "John" { print $2 }' file.txt
```

This will print the second field of lines where the first field is "John".

### 3. **Regular Expressions as patterns:**
```bash
awk '$1 ~ /[a-z]+/ { print $1 }' file.txt
```

This will print the first field of lines where the first field matches a lowercase word.

### 4. **END and BEGIN patterns:**
- `BEGIN` is used to execute actions before processing any input lines.
- `END` is used to execute actions after all lines have been processed.

```bash
awk 'BEGIN { print "Start Processing" } { print $1 } END { print "End Processing" }' file.txt
```

---

## AWK Actions

Actions are enclosed in `{}` and can contain commands like `print`, `if`, `for`, etc.

### Example:
```bash
awk '{ print "Field 1: "$1 ", Field 2: "$2 }' file.txt
```

This will print both the first and second fields for each line in the file.

### Conditional Actions
```bash
awk '$1 > 10 { print "Large: "$1 }' file.txt
```

This will print "Large: <value>" if the first field is greater than 10.

---

## Variables in AWK

You can define and use variables in AWK.

### Example:
```bash
awk '{ sum += $1 } END { print sum }' file.txt
```

This will calculate the sum of the first field in the file.

### Assigning a value to a variable:
```bash
awk 'BEGIN { value = 100 } { print value }' file.txt
```

This will print `100` for each line in the file.

---

## Built-in Variables

AWK provides several built-in variables.

- **`$0`**: The entire line of input.
- **`$1`, `$2`, ...**: The individual fields of a line.
- **`NR`**: The number of records (lines) processed so far.
- **`NF`**: The number of fields in the current record.
- **`FS`**: The field separator (default is space or tab).
- **`OFS`**: The output field separator (default is space).
- **`RS`**: The input record separator (default is newline).
- **`ORS`**: The output record separator (default is newline).

### Example:
```bash
awk '{ print "Line number: " NR ", Fields: " NF }' file.txt
```

This will print the line number and the number of fields for each line.

---

## Control Flow

AWK supports standard control flow constructs such as `if`, `else`, `for`, and `while`.

### Example with `if`:
```bash
awk '{ if ($1 > 10) { print $1 } else { print "Small" } }' file.txt
```

This will print the first field if it is greater than 10, otherwise print "Small".

### Example with `for` loop:
```bash
awk '{ for(i=1; i<=NF; i++) { print $i } }' file.txt
```

This will print all fields in each line.

### Example with `while` loop:
```bash
awk '{ i = 1; while (i <= NF) { print $i; i++ } }' file.txt
```

This will print all fields in each line using a `while` loop.

---

## AWK Functions

AWK provides a variety of built-in functions such as `length`, `substr`, `index`, and `tolower`.

### Example with `length`:
```bash
awk '{ print length($1) }' file.txt
```

This will print the length of the first field.

### Example with `substr`:
```bash
awk '{ print substr($1, 1, 3) }' file.txt
```

This will print the first three characters of the first field.

### Example with `tolower`:
```bash
awk '{ print tolower($1) }' file.txt
```

This will print the first field in lowercase.

---

## AWK Regular Expressions

AWK supports regular expressions to match patterns in text.

### Example with `~` operator (matches regex):
```bash
awk '$1 ~ /^[A-Z]/ { print $1 }' file.txt
```

This will print the first field of lines where the first field starts with an uppercase letter.

### Example with `!~` operator (does not match regex):
```bash
awk '$1 !~ /^[A-Z]/ { print $1 }' file.txt
```

This will print the first field of lines where the first field does not start with an uppercase letter.

---

## Input/Output

### Redirecting Output

You can redirect the output of AWK to a file using `>` or `>>`.

```bash
awk '{ print $1 }' file.txt > output.txt
```

This will save the first field of each line in `file.txt` to `output.txt`.

### Input from File

AWK can process input files directly or via command-line arguments.

```bash
awk '{ print $1 }' file.txt
```

This will print the first field from `file.txt`.

### Reading from Multiple Files

AWK can process multiple files at once.

```bash
awk '{ print $1 }' file1.txt file2.txt
```

This will print the first field of each line in both `file1.txt` and `file2.txt`.

---

## AWK Example Scripts

### Example 1: Count lines in a file
```bash
awk 'END { print "Total lines:", NR }' file.txt
```

This will print the total number of lines in `file.txt`.

### Example 2: Print lines with more than 3 fields
```bash
awk 'NF > 3 { print $0 }' file.txt
```

This will print all lines that have more than 3 fields.

### Example 3: Print sum of fields
```bash
awk '{ sum += $1 } END { print "Total Sum:", sum }' file.txt
```

This will print the sum of the first field of each line in `file.txt`.

---

## Conclusion

AWK is a versatile tool for text processing and pattern matching. By mastering its syntax, you can automate tasks, process data, and perform complex text manipulation.

For further reference, consult the [AWK Manual](https://www.gnu.org/software/gawk/manual/).
