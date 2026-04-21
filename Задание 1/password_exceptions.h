#ifndef _1_PASSWORD_EXCEPTIONS_H
#define _1_PASSWORD_EXCEPTIONS_H

#include <exception>

class PasswordError : public std::exception {
public:
    const char* what() const noexcept override = 0;
};

class LengthError : public PasswordError {
public:
    const char* what() const noexcept override;
};

class RegisterError : public PasswordError {
public:
    const char* what() const noexcept override;
};

class DigitError : public PasswordError {
public:
    const char* what() const noexcept override;
};

class ForbiddenLetterError : public PasswordError {
public:
    const char* what() const noexcept override;
};

#endif //_1_PASSWORD_EXCEPTIONS_H