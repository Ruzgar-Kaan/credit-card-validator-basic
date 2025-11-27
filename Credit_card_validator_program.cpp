#include <iostream>
#include <algorithm>

// Returns the sum of digits of a number after doubling (used in Luhn algorithm)
int getDigit(const int number);

// Sums the digits in odd positions (from the right)
int sumOddDigit(const std::string& cardNumber);

// Sums the digits in even positions (from the right), applies doubling rule
int sumEvenDigit(const std::string& cardNumber);

int main() {

    std::string cardNumber;
    int result = 0;

    std::cout << "Enter a credit card number: ";
    std::cin >> cardNumber;

    // Check if input contains only digits
    if (!std::all_of(cardNumber.begin(), cardNumber.end(), ::isdigit)) {
        std::cout << "Invalid input. Please enter digits only.\n";
        return 0;
    }

    // Apply Luhn algorithm: even-position sum + odd-position sum
    result = sumEvenDigit(cardNumber) + sumOddDigit(cardNumber);

    // If the total mod 10 equals 0, the card number is valid
    if (result % 10 == 0) {
        std::cout << cardNumber << " is valid\n";
    } else {
        std::cout << cardNumber << " is not valid\n";
    }

    return 0;
}

// Extracts processed digit (if doubled number is >= 10, sum its digits)
int getDigit(const int number) {
    return number % 10 + (number / 10 % 10);
}

// Adds digits in the odd positions (from right to left)
int sumOddDigit(const std::string& cardNumber) {

    int sum = 0;

    // Start from last digit, move backwards by 2
    for (int i = cardNumber.size() - 1; i >= 0; i -= 2) {
        sum += cardNumber[i] - '0'; // Convert char to int
    }

    return sum;
}

// Adds processed digits in even positions (from right to left)
int sumEvenDigit(const std::string& cardNumber) {

    int sum = 0;

    // Start one position before last, move backwards by 2
    for (int i = cardNumber.size() - 2; i >= 0; i -= 2) {

        // Double the digit and convert properly using getDigit()
        sum += getDigit((cardNumber[i] - '0') * 2);
    }

    return sum;
}
