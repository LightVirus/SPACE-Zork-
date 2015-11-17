#pragma once
#include "items.h"
#include "place.h"
#include "cango.h"
#include <string>
#include <vector>
class events
{
public:
	events();
	~events();

	int eventid;
	string itemevent;
	bool eventend;
	string eventdesc;
	string eventdesccomp;

	void setevent(int id, string eventitem, bool endevent, string descevent, string desccompevent);




};

