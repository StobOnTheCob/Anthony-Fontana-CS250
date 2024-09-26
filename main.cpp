/*
  9/25/2024
  Dr.V
  CS250
  Author: Anthony Fontana

  Description: This program asks the user for the amount of rows and
  seats per row to be had in any given airplane. It prompts the user
  to fill seats until there are no seats left or the user is done.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displaySeatingChart(const vector<vector<char>>& seats) {

    cout << "Seating Chart:\n";
    cout << "   ";

    for (char letter = 'A'; letter < 'A' + seats[0].size(); ++letter) {
        cout << letter << " ";
    }
    cout << endl;
    for (int i = 0; i < seats.size(); ++i) {
        cout << i + 1 << "  "; // Display row numbers
        for (int j = 0; j < seats[i].size(); ++j) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSeatAvailable(const vector<vector<char>>& seats, int row, int seat) {
    return seats[row][seat] == '0';
}

// Function to check if a string is a valid integer
bool isValidInteger(const string& input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return !input.empty();  // Ensure input isn't empty
}

// Function to check if the input is a valid seat letter
bool isValidSeatLetter(char seatLetter, int maxSeats) {

    seatLetter = toupper(seatLetter); // Normalize to uppercase
    return seatLetter >= 'A' && seatLetter < 'A' + maxSeats;
}

// Function to get a valid integer input as a string and convert it to int
int getSafeIntInput(const string& prompt) {

    string input;
    while (true) {
        cout << prompt;
        cin >> input;

        // Validate if the input is a valid integer
        if (isValidInteger(input)) {
            return stoi(input);  // string to integer I learned from Youtube lol
        } else {
            cout << "Invalid input. Please enter a valid number.\n";
        }
    }
}

// Function to get a valid seat letter from the user
char getSafeSeatLetterInput(const string& prompt, int maxSeats) {
    char seatLetter;
    while (true) {
        cout << prompt;
        cin >> seatLetter;

        // Validate if the input is a valid seat letter
        if (isValidSeatLetter(seatLetter, maxSeats)) {
            return toupper(seatLetter);  // Normalize to uppercase and return
        } else {
            cout << "Invalid seat. Please enter a valid seat letter (A-" << char('A' + maxSeats - 1) << ").\n";
        }
    }
}

int main() {

    int rows = getSafeIntInput("Enter the number of rows: ");

    int seatsPerRow = getSafeIntInput("Enter the number of seats per row (A, B, C, ...): ");

    // Initialize seating chart with all available seats
    vector<vector<char>> seatingChart(rows, vector<char>(seatsPerRow, '0'));

    cout << endl;
    displaySeatingChart(seatingChart);
    cout << endl;

    vector<string> assignedSeats;
    int availableSeats = rows * seatsPerRow;

    while (availableSeats > 0) {
    try {
        // Input row number
        int row = getSafeIntInput("Enter row number: ");
        if (row < 1 || row > rows) {
            throw "Row number is out of range. Please enter a valid row number.";
        }
        row--;  // Adjust for 0-based indexing

        // Input seat letter
        char seatLetter = getSafeSeatLetterInput("Enter seat letter (A-" + string(1, 'A' + seatsPerRow - 1) + "): ", seatsPerRow);
        cout << endl;
        int seat = seatLetter - 'A'; // Convert seat letter to index (0-based)

        // Check if the seat is available
        if (!isSeatAvailable(seatingChart, row, seat)) {
            throw "Seat already taken. Try again.";
        }

        // Mark the seat as unavailable and store the assignment
        seatingChart[row][seat] = 'X';
        availableSeats--;

        // Store assigned seat in the format "RowColumn" ex: "1A"
        assignedSeats.push_back(to_string(row + 1) + seatLetter);

        displaySeatingChart(seatingChart);
        cout << endl;
        cout << "Seats available: " << availableSeats << endl << endl;

        // Automatically end if all seats are assigned
        if (availableSeats == 0) {
            cout << "All seats are assigned." << endl << endl;;
            break;  // Exit loop when no seats are available
        }

        // Validate user input for 'y' or 'n'
        char cont;
        while (true) {

            cout << "Do you want to assign another seat? (Y/N): ";
            cin >> cont;
            cout << endl;

            if (cont == 'y' || cont == 'Y' || cont == 'n' || cont == 'N') {
                break;  // Valid input, exit the loop
            } else {
                cout << "Invalid input. Please enter 'Y' or 'N'" << endl << endl;
            }
        }

        if (cont == 'n' || cont == 'N') break;

    } catch (const char* msg) {
        // Catch exceptions and print the error message
        cout << msg << endl;
        continue;
    }
}

    // Display final seating chart and summary
    cout << "Final Seating Chart Displayed Below" << endl << endl;

    displaySeatingChart(seatingChart);
    cout << endl;

    cout << assignedSeats.size() << " seats assigned: ";
    for (const string& seat : assignedSeats) {
        cout << seat << " ";
    }
    cout << endl;

    return 0;
}
