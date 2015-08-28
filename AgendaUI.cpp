#include"AgendaUI.h"
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using std::cout;
using std::left;
using std::right;
using std::setw;
using std::setfill;
using std::cin; 
using std::endl;
using std::list;
AgendaUI::AgendaUI() {
  startAgenda();
}
void AgendaUI::OperationLoop() {
  string op;
  cin >> op;
system("reset");
  executeOperation(op);
}
void AgendaUI::startAgenda() {
  system("reset");
  cout << setw(40) << setfill('-') << std::right<< "Agenda" << setw(40) << setfill('-') << right << " " << endl;
  cout << setw(0) << "Action :" << endl;
  cout << "l     - log in Agenda by user name and password" << endl;
  cout << "r     - register an Agenda account" << endl;
  cout << "q     - quit Agenda" << endl;
  cout << setfill('-') << setw(65) << " "  << endl;
  cout << setw(0) << "Agenda : ~$";
  OperationLoop();
}
bool AgendaUI::executeOperation(string op) {
  if(op == "l")
    userLogIn();
  if(op == "r")
    userRegister();
  if(op == "q")
    quitAgenda();
}
void face(string userName) {
  system("reset");
    cout << setw(41) << setfill('-') << std::right << " Agenda " << setw(23) << " " << endl;
  cout << "Action :" << endl;
  cout << "o     - log out Agenda" << endl;
  cout << "dc    - delete Agenda account" << endl;
  cout << "lu    - list all Agenda user" << endl;
  cout << "cm    - create a meeting" << endl;
  cout << "la    - list all meetings" << endl;
  cout << "las   - list all sponsor meetings"  << endl;
  cout << "lap   - list all  participate meetings" << endl;
  cout << "qm    - query meeting by title" << endl;
  cout << "qt    - query meeting by time interval" << endl;
  cout << "dm    - delete meeting by title" << endl;
  cout << "da    - delete all meetings" << endl;
  cout << setw(64) << setfill('-') << " " << endl << endl;
  cout << "[Tips]:Please choose a action to execute:" << endl;
  }
void AgendaUI::userLogIn() {
  void face(string username);
  string op;
  cout << setw(40) << setfill('-') << std::right<< "LOG IN" << setw(40) << setfill('-') << right << " " << endl;
  cout << "[log in] [user name] [password]" << endl;
  cout << "[log in] ";
  cin >> userName_ >> userPassword_;
  if(agendaService_.userLogIn(userName_, userPassword_)) {
  cout << endl;
  cout << "[log in] succeed!" << endl;
  face(userName_);
  cin >> op;
  while(1) {
  system("reset");
  if(op == "dc") {
    deleteUser();
    break;
  }
  else if(op == "fx") {
  cout << "The stackgame is buliding.Please call chuang wei for help" << endl << "Please enter any charater to continue";
  getchar();
}
  else if(op == "lu")
    listAllUsers();
  else if(op == "cm")
    createMeeting();
  else if(op == "la")
    listAllMeetings();
  else if(op == "las")
    listAllSponsorMeetings();
  else if(op == "lap")
     listAllParticipateMeetings();
  else if(op == "qm")
    queryMeetingByTitle();
  else if(op == "qt")
    queryMeetingByTimeInterval();
  else if(op == "dm")
    deleteMeetingByTitle();
  else if(op == "da")
    deleteAllMeetings();
  else if(op == "o") {
    break;
  }
  face(userName_);
  cout << "Agenda@" << userName_ << ":" << endl;
  cin >> op;
  }
  cout << "[Tips] Enter any charater to continue!" << endl;
  getchar();
  getchar();
  startAgenda();
  } else {
    cout << endl << "[error] log in fail!" << endl;
    cout << "[Tips] Enter any charater to continue!" << endl;
    getchar();
    startAgenda();
}
}
void AgendaUI::userLogOut() {
    startAgenda();
   }
