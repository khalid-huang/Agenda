#include"User.h"
User::User(string name_, string password_, string email_, string phone_) {
    name = name_;
    password = password_;
    email = email_;
    phone = phone_;
}
string User::getName() const {
    return name;
}
void User::setName(string name_) {
    name = name_;}
string User::getPassword() const {
    return password;
}
void User::setPassword(string password_) {
    password = password_;
}
string User::getEmail()const {
    return email;
}
void User::setEmail(string email_) {
    email = email_;
}
string User::getPhone()const {
    return phone;
}
void User::setPhone(string phone_) {
    phone = phone_;
}

