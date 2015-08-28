#ifndef MEETING_H
#define MEETING_H
#include<iostream>
using std::string;
#include"Date.h"
class Meeting {
 public:
    Meeting();
    Meeting(string sponsor, string participator, Date startTime, Date endTime, string title);
    string getSponsor() const;
    string getParticipator()const;
    Date getStartDate() const;
    Date getEndDate() const;
    string getTitle()const;
    void setSponsor(string sponsor);

    void setParticipator(string participator_);
    void setStartDate(Date& statTime);
    void setEndDate(Date& endTime);
    void setTitle(string title);
 private:
    string sponsor_;
    string participator_;
    Date startDate_;
    Date endDate_;
    string title_;
};
#endif
