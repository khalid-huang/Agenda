#include"AgendaService.h"
#include<list>
using std::string;
using std::function;
using std::cout;
using std::list;
AgendaService::AgendaService() {
  startAgenda();
}
AgendaService::~AgendaService() {
  quitAgenda();
}
void AgendaService:: startAgenda() {
  storage_ = Storage::getInstance();
}
void AgendaService::quitAgenda() {
  delete storage_;
  storage_=NULL;
}
bool AgendaService::userLogIn(string userName, string password) {
  User user;
  list<User> userlist;
  user.setName(userName);
  user.setPassword(password);
  function<bool(const User&)> f = [&user](const User& user1) {
    return (user.getName() == user1.getName() && user.getPassword() == user1.getPassword());
  };
  userlist = storage_->queryUser(f);
  if(userlist.empty()) {
    return false;
  } else {
    return true;
  }
}
bool AgendaService::userRegister(string userName, string password, string email, string phone) {
  function<bool(const User&)> f = [userName](const User& user) {
    if(userName == user.getName())
      return true;
    else return false;
  };
  list<User> l;
  l = storage_->queryUser(f);
  if(l.size() != 0)
    return false;
  else {
    User user(userName, password, email, phone);
    storage_->createUser(user);
    return true;
  }
}
bool AgendaService::deleteUser(string userName, string password) {
  User user;
  int num;
  user.setName(userName);
  user.setPassword(password);
  function<bool(const Meeting&)> f0 = [&user](const Meeting& meeting) {
    return (user.getName() == meeting.getParticipator() || user.getName() == meeting.getSponsor());
  };
 storage_->deleteMeeting(f0);
  function<bool(const User&)> f = [&user](const User& user1) {
    return (user.getName() == user1.getName() && user.getPassword() == user1.getPassword());};
  num =  storage_->deleteUser(f);
  if(num != 0) {
    return true;
  } else {
    return false;
  }
}
list<User> AgendaService::listAllUsers() {
  function<bool(const User&)> f = [](const User& user) {
  return true;
  };
  list<User> list1;
  list1 = storage_->queryUser(f);
   return list1;
}
bool AgendaService::createMeeting(string userName, string title, string participator, string startDate, string endDate) {
   Date start = Date::stringToDate(startDate);
   Date end = Date::stringToDate(endDate);
   if(!Date::isValid(start) || !Date::isValid(end) || start >= end)
   return false;
   function<bool(const User&)> f = [&](const User& user) {
   if(participator == user.getName())
   return true;
   else
   return
   false;
   };
    function<bool(const Meeting&)> f1 = [&] (const Meeting& meeting) {
    if (meeting.getSponsor() == userName || meeting.getParticipator() == userName) {
			    if (end <= meeting.getStartDate()) 
			    return false;
			    if (start >= meeting.getEndDate()) 
			    return false;
			    return true;
	}
	if (meeting.getSponsor() == participator || meeting.getParticipator() == participator) {
			    if (end <= meeting.getStartDate()) 
			    return false;
			    if (start >= meeting.getEndDate()) 
			    return false;
			    return true;
			}
			return false;
		};
		function<bool(const Meeting&)> f2 = [&](const Meeting& meeting) {
			if (meeting.getSponsor() == userName || meeting.getParticipator() == userName) {
			    if (title != meeting.getTitle()) 
			    return false;
			    else return true;
			}
			if (meeting.getSponsor() == participator || meeting.getParticipator() == participator) {
				if (title != meeting.getTitle()) 
				return false;
			    else return true;
			}
			return false;
		};
		list<User> li = storage_->queryUser(f);
		if(li.empty())
		return false;
		list<Meeting> list1 = storage_->queryMeeting(f1);
		if(!list1.empty())
		return false;
		list1 = storage_->queryMeeting(f2);
		if(!list1.empty())
		return false;
		storage_->createMeeting(Meeting(userName, participator, start, end, title));
		return true;
}
  list<Meeting> AgendaService::meetingQuery(string userName, string title) {
    function<bool(const Meeting&)> f = [&userName, &title] (const Meeting& meeting) {
      if(userName == meeting.getSponsor() || userName == meeting.getParticipator()) {
	if(title == meeting.getTitle())
	  return true;
      }
      return false;
    };
    list<Meeting> list1;
    list1 = storage_->queryMeeting(f);
    return list1;
  }
 std::list<Meeting> AgendaService::meetingQuery(std::string userName, std::string startDate, std::string endDate) {
 std::list<Meeting> temp;
	Date start = Date::stringToDate(startDate);
	Date end = Date::stringToDate(endDate);
	if (!Date::isValid(start) || !Date::isValid(end)) {
		return temp;
	}
	if (start > end) {
		return temp;
	}
    std::function<bool(const Meeting&)> f = [&](const Meeting& meeting) {
        if (meeting.getSponsor() == userName || meeting.getParticipator() == userName) {
			    if (end < meeting.getStartDate()) 
			    return false;
			    if (start > meeting.getEndDate()) 
			    return false;
			    return true;
		}
		return false;
    };
    temp = storage_->queryMeeting(f);
    return temp;
}
  list<Meeting> AgendaService::listAllMeetings(string userName) {
    function<bool(const Meeting&)> f = [userName](const Meeting& meeting) {
      if(userName == meeting.getSponsor() || userName == meeting.getParticipator())
	return true;
	else 
	  return false;
    };
    list<Meeting> list1;
    list1 = storage_->queryMeeting(f);
    return list1;
  }
  list<Meeting> AgendaService::listAllSponsorMeetings(string userName) {
    function<bool(const Meeting&)> f = [userName](const Meeting& meeting) {
      if(userName == meeting.getSponsor())
	return true;
      else 
	return false;
    };
    list<Meeting> list1;
    list1 = storage_->queryMeeting(f);
    return list1;
  }
  list<Meeting> AgendaService::listAllParticipateMeetings(string userName) {
    function<bool(const Meeting&)> f = [userName] (const Meeting& meeting) {
      if(userName == meeting.getParticipator())
	return true;
      else
	return false;
    };
    list<Meeting> list1;
    list1 = storage_->queryMeeting(f);
    return list1;
  }
  bool AgendaService::deleteMeeting(std::string userName, std::string title) {
    std::function<bool(const Meeting&)> f = [&](const Meeting& meeting) {
        if (meeting.getSponsor() == userName && meeting.getTitle() == title)
            return true;
        else
            return false;
    };
    bool t = storage_->deleteMeeting(f);
    return t;
}
  bool AgendaService::deleteAllMeetings(string userName) {
    function<bool(const Meeting&)> f = [userName](const Meeting& meeting) {
      if(userName == meeting.getSponsor())
	return true;
      return false;
    };
    int num;
    num = storage_->deleteMeeting(f);
    if(num > 0)
      return true;
    else 
      return false;
  }
