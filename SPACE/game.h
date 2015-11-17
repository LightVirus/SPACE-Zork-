#include "place.h"
#include "player.h"
#include "items.h"
#include "cango.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class player;
class place;
class items;

class game
{
	// Player
	player MyPlayer;

	//Rooms
	place Engi;
	place Crew;
	place Combat;
	place Capi;
	place Mec;
	place Hangar;
	place Bridge;

	//CanGo
	cango EngiCrew;
	cango EngiMec;
	cango CrewEngi;
	cango CrewCombat;
	cango MecEngi;
	cango MecCombat;
	cango CombatCapi;
	cango CombatHangar;
	cango CombatBridge;
	cango CapiCombat;
	cango HangarCombat;
	cango BridgeCombat;


	//Items
	items ACode;
	items ECell;
	items PCutter;
	items Card;

	//Events
	events Energy;
	events UsePCuter;
	events OpenHangar;

	void GO();
	void TAKE();
	void LOOK() const;
	void HELP() const;
	void INV() const;
	void USE();
	void PUTINSIDE();


	void onenergy(items &codecard);
	void hangaropen(items &hangarcard);
	void PCutterUse(items &pcutter);

public:
	game();
	~game();
	
	void imprimir(bool &ft);
	bool OrderIn(string order);

	
};
