#include "stdafx.h"
#include "place.h"
#include "game.h"
#include "items.h"
#include "player.h"
#include "cango.h"
#include <string>
#include <vector>
using namespace std;
place::place()
{
	

}


place::~place()
{
}

void place::AddItemToPlace(items &itemadd)
{
	zoneitems.push_back(itemadd);
	itemadd.desc = "thrown on the floor";
}


void place::AddItemToPlace(items &itemadd, string descofitem)
{
	itemadd.placedesc = descofitem;
	zoneitems.push_back(itemadd);
	
}

/*bool place::FindItemHere(string itemname)
{
	bool end = false;
	for (int i = 0; i < zoneitems.size(); i++)
	{
		if (zoneitems[i].name == itemname)
		{
			end = true;
		}
	}
	return end;
}

items & place::FindItemHereAndReturn(string itemname)
{
	for (int i = 0; i < zoneitems.size(); i++)
	{
		if (zoneitems[i].name == itemname)
		{
			items &itemausar = zoneitems[i];
			return itemausar;
		}
	}
}*/

void place::RemoveFromZone(items &itemrem)
{
	for (int i = 0; i < zoneitems.size(); i++)
	{
		if (itemrem.name == zoneitems[i].name)
		{
			zoneitems.erase(zoneitems.begin() + i);
		}
	}
}

void place::FindItems const()
{
	for (int i = 0; i < zoneitems.size(); i++)
	{
		cout << zoneitems[i].name << " -- " << zoneitems[i].desc << " -- " << zoneitems[i].placedesc << endl;
	}
}

void place::SetAtt(string n, string d)
{
	name = n;
	desc = d;
}

void place::AddCangoToPlace(cango &whereican)
{
	goin.push_back(whereican);
}
