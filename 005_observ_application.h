/**
* File Name 	: 005_observ_application.h
* Functionality : 

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

#ifndef _005_OBSERV_APPLICATION_H_
#define _005_OBSERV_APPLICATION_H_

// Event types

#define APP_EVENT_TYPE 	111
#define SYS_EVENT_TYPE 	112


#include <iostream>
#include <string>
#include <list>

using namespace std;

class IClient;

// Event framework base class aka ServerEvents 

class ServerEvents
{
	public:
		ServerEvents(string ServerIP):m_ServerIP(ServerIP){}
		ServerEvents(unsigned int eventID):m_EventID(eventID){}

		// Pure virtual dtor will make sure that all derived classes
		// implement the respective dtor. 
		// And yes, pure virtual dtor can have implementation.

		virtual 		~ServerEvents()=0;
		
		unsigned int 	getEventID(){ return m_EventID; }

		void 			Attach(IClient* clt);
		void 			Detach(IClient* clt);

		// We pass EventType for respective subject

		void 			Notify(const int& EventType);

		// These methods are not supposed to be called by ServerEvents object.
		// They are here for just to provide virtual inheritance for derived classes.

		// Methods for AppEvent class
		virtual unsigned int GetAppID(){return 0;}
		virtual string GetAppName(){return 0;}
		virtual string GetAppVersion(){return 0;}

		// Methods for SysEvent class
		virtual int GetDiskSpace(){ return 0; }
		virtual int GetMemoryUsage(){ return 0; }
		virtual int GetTemperature(){ return 0; }

	protected:
		// Protected ctor will make this class abstract.
		// But still accessible by derived class for inheritance.

		ServerEvents(){}

	private:
		unsigned int	m_EventID;
		string 			m_ServerIP;
		list<IClient*> 	m_cltList;
};


// First event type is application event.
// Whenever any application version changes, this event is raised.
// And all the observers of this event will be notified.

class AppEvent : public ServerEvents
{
	public:
		// This ctor will still call default ctor of base class
		// i.e. ServerEvents(). That's why we made ServerEvents() protected...
		// Same applies for all the derived classes.

		AppEvent(const unsigned int eventID,
			const unsigned int appID,
			const string appName,
			const string appVersion)
				: ServerEvents(eventID)
				, m_appID(appID)
			    , m_appName(appName)
			    , m_appVersion(appVersion)
		{
			#ifdef DEBUG
			cout << "New AppEvent with Event ID " << getEventID() << " registered. " << endl;
			#endif 
		}

		~AppEvent();

		unsigned int 	GetAppID();
		string 			GetAppName();
		string 			GetAppVersion();

		void ChangeVersion(string&);
	private:
		unsigned int 	m_appID;
		string			m_appName;
		string			m_appVersion;
		
};

class SysEvent : public ServerEvents
{
	public:
		SysEvent(const unsigned int eventID,
			const int ds,
			const int mu,
			const int tem)
			: ServerEvents(eventID)
			, m_diskSpace(ds)
			, m_memoryUsage(mu)
			, m_temperature(tem)
		{
			#ifdef DEBUG
			cout << "New SysEvent with Event ID " << getEventID() << " registered." << endl;
			#endif 
		}
		~SysEvent();

		int GetDiskSpace();
		int GetMemoryUsage();
		int GetTemperature();

		void ChangeDiskSpace(const int&);
	private:
		int 	m_diskSpace;		// In percentile
		int		m_memoryUsage;		// In Percentile
		int		m_temperature;		// In Celsius
};

#endif	//_005_OBSERV_APPLICATION_H_
