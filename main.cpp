#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Constants for menu choices
const int ADULT_CHOICE = 1,
          CHILD_CHOICE = 2,
          SENIOR_CHOICE = 3,
          QUIT_CHOICE = 4;

// Constants for membership rates
const double ADULT = 40.0,
             CHILD = 20.0,
             SENIOR = 30.0;

const int MIN_MONTHS = 0;
const int MAX_MONTHS = 60;

// Add function prototypes here
void displayCharges(double charges);
double choiceToUSD(int choice, int months);
int getIntInRange(string prompt, int min, int max);
void displayMenu();
int getChoice();
void handleChoice(int choice);

int main() {
    // Variables
    int choice = 0;         // Menu choice
    do {
        displayMenu();
        choice = getIntInRange("", ADULT_CHOICE, QUIT_CHOICE);
        handleChoice(choice);
    } while (choice != QUIT_CHOICE);

    return 0;
}


void displayCharges(double charges) {
    cout << fixed << showpoint << setprecision(2);
    cout << "The total charges are $" << charges << endl;
}

double choiceToUSD(int choice, int months) {
    double usd = 0.0;
    switch (choice) {
    case ADULT_CHOICE:
        usd = months * ADULT;
        break;
    case CHILD_CHOICE:
        usd = months * CHILD;
        break;
    case SENIOR_CHOICE:
        usd = months * SENIOR;
    }
    return usd;
}

int getIntInRange(string prompt, int min, int max) {
    int n = 0;
    bool next = true;
    while(next) {
        cout << prompt;
        cin >> n;
        if(cin) {
            if(min <= n and n <= max) {
                next = false;
            } 
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(next) {
          cout << "ERROR: Out of range(" << min << ", " << max << ")" <<endl;
        }
    }
    return n;
}

void displayMenu() {
    cout << "\n\t\tHealth Club Membership Menu\n\n"
         << "1. Standard Adult Membership\n"
         << "2. Child Membership\n"
         << "3. Senior Citizen Membership\n"
         << "4. Quit the Program\n\n"
         << "Enter your choice: ";
}

void handleChoice(int choice) {
    // Validate and process the user's choice.
    if (choice == QUIT_CHOICE) {
        return;
    }

    int months = 0;         // Number of months
    double charges_USD = 0.0;   // Monthly charges
    months = getIntInRange("For how many months? ", MIN_MONTHS, MAX_MONTHS);
    charges_USD = choiceToUSD(choice, months);
    displayCharges(charges_USD);
}