/**
* File Name 	: 005_use_observ.cpp
* Functionality : This is demo to use observer pattern established in 
		  server-client model for application version updates.

* Copyright (C) 2012 Divyang Patel

* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "005_observ_application.h"
#include "005_observ_client.h"

using namespace std;

#ifndef DEBUG
#define DEBUG 0
#endif
#define PRINT_DEBUG(def_var) if(DEBUG) cout << def_var << endl;


int main()
{
	AppEvent *app1 = new AppEvent(500, 11, "gdb", "10.1");
	AppEvent *app2 = new AppEvent(501, 12, "valgrind", "1.1.2");

	SysEvent *sysevt = new SysEvent(502, 50, 30, 10);

	Client *clt1 = new Client("127.72.50.51", "Pune-S", "clt1");
	Client *clt2 = new Client("127.72.50.52", "Pune-H", "clt2");
	Client *clt3 = new Client("127.72.50.53", "Pune-H", "clt3");

	app1->Attach(clt1);
	app1->Attach(clt2);

	app2->Attach(clt2);

	app1->Detach(clt2);

	sysevt->Attach(clt3);
	sysevt->Attach(clt2);
	sysevt->Attach(clt1);

	string ver = "11.1";
	app1->ChangeVersion(ver);

	ver = "1.2.1";
	app2->ChangeVersion(ver);

	sysevt->ChangeDiskSpace(26);

	delete app1;
	delete app2; 
	delete clt1; 
	delete clt2;
	delete clt3;
	delete sysevt;

	return 0;
}

