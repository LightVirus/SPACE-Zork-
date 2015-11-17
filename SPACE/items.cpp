#include "stdafx.h"
#include "items.h"
#include "place.h"
#include "game.h"
#include "player.h"
#include <string>
#include <vector>
using namespace std;

items::items()
{
	
}


items::~items()
{

}

void items::PutItemOnItem(items &itemtoput)
{
	contitems.push_back(itemtoput);
}

void items::SetAtt(string n, string d, bool cont, bool canbs, string obju)
{
	name = n;
	desc = d;
	container = cont;
	objusestr = obju;
	canbestored = canbs;
}
