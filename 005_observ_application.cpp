/**
* File Name 	: 005_observ_application.cpp
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


#ifndef DEBUG
#define DEBUG 0
#endif
#define PRINT_DEBUG(def_var) if(DEBUG) cout << def_var << endl;

#include "005_observ_application.h"
#include "005_observ_client.h"

using namespace std;

ServerEvents::~ServerEvents()
{
}

void ServerEvents::Attach(IClient* clt)
{
	#ifdef DEBUG
	cout << "Observer client with IP " << clt->getClientIP() << " STARTED observing " << this->getEventID() << endl;
	#endif 
	m_cltList.push_back(clt);
}

// Removing particular client from multimap for particular event types
// is rather tricky and there's no direct function or algorithm available
// so we need our own little algo.

void ServerEvents::Detach(IClient* clt)
{
	#ifdef DEBUG
	cout << "Observer client with IP " << clt->getClientIP() << " STOPPED observing " << this->getEventID() << endl;
	#endif
	m_cltList.remove(clt);
}

void ServerEvents::Notify(const int& EvtType)
{
	list<IClient*>::iterator lc_iter;
	for(lc_iter=m_cltList.begin(); lc_iter!=m_cltList.end(); lc_iter++)
	{
		(*lc_iter)->Update(this, EvtType);
	}
}

// Methods for AppEvent class

void AppEvent::ChangeVersion(string &newVer)
{
	#ifdef DEBUG
	cout << "== AppEvent " << getEventID() << " fired  from ChangeVersion ==" << endl;
	#endif 
	m_appVersion = newVer;
	Notify(APP_EVENT_TYPE);
}


AppEvent::~AppEvent()
{
}

unsigned int AppEvent::GetAppID()
{
	return m_appID;
}

string AppEvent::GetAppName()
{
	return m_appName;
}

string AppEvent::GetAppVersion()
{
	return m_appVersion;
}

// Methods for SysEvent class

SysEvent::~SysEvent()
{
}

int SysEvent::GetDiskSpace()
{
	return m_diskSpace;
}

int SysEvent::GetMemoryUsage()
{
	return m_memoryUsage;
}

int SysEvent::GetTemperature()
{
	return m_temperature;
}

void SysEvent::ChangeDiskSpace(const int& ds)
{
	#ifdef DEBUG
	cout << "== SysEvent " << getEventID() << " fired  from ChangeDiskSpace ==" << endl;
	#endif 
	m_diskSpace = ds;
	Notify(SYS_EVENT_TYPE);
}
