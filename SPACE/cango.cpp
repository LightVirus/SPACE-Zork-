#include "stdafx.h"
#include "cango.h"
#include "place.h"
#include <string>
#include <vector>
using namespace std;

cango::cango()
{
}


cango::~cango()
{
}

void cango::SetCango(place *placeto, bool haseve, events *eventof)
{
	placetogo = placeto;
	hasevent = haseve;
	eventofcango = eventof;
}
void cango::SetCango(place *placeto, bool haseve)
{
	placetogo = placeto;
	hasevent = haseve;
}