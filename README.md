# Word Frequency Analyzer

This is a simple C++ command-line program that takes user input and analyzes the **frequency** of:

- Words
- Numbers
- Special characters

It then displays the **top 10 most frequent** items in each category.

## 📂 Project Structure

- "proj1.cpp" — Main program that reads and analyzes input.

## 💡 How It Works

1. The program prompts the user to input lines of text.
2. It processes each line to:
   - Convert words to lowercase.
   - Distinguish between alphabetic words, numeric strings, and special characters.
   - Track frequency of each.
3. Outputs the **top 10 most frequent** words, numbers, and special characters.

### Sample Use

Please enter the input. When finished, press enter on an empty line: 
Hello world!
123 123 hello
!

Top 10: words
hello - 2
world - 1

Top 10: numbers
123 - 2

Top 10: special characters
! - 2
