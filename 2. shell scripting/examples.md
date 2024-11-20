# Content for Shell Script Programs that includes the "check substring occurrence" script and more examples

shell_script_examples_content = """
# Shell Script Program Examples

This document contains examples of shell scripts for different use cases. These examples can help in learning and understanding the concepts of shell scripting.

---

## Table of Contents

1. [Check Substring Occurrences](#check-substring-occurrences)
2. [Check if a Number is Prime](#check-if-a-number-is-prime)
3. [Count Number of Files in a Directory](#count-number-of-files-in-a-directory)
4. [Calculate Factorial](#calculate-factorial)
5. [Reverse a String](#reverse-a-string)

---

## Check Substring Occurrences

This script checks whether the entered substring is present in a given string, prints the number of occurrences, and their positions.

```bash
#!/bin/bash
# Script to check if a substring is present in a string and print the number of occurrences and their positions.

# Prompt user for the string and substring
echo "Enter the main string: "
read main_string

echo "Enter the substring: "
read substring

# Initialize a variable to count occurrences
count=0

# Loop through the string and find the substring
position=0
while [[ "$main_string" =~ "$substring" ]]; do
  # Get the position of the first occurrence of the substring
  index=$(echo "$main_string" | grep -b -o "$substring" | head -n 1 | cut -d: -f1)
  
  # Print the position and increase the counter
  echo "Occurrence $count found at position: $index"
  
  # Remove the found substring up to the index and continue searching
  main_string="${main_string:$(($index + 1))}"
  count=$((count + 1))
done

# Print the total number of occurrences
echo "Total occurrences: $count"