void AgendaUI::userRegister() {
  string email, phone;
  cout << setw(40) << setfill('-') << std::right<< "USER REGISTER" << setw(40) << setfill('-') << right << " " << endl;
  cout << "[register] [username] [password] [email] [phone]" << endl;
  cout << "[register] ";
  cin >>userName_ >> userPassword_ >> email >> phone;
  cout << endl;
  if(agendaService_.userRegister(userName_, userPassword_, email, phone)) {
    cout << "[register] succeed!"<< endl;
    while(1) {
    cout << "[tip] Do you want to log in? [yes or no]" << endl;
    string op;
    cin >> op;
    if(op == "yes") {
    userLogIn();
    break;
    }
    else if(op == "no")
    break;
    else
    cout << "Try again Please";
    }
    startAgenda();
  } else { cout << "[error] register fail!";
  startAgenda();
  }
}
void AgendaUI::deleteUser() {
        cout << setw(40) << setfill('-') << std::right<< "DELETE USER" << setw(40) << setfill('-') << right << " " << endl;
	if(agendaService_.userLogIn(userName_, userPassword_))
	if(agendaService_.deleteUser(userName_, userPassword_))
	cout << endl << "[delete agenda account] succeed!" << endl;
        cout << "[Tip]: Please input any character to continue;" << endl;
        getchar();
        getchar();
        cout << "Agenda : ~$" << endl;
}
void AgendaUI::listAllUsers() {
        string op;
	list<User> list1;
	list1 = agendaService_.listAllUsers();
	list<User>::iterator lit;
cout << setw(40) << setfill('-') << std::right<< "LIST ALL USERS" << setw(40) << setfill('-') << right << " " << endl;
        cout << setfill(' ');
	cout << setw(15) << left << "name" << setw(20) << left << "mail" << setw(0) << left << "phone" <<endl;
	for(lit = list1.begin(); lit != list1.end(); ++lit) {
		cout << setw(15) << left << lit->getName() << setw(20) << left << lit->getEmail();
		cout << setw(0) << left << lit->getPhone() << endl;
	}
        cout << "[Tip]: Please input any character to continue;" << endl;
        getchar();
        getchar();
        cout << "Agenda : ~$" << endl;

}
void AgendaUI::createMeeting() {
        cout << setw(40) << setfill('-') << std::right<< "CREATER  MEETING" << setw(40) << setfill('-') << right << " " << endl;
	if(agendaService_.userLogIn(userName_, userPassword_)) {
	string title, participator, starttime, endtime;
	cout << endl <<"[create meeting] [title] [participator] [start time<yyyy-mm-dd/hh:mm>] [end time<yyyy-mm-dd/hh:mm>]";
	cout << endl << "[create meeting] ";
    cin >> title >> participator >> starttime >> endtime;
    if(agendaService_.createMeeting(userName_, title, participator, starttime, endtime)) {
		cout << endl << "[creat meeting] succed!" << endl;
	} else {
		cout << endl << "[error] create meeting fail!" << endl;
	}
    }
        cout << "[Tip]: Please input any character to continue;" << endl;
        getchar();
        getchar();
        cout << "Agenda : ~$" << endl;
}

