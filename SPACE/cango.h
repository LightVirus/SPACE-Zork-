#pragma once
#include "place.h"
#include "events.h"
#include <string>
#include <vector>

using namespace std;

class place;
class events;

class cango
{
public:
	cango();
	~cango();

	place *placetogo;
	bool hasevent;
	events *eventofcango;

	void SetCango(place *placeto, bool haseve, events *eventof);
	void SetCango(place *placeto, bool haseve);




};

