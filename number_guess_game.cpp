#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Every time different sequence of numbers is chosen
    int number = rand() % 100 + 1; // Random number between 1 and 100
    int guess;

    cout << "Guess the number (between 1 and 100):";

    while (true) {
        cin >> guess;

        if (guess < number) {
            cout << "Number is too low.Please try again: ";
        } else if (guess > number) {
            cout << "Number is too high.Please try again: ";
        } else {
            cout << "Congratulations! You guessed the number.\n";
            break;
        }
    }

    return 0;
}