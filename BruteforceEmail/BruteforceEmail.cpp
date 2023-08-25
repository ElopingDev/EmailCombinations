#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

// This tool has been created to recover a specific email however i added instructions on how you can use it yourself to create a list of emails using only a few letters

using namespace std;

string generateRandomString(int length) {
    const string characters = "abcdefghijklmnopqrstuvwxyz0123456789";
    const int charactersLength = characters.length();
    string randomString;

    for (int i = 0; i < length; ++i) {
        randomString += characters[rand() % charactersLength];
    }

    return randomString;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    ofstream outputFile("email_combinations.txt");
    if (!outputFile.is_open()) {
        cout << "Error opening file for writing.\n";
        return 1;
    }

    for (int i = 0; i < 60466176; ++i) { // Number of possible combinations
        string email = "pe" + generateRandomString(3) + "1" + generateRandomString(2) + "@hotmail.com"; // cleartext characters + generateRandomString on hidden characters
        outputFile << email << "\n";
    }

    outputFile.close();

    cout << "Email combinations generated and saved to email_combinations.txt\n";

    return 0;
}