age:Date.o User.o Meeting.o Storage.o AgendaService.o AgendaUI.o Agenda.cpp
	g++ -std=c++11 -o agenda Agenda.cpp Date.o User.o Meeting.o Storage.o AgendaService.o AgendaUI.o
AgendaUI.o:AgendaUI.cpp AgendaUI.h
	g++ -std=c++11 -c AgendaUI.cpp
AgendaService.o:AgendaService.cpp AgendaService.h
	g++ -std=c++11 -c AgendaService.cpp
Storage.o:Storage.h Storage.cpp
	g++ -std=c++11 -c Storage.cpp
User.o:User.h User.cpp
	g++ -c User.cpp
Meeting.o: Meeting.h Meeting.cpp
	g++ -c Meeting.cpp
Date.o: Date.h Date.cpp
	g++ -c Date.cpp
clean:
	rm *.o
