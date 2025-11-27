# Credit Card Validator (Luhn Algorithm)

This is a simple credit card number validator written in C++.  
It implements the Luhn Algorithm, which is commonly used to verify the validity of credit card numbers.

The project demonstrates basic C++ practices such as input handling, loops, string manipulation, and algorithm implementation.

****************************************************************************************************************************************************

# How to Compile and Run

To compile the program with g++, run the following command:

g++ Credit_card_validator_program.cpp -o validator


After compilation, you can run the program with:

./validator

****************************************************************************************************************************************************

1. Starting from the rightmost digit:
   - Digits in odd positions are added directly.
   - Digits in even positions are doubled. If the result is greater than 9, the digits are added together (for example, 12 becomes 1 + 2 = 3).
2. The sums are combined.
3. If the final total is divisible by 10, the credit card number is considered valid.

****************************************************************************************************************************************************

# NOTE

 This is a basic, beginner-level project meant for learning purposes.
It can be expanded by adding features such as:

- Detecting card type (Visa, MasterCard, etc.)

- Better input formatting

- Splitting logic into separate files or classes

- Adding automated tests
