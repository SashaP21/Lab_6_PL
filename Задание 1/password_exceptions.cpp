#include "password_exceptions.h"

const char *LengthError::what() const noexcept {
    return "LengthError: Password length must be at least 9 characters";
}

const char* RegisterError::what() const noexcept {
    return "RegisterError: Password must contain both upper and lower case letters";
}

const char* DigitError::what() const noexcept {
    return "DigitError: Password must contain at least one digit";
}

const char* ForbiddenLetterError::what() const noexcept {
    return "ForbiddenLetterError: Password contains forbidden letters (l, I, 1, o, O, 0)";
}