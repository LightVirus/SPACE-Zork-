#include "stdafx.h"
#include "player.h"
#include "place.h"
#include "game.h"
#include "items.h"
#include <string>
#include <vector>
using namespace std;

player::player()
{

	
}


player::~player()
{
}

void player::AddItemToInv(items &itemadd)
{
	inv.push_back(itemadd);
	itemadd.placedesc = "in your inventory";
}

void player::RemoveFromInv(items &itemrem)
{
	for (int i = 0; i < inv.size(); i++)
	{
		if (itemrem.name == inv[i].name)
		{
			inv.erase(inv.begin() + i);
		}
	}
}
