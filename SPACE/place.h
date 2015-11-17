#pragma once
#include <string>
#include <vector>
#include "items.h"
#include "cango.h"
using namespace std;

class items;
class cango;

class place
{

public:
	place();
	~place();
	
	
	vector<items> zoneitems;
	vector<cango> goin;
	string name;
	string desc;

	
	
	
	void AddItemToPlace (items &itemadd);
	void AddItemToPlace (items &itemadd, string descofitem);
	void AddCangoToPlace(cango &whereican);
	//bool FindItemHere(string itemname);
	//items & FindItemHereAndReturn(string itemname);
	void RemoveFromZone(items &itemrem);
	void FindItems() const;

	void SetAtt(string n, string d);
};

