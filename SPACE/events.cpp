#include "stdafx.h"
#include "events.h"
#include "cango.h"
#include "items.h"
#include "place.h"
#include <string>
#include <vector>
using namespace std;


events::events()
{
}


events::~events()
{
}


void events::setevent(int id, string eventitem, bool endevent, string descevent, string desccompevent)
{
	eventid = id;
	itemevent = eventitem;
	eventend = endevent;
	eventdesc = descevent;
	eventdesccomp = desccompevent;
}