#include"Storage.h"
#include<iostream>
#include<fstream>
using std::list;
using std::endl;
using std::fstream;
using std::string;
using std::function;
using std::ios;
Storage* Storage::instance_ = NULL;
Storage::Storage() {
    readFromFile("agenda.data");
}
bool Storage::sync() {
  if (writeToFile("agenda.data"))
     return true;
     return false;
}
Storage* Storage::getInstance() {
    if (instance_ == NULL) {
        instance_ = new Storage();
    }
    return instance_;
}

Storage::~Storage() {
    writeToFile("agenda.data");
    instance_ = NULL;
}
bool Storage::readFromFile(const char* fpath) {
  std::ifstream infile;
  int num, i;
  infile.open(fpath, ios::in);
  if (!infile) {
    return false;
  } else {
  string trash, name, password, email, phone;
  string sponsor, participator, time, title;
  getline(infile, trash, ':');
  getline(infile, trash, ':');
  infile >> num;
  for (i = 0; i < num; ++i) {
    getline(infile, trash, '"');
    getline(infile, name, '"');
    getline(infile, trash, '"');
    getline(infile, password, '"');
    getline(infile, trash, '"');
    getline(infile, email, '"');
    getline(infile, trash, '"');
    getline(infile, phone, '"');
    User user(name, password, email, phone);
    userList_.push_back(user);
  }
  getline(infile, trash, ':');
  getline(infile, trash, ':');
  infile >> num;
  Date date1, date2;
  for (i = 0; i < num; ++i) {
    getline(infile, trash, '"');
    getline(infile, sponsor, '"');
    getline(infile, trash, '"');
    getline(infile, participator, '"');
    getline(infile, trash, '"');
    getline(infile, time, '"');
    date1 = Date::stringToDate(time);
    getline(infile, trash, '"');
    getline(infile, time, '"');
    date2 = Date::stringToDate(time);
    getline(infile, trash, '"');
    getline(infile, title, '"');
    Meeting meeting(sponsor, participator, date1, date2, title);
    meetingList_.push_back(meeting);
    }
    infile.close();
  return true;
  }
}
bool Storage::writeToFile(const char* fpath) {
  std::ofstream outfile(fpath, std::ofstream::out);
  list<User>::iterator lit;
  list<Meeting>::iterator mit;
  if (!outfile) {
    return false;
  } else {

  int size = userList_.size();

  outfile << "{collection:\"User\",total:" << size << "}" << endl;
  for (lit = userList_.begin(); lit != userList_.end(); ++lit) {
    outfile << "{name:\"" << lit->getName() << "\", password:\"";
    outfile << lit->getPassword();
    outfile << "\",email:\"" << lit->getEmail();
    outfile << "\",phone:\"" << lit->getPhone() << "\"}" << endl;
  }
  size = meetingList_.size();
  outfile << "{collection:\"Meeting\",total:" << size  << "}" << endl;
  for (mit = meetingList_.begin(); mit != meetingList_.end(); ++mit) {
    outfile << "{sponsor:\"" << mit->getSponsor() << "\",participator:\"";
    outfile << mit->getParticipator();
    outfile << "\",sdate:\"" << Date::dateToString(mit->getStartDate());
    outfile << "\",edate:\"" <<Date::dateToString(mit->getEndDate()) ;
    outfile << "\", title:\"" << mit->getTitle()<< "\"}" << endl;
  }
  outfile.close();
  return true;
  }
}
void Storage::createUser(const User& user) {
    userList_.push_back(user);
}
list<User> Storage::queryUser(function<bool(const User&)> filter) {
            list<User> temp;
            list<User>::iterator lit;
            for (lit = userList_.begin(); lit != userList_.end(); 
                 lit++) {
                if (filter(*lit)) {
                    temp.push_back(*lit);
                }
            }
            return temp;
            }

int Storage::updateUser(function<bool(const User&)> filter, std::function<void(User&)> switcher) {
        int count = 0;
        list<User>::iterator lit;
        for (lit = userList_.begin(); lit != userList_.end();
             lit++) {
            if (filter(*lit)) {
                count++;
                switcher(*lit);
            }
        }
        return count;
    }

int Storage::deleteUser(function<bool(const User&) > filter) {
            int count = 0;
            list<User> list1;
            list<User>::iterator it;
            for (it = userList_.begin(); it != userList_.end();
                it++) {
                if (filter(*it)) {
                    count++;
                } else {
                 list1.push_back(*it);
                }
            }
            userList_ = list1;
            return count;
        }

void Storage::createMeeting(const Meeting& a) {
        meetingList_.push_back(a);
        }

std::list<Meeting> Storage::queryMeeting(function<bool(const Meeting&)> filter) {
            list<Meeting> temp;
            list<Meeting>::iterator lit;
            for (lit = meetingList_.begin(); 
                  lit != meetingList_.end(); lit++) {
                if (filter(*lit)) {
                    temp.push_back(*lit);
                }
            }
            return temp;
}



int Storage::updateMeeting(function<bool(const Meeting&)> filter,
        std::function<void(Meeting&)> switcher) {
        int count = 0;
        list<Meeting>::iterator lit;
        for (lit = meetingList_.begin(); lit != meetingList_.end();
             lit++) {
            if (filter(*lit)) {
                switcher(*lit);
                count++;
            }
        }
        return count;
    }

    int Storage::deleteMeeting(std::function<bool(const Meeting&)> filter) {
            int count = 0;
            list<Meeting> list1;
            list<Meeting>::iterator it;
            for (it = meetingList_.begin(); it != meetingList_.end(); ++it) {
                if (filter(*it)) {
                    count++;
                } else {
                  list1.push_back(*it);
                }
            }
            meetingList_ = list1;
            return count;
    }



