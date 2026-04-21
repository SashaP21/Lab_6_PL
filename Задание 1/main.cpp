#include <iostream>
#include <string>
#include <cctype>
#include "password_exceptions.h"

using std::string;
using std::cout;
using std::cin;

string get_password() {
    string password;
    cout << "Enter password\n";
    cin >> password;

    if (password.length() < 9)
        throw LengthError();

    bool has_lower = false;
    bool has_upper = false;
    bool has_digits = false;

    for (char c: password) {
        if (islower(c))
            has_lower = true;
        else if (isupper(c))
            has_upper = true;
        else if (isdigit(c))
            has_digits = true;
        if (c == 'l' || c == 'I' || c == '1' ||
                 c == 'o' || c == 'O' || c == '0')
            throw ForbiddenLetterError();
    }

    if (!has_digits)
        throw DigitError();
    if (!(has_lower && has_upper))
        throw RegisterError();

    return password;
}

int main() {
    string password;
    while (true) {
        try {
            password = get_password();
            break;
        }
        catch (const PasswordError& e) {
            std::cerr << e.what() << "\n";
        }
    }
    cout << "Your password: " << password << "\n";
}