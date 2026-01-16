#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cout << "Welcome to the Index for Password Strength (IPS)!" << endl;

    string passwd;
    cout << "\nEnter your password (8-15 characters): ";
    cin >> passwd;

    if (passwd.length() < 8) {
        cout << "Invalid Password Length, tip: add more characters!" << endl;
        return 0;
    }
    if (passwd.length() > 15) {
        cout << "Invalid Password Length, tip: less characters please!" << endl;
        return 0;
    }

    double basicScore = 0, lengthScore = 0, repetitionScore = 0, complexityScore = 0;

    vector<string> basicProblems, lengthProblems, repetitionProblems, complexityProblems;

    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string nums  = "0123456789";
    string special = "!@#$%^&*()-_{}[]|;:.,?\\<>+~`=";

    bool hasLower = false, hasUpper = false, hasNum = false, hasSpecial = false;

    for (char c : passwd) {
        if (lower.find(c) != string::npos) hasLower = true;
        if (upper.find(c) != string::npos) hasUpper = true;
        if (nums.find(c) != string::npos) hasNum = true;
        if (special.find(c) != string::npos) hasSpecial = true;
    }

    if (!hasLower) basicProblems.push_back("The password doesn't contain any lowercase letters");
    if (!hasUpper) basicProblems.push_back("The password doesn't contain any uppercase letters");
    if (!hasNum) basicProblems.push_back("The password doesn't contain any numbers");
    if (!hasSpecial) basicProblems.push_back("The password doesn't contain any special characters");

    if (hasLower) basicScore += 25;
    if (hasUpper) basicScore += 25;
    if (hasNum) basicScore += 25;
    if (hasSpecial) basicScore += 25;

    if (passwd.length() >= 8)  lengthScore += 25;
    if (passwd.length() >= 10) lengthScore += 25;
    if (passwd.length() >= 12) lengthScore += 25;
    if (passwd.length() >= 14) lengthScore += 25;

    if (passwd.length() < 15) {
        lengthProblems.push_back("Longer passwords are generally stronger");
    }

    vector<char> uniqueChars;
    vector<int> counts;

    for (char c : passwd) {
        auto it = find(uniqueChars.begin(), uniqueChars.end(), c);
        if (it == uniqueChars.end()) {
            uniqueChars.push_back(c);
            counts.push_back(1);
        } else {
            counts[it - uniqueChars.begin()]++;
        }
    }

    for (int count : counts) {
        if (count > 1) {
            repetitionProblems.push_back("The password contains repeated characters");
        } else {
            repetitionScore += 100.0 / (passwd.length() - 1);
        }
    }

    if (repetitionScore > 100) repetitionScore = 100;

    int sameChar = 0, sameClass = 0, sameLetter = 0;

    for (size_t i = 0; i < passwd.length() - 1; i++) {
        if (passwd[i] != passwd[i + 1])
            complexityScore += 12.5 / (passwd.length() - 1);
        else
            sameChar++;

        bool currLower = lower.find(passwd[i]) != string::npos;
        bool nextLower = lower.find(passwd[i + 1]) != string::npos;
        bool currUpper = upper.find(passwd[i]) != string::npos;
        bool nextUpper = upper.find(passwd[i + 1]) != string::npos;

        if (currLower && nextUpper && tolower(passwd[i + 1]) != passwd[i])
            complexityScore += 12.5 / (passwd.length() - 1);
        else if (currUpper && nextLower && toupper(passwd[i + 1]) != passwd[i])
            complexityScore += 12.5 / (passwd.length() - 1);
        else
            sameLetter++;
    }

    if (sameChar > 0)
        complexityProblems.push_back("Repeated consecutive characters detected");
    if (sameClass > 0)
        complexityProblems.push_back("Repeated consecutive character classes detected");
    if (sameLetter > 0)
        complexityProblems.push_back("Repeated consecutive letters detected");

    double totalScore = (basicScore + lengthScore + repetitionScore + complexityScore) / 4.0;

    cout << "\nBasic Factor: " << basicScore << "/100";
    cout << "\nLength Factor: " << lengthScore << "/100";
    cout << "\nRepetition Factor: " << repetitionScore << "/100";
    cout << "\nComplexity Factor: " << complexityScore << "/100";
    cout << "\n\nTotal Password Strength: " << round(totalScore * 100) / 100 << "/100\n";

    cout << "\nIssues Identified:\n";
    for (auto &p : basicProblems) cout << " - " << p << endl;
    for (auto &p : lengthProblems) cout << " - " << p << endl;
    for (auto &p : repetitionProblems) cout << " - " << p << endl;
    for (auto &p : complexityProblems) cout << " - " << p << endl;

    return 0;
}
