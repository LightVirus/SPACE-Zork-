#pragma once
#include <string>
#include <vector>
#include "items.h"
#include "place.h"
using namespace std;

class items;

class player
{
	
public:
	player();
	~player();
	place *whereami;
	vector<items> inv;
	float hp;
	void AddItemToInv(items &itemadd);
	void RemoveFromInv(items &itemrem);

	


};

