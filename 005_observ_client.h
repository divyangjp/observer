/**
* File Name 	: 005_observ_client.h
* Functionality : This is code for clients (aka observers) who will be
		  notified by server (aks subject) when application version
		  is changed for which particular client is interested.

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

#ifndef _005_OBSERV_CLIENT_H_
#define _005_OBSERV_CLIENT_H_

#include <iostream>

#include "005_observ_application.h"

class IClient
{
	public:
		virtual void 	Update(ServerEvents* app, const int& EvtType)=0;
		virtual string 	getClientIP() = 0;
};


class Client : public IClient
{
	public:
		Client(const string cltIP,
		       const string cltLoc,
		       const string mcName)
		       : m_clientIP(cltIP)
		       , m_clientLocation(cltLoc)
		       , m_machineName(mcName)
		{
			#ifdef DEBUG
			cout << "New observer Client with IP " << cltIP << " registered. " << endl;
			#endif 
		}

		void Update(ServerEvents*, const int&);
		string getClientIP() { return m_clientIP; }

	private:
		string m_clientIP;
		string m_clientLocation;
		string m_machineName;

		Client();
};



#endif	// _005_OBSERV_CLIENT_H_
