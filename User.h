#ifndef USER_H
#define USER_H
#include<iostream>
using std::string;
class User {
    public:
        User() {}
        User(string name_, string password_, string email_, string phone_);
    string getName() const;
	void setName(string name_);
	string getPassword()const;
	void setPassword(string password_);
	string getEmail()const;
	void setEmail(string email_);
	string getPhone() const;
	void setPhone(string phnoe_); 
    private:
    string name;
	string password;
	string email;
	string phone;
};
#endif
