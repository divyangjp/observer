/**
* File Name 	: 005_observ_client.cpp
* Functionality : Check header for details

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

#include "005_observ_client.h"

using namespace std;

#ifndef DEBUG
#define DEBUG 0
#endif
#define PRINT_DEBUG(def_var) if(DEBUG) cout << def_var << endl;


void Client::Update(ServerEvents* app, const int& EvtType)
{
	switch(EvtType)
	{
	case APP_EVENT_TYPE :
	{
		cout << "Event consumed by observer client machine IP = " << m_clientIP << endl;
		cout << "Application version updated..." << endl;
		cout << "Application Name = " << app->GetAppName() << endl;
		cout << "New version number = " << app->GetAppVersion() << endl << endl;

		break;
	}

	case SYS_EVENT_TYPE:
	{
		cout << "Event consumed by observer client machine IP = " << m_clientIP << endl;
		cout << "System stats updated..." << endl;
		cout << "Disk space = " << app->GetDiskSpace() << endl;
		cout << "Memory usage = " << app->GetMemoryUsage() << endl;
		cout << "Temperature = " << app->GetTemperature() << endl << endl;

		break;
	}

	default:
	{
		cout << "Event type not known... duh!!" << endl << endl;
	}
	}
}
