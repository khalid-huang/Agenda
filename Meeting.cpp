#include"Meeting.h"
Meeting::Meeting() {}
Meeting::Meeting(string sponsor, string participator, Date startTime, Date endTime, string title) {
    sponsor_ = sponsor;
    participator_ = participator;
    startDate_ = startTime;
    endDate_ = endTime;
    title_ = title;
}
string Meeting::getSponsor() const {
    return sponsor_;
}
string Meeting::getParticipator()const {
  return participator_;
}
Date Meeting::getStartDate() const {
  return startDate_;
}
Date Meeting::getEndDate()const {
  return endDate_;
}
string Meeting::getTitle()const {
  return title_;
}
void Meeting::setSponsor(string sponsor) {
sponsor_ = sponsor;
}
void  Meeting::setParticipator(string participator) {
  participator_ = participator;
}
void Meeting::setStartDate(Date & startTime)  {
  startDate_ = startTime;
}
void Meeting::setEndDate(Date & endTime) {
  endDate_ = endTime;
}
void Meeting::setTitle(string title) {
  title_ = title;
}