void AgendaUI::listAllMeetings() {
	list<Meeting> list1;
	list1 = agendaService_.listAllMeetings(userName_);
        cout << setw(40) << setfill('-') << std::right<< "LIST ALLMEETINGS" << setw(40) << setfill('-') << right << " " << endl;
	printMeetings(list1);
	cout << endl << "[Tip]: Please input any character to continue;" << endl;
        getchar();
        getchar();
        cout << "Agenda : ~$" << endl;

}
void AgendaUI::listAllSponsorMeetings() {
	list<Meeting> list1;
    list1 = agendaService_.listAllSponsorMeetings(userName_);
        cout << setw(40) << setfill('-') << std::right<< "LIST ALL SPONSORMEETINGS" << setw(40) << setfill('-') << right << " " << endl;
	printMeetings(list1);
	cout << endl << "[Tip]: Please input any character to continue;" << endl;
        getchar();
        getchar();
        cout << "Agenda : ~$" << endl;

}
void AgendaUI::listAllParticipateMeetings() {
	list<Meeting> list1;
	list1 = agendaService_.listAllParticipateMeetings(userName_);
        cout << setw(40) << setfill('-') << std::right<< "LIST ALL PARTICIPATEMEETINGS" << setw(40) << setfill('-') << right << " " << endl;
	printMeetings(list1);
        cout << endl << "[Tip]: Please input any character to continue;" << endl;
        getchar();
        getchar();
        cout << "Agenda : ~$" << endl;

}
void AgendaUI::queryMeetingByTitle() {
	string title;
	list<Meeting> list1;
        cout << setw(40) << setfill('-') << std::right<< "QUERY MEETING BY TITLE" << setw(40) << setfill('-') << right << " " << endl;
	cout << "[query meeting] " ;
	cin >> title;
	cout << endl;
	list1 = agendaService_.meetingQuery(userName_, title);
	printMeetings(list1);
	cout << endl << "[Tip]: Please input any character to continue;" << endl;
        getchar();
        getchar();
        cout << "Agenda : ~$" << endl;

}
void AgendaUI::queryMeetingByTimeInterval() {
	string startDate, endDate;
        cout << setw(40) << setfill('-') << std::right<< "QUERY MEETINGBYTIMEINTERVAL" << setw(40) << setfill('-') << right << " " << endl;
	cout << endl << "[query meetings] [start time<yyyy-mm-dd/hh:mm>] [end time <yyyy-mm-dd/hh:mm>]" << endl;
	cout << "[query meetings] ";
	cin >> startDate >> endDate;
	list<Meeting> list1;
	cout << endl << "[query meetings]" << endl;
	list1 = agendaService_.meetingQuery(userName_, startDate, endDate);
	printMeetings(list1);
        cout << "[Tip]: Please input any character to continue;" << endl;
        getchar();
        getchar();
        cout << "Agenda : ~$" << endl;

}
void AgendaUI::deleteMeetingByTitle(){
	string title;
        cout << setw(40) << setfill('-') << std::right<< "DELETE MEETING BY TITLE" << setw(40) << setfill('-') << right << " " << endl;
	cin >> title;
	if(agendaService_.deleteMeeting(userName_, title))
		cout << endl << "[delete meeting by title] succeed!" << endl;
	else
		cout << endl << "[error] delete meeting fail!" << endl;
        cout << "[Tip]: Please input any character to continue;" << endl;
        getchar();
        getchar();
        cout << "Agenda : ~$" << endl;

}
void AgendaUI::deleteAllMeetings() {
        cout << setw(40) << setfill('-') << std::right<< "DELETE ALL MEETINGS" << setw(40) << setfill('-') << right << " ";
	if(agendaService_.deleteAllMeetings(userName_))
		cout << "[delete all meetings] succeed!" << endl;
        cout << "[Tip]: Please input any character to continue;" << endl;
        getchar();
        getchar();
        cout << "Agenda : ~$" << endl;
}
void AgendaUI::printMeetings(list<Meeting> meetings) {
        cout << setfill(' ');
	cout << setw(10) << left << "title" << setw(10) <<left << "sponsor" << setw(15) << left << "participator" << setw(20) << left << "start time" << setw(0) << left << "end time\n";
    list<Meeting>::iterator lit;
    for(lit = meetings.begin(); lit != meetings.end(); ++lit) {
		cout << setw(10) << left << lit->getTitle() << setw(10) << left << lit->getSponsor();
		cout << setw(15) << left << lit->getParticipator();
		cout << setw(20) << left << Date::dateToString(lit->getStartDate());
		cout << setw(0)  << left << Date::dateToString(lit->getEndDate()) << endl;
	}
}
void AgendaUI::quitAgenda() {
	agendaService_.~AgendaService();
}	
		
