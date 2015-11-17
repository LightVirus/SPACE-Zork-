#include "stdafx.h"
#include "game.h"
#include "place.h"
#include "items.h"
#include "player.h"
#include "cango.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

game::game()
{
	MyPlayer.whereami = &Mec;
	
	// Rooms

	Engi.SetAtt("Engineering", "A room with many cables on the floor and little space to walk. You struck by the great hyperspace engine which is held in the center of the room.");
	Crew.SetAtt("Crew's Quarters", "Here it seems that is where the crew slept. You see a lot of things scattered on the floor, it seems they left hastily...");
	Combat.SetAtt("Combat Center", "It seems the central part of the ship, you can see many corpses and remains of the crew");
	Capi.SetAtt("Captain's Cabin", "You can see the body of the commander of the ship, it seems that he was trying to send an SOS when they killed him.");
	Mec.SetAtt("Medical Center", "This is where the wounded healed, the room is much better than the rest of the ship, it seems they didn't enter this room");
	Hangar.SetAtt("Hangar", "You can see the captain personal ship, it seems intact and ready to use. Type usespaceship to escape");
	Bridge.SetAtt("Bridge of the ship", "The bridge looks pretty damaged. Under the pilot's body, you can see a console that still works");



	// Items
	ACode.SetAtt("Engine Start code", "A paper with a very long codes, appear to be for the ship engine", false, false, "Energy");
	ECell.SetAtt("Energy Cell", "A charged energy cell ,could be used to turn on machine or tool.", false, true, "Edoor");
	PCutter.SetAtt("Plasma Cutter", "Tool used by engieners for cutting strong materials", true, false, "Edoor");
	Card.SetAtt("Captain's acces card", "A acces card of max security level, could be usefull", false, false, "hangar");


	//Cango
	EngiCrew.SetCango(&Crew, false);
	EngiMec.SetCango(&Mec, false);
	CrewEngi.SetCango(&Engi, false);
	CrewCombat.SetCango(&Combat, true, &Energy);
	MecEngi.SetCango(&Engi, false);
	MecCombat.SetCango(&Combat, true, &Energy);
	CombatCapi.SetCango(&Capi, true, &UsePCuter);
	CombatHangar.SetCango(&Hangar, true, &OpenHangar);
	CombatBridge.SetCango(&Bridge, false);
	CapiCombat.SetCango(&Combat, false);
	HangarCombat.SetCango(&Combat, false);
	BridgeCombat.SetCango(&Combat, false);

	

	//Events
	Energy.setevent(1, "Energy", false, "The ship has no energy, and you cant open the door manually", "The engine started working!, you hear how a door opens in the distance");
	UsePCuter.setevent(2, "Edoor", false, "The corridor is blocked by debris, you must find a way to cut them", "You manage to cut enough to pass, but the Plasma Cutter runs out of energy");
	OpenHangar.setevent(3, "hangar", false, "The hangar door is sealed, it appears some kind of security lock, maybe with autorization you could deactivate in somewhere", "--Security lock disabled--");
	
	// Set Items on places
	Engi.AddItemToPlace(PCutter, "next to the hyperspace engine");
	Crew.AddItemToPlace(ACode, "on the bed, next to a dead engieneer");
	Combat.AddItemToPlace(ECell, "on the comander desk");
	Capi.AddItemToPlace(Card, "Inside a pocket of captain shirt");


	//Set Cango to placer
	Engi.AddCangoToPlace(EngiCrew);
	Engi.AddCangoToPlace(EngiMec);
	Crew.AddCangoToPlace(CrewEngi);
	Crew.AddCangoToPlace(CrewCombat);
	Mec.AddCangoToPlace(MecEngi);
	Mec.AddCangoToPlace(MecCombat);
	Combat.AddCangoToPlace(CombatCapi);
	Combat.AddCangoToPlace(CombatHangar);
	Combat.AddCangoToPlace(CombatBridge);
	Capi.AddCangoToPlace(CapiCombat);
	Hangar.AddCangoToPlace(HangarCombat);
	Bridge.AddCangoToPlace(BridgeCombat);

	
	
}


game::~game()
{
}


void game::imprimir(bool &ft)
{
	if (ft)
	{
		cout << "-- Welcome to SPACE! Text based RPG by Unai Lujambio Jimenez --" << endl;
		cout << "--              Type help to learn how to play               --" << endl;
		
		cout << endl;
		cout << "  -You just wake up in the medical center of one starship-" << endl;
		cout << endl;
		cout << "  -The last thing you remmember is you beeing sent to a starship for repearing the main engine-" << endl;
		cout << endl;
		cout << "  -You can see lot of blood in the next room..." << endl;
		cout << "  you dont know what hapenned here, but better run away now, before is to late..-" << endl;
		system("pause");
		ft = false;
	}
	system("cls");
	cout << "-- Welcome to SPACE! Text based RPG by Unai Lujambio Jimenez --" << endl;
	cout << "--              Type HELP to learn how to play               --" << endl;
	
	cout << endl;
	cout << endl;
	cout << "Current Room: " << MyPlayer.whereami->name << endl;
	cout << endl;
	cout << MyPlayer.whereami->desc << endl;
	cout << endl;
}



bool game::OrderIn(string order) // Order In
{
	bool end = false;
	if (order != "")
	{
		if (order == "go") 
		{
			GO();
		}
		else if (order == "take") 
		{
			TAKE();
		}
		else if (order == "putinside")
		{
			PUTINSIDE();
		}
		else if (order == "inv")
		{
			INV();
		}
		else if (order == "drop")
		{
			DROP();
		}
		else if (order == "use")
		{
			USE();
		}
		else if (order == "look")
		{
			LOOK();
		}
		else if (order == "help")
		{
			HELP();
		}
		else if (order == "exit")
		{
			end = true;
		}
		else if (order == "usespaceship")
		{
			if (MyPlayer.whereami->name == "Hangar")
			{
				cout << "You escaped from the spaceship succesfully!" << endl << endl;
				cout << "YOU FINISHED THE GAME!!!" << endl;
				end = true;
			}
		}
		else
		{
			cout << "I do not understand that :(" << endl;
		}
	}
	cout << endl;
	system("pause");
	return end;
}


void game::GO() // Go COMAND
{
	cout << "Where want you to go? Write the number!" << endl;
	int max = 0;
	for (int i = 0; i < MyPlayer.whereami->goin.size(); i++)
	{
		cout << "      - [" << i << "] - " << MyPlayer.whereami->goin[i].placetogo->name << endl;
		max = i;
	}
	int temp = -1;
	cin >> temp;
	if (temp >= 0 && temp <= max)
	{
		if (MyPlayer.whereami->goin[temp].hasevent)
		{
			if (MyPlayer.whereami->goin[temp].eventofcango->eventend)
			{
				place *destino = MyPlayer.whereami->goin[temp].placetogo;
				MyPlayer.whereami = destino;
				cout << "You successfully enter in the " << MyPlayer.whereami->name << " room!" << endl;
			}
			else
			{
				cout << "You cant go there, " << MyPlayer.whereami->goin[temp].eventofcango->eventdesc << endl;
			}
		}
		else
		{
			place *destino = MyPlayer.whereami->goin[temp].placetogo;
			MyPlayer.whereami = destino;
			cout << "You successfully enter in the " << MyPlayer.whereami->name << " room!" << endl;
		}
	}
	else
	{
		cout << "You enter a wrong number" << endl;
	}
}

void game::TAKE() // Take COMAND
{
	if (MyPlayer.whereami->zoneitems.size() != 0)
	{

		cout << "What do you want to take?" << endl;
		int max = 0;
		for (int i = 0; i < MyPlayer.whereami->zoneitems.size(); i++)
		{
			cout << "      - [" << i << "] - " << MyPlayer.whereami->zoneitems[i].name << endl;
			max = i;
		}
		int temp = -1;
		cin >> temp;
		if (temp >= 0 && temp <= max)
		{
			items itemtomod = MyPlayer.whereami->zoneitems[temp];
			MyPlayer.AddItemToInv(itemtomod);
			MyPlayer.whereami->RemoveFromZone(itemtomod);
			cout << "You take the " << itemtomod.name << "!, you have stored it in your bag" << endl;
			itemtomod.~items();
		}
		else
		{
			cout << "You enter a wrong number" << endl;
		}
	}
	else
	{
		cout << "There's nothing to take here, use look comand for searching the room" << endl;
	}
}

void game::LOOK() const // Look Comand
{
	if (MyPlayer.whereami->zoneitems.size() != 0)
	{
		cout << "You can see this usefull things here:" << endl;
		MyPlayer.whereami->FindItems();
	}
	else
		cout << "You didnt find anything here :(" << endl;
}

void game::HELP() const // Help Comand
{
	cout << "Welcome to SPACE! Just enter a comand to play! Comands list:" << endl;
	cout << "look : Check your environment for items" << endl;
	cout << "go : Go somewhere" << endl;
	cout << "take : Take something" << endl;
	cout << "drop : Drop something" << endl;
	cout << "putinside : Put one item inside another item" << endl;
	cout << "inv : Check items in your inventory" << endl;
	cout << "use : Use a item" << endl << endl;
	cout << "exit : Exit's the program" << endl;
}

void game::INV() const // Inventory Comand
{
	if (MyPlayer.inv.size() > 0)
	{
		cout << "Items in your inventory:" << endl;
		for (int i = 0; i < MyPlayer.inv.size(); i++)
		{
			cout << "      - [" << i << "] - " << MyPlayer.inv[i].name << endl;
		}
	}
	else
	{
		cout << "Your inventory is empty!" << endl;
	}

}

void game::PUTINSIDE()
{
	cout << "What item you want to put somewhere?" << endl;
	int max = 0;
	for (int i = 0; i < MyPlayer.inv.size(); i++)
	{
		cout << "      - [" << i << "] - " << MyPlayer.inv[i].name << endl;
		max = i;
	}
	int temp = -1;
	cin >> temp;
	cout << endl << endl;
	cout << "And in what item you want to put inside?" << endl;
	int max2 = 0;
	for (int i2 = 0; i2 < MyPlayer.inv.size(); i2++)
	{
		cout << "      - [" << i2 << "] - " << MyPlayer.inv[i2].name << endl;
		max2 = i2;
	}
	int temp2 = -1;
	cin >> temp2;
	if (MyPlayer.inv[temp].name != MyPlayer.inv[temp2].name)
	{
		if (MyPlayer.inv[temp].canbestored && MyPlayer.inv[temp2].container)
		{
			string name1, name2;
			name1 = MyPlayer.inv[temp].name;
			name2 = MyPlayer.inv[temp2].name;
			MyPlayer.inv[temp2].PutItemOnItem(MyPlayer.inv[temp]);
			MyPlayer.RemoveFromInv(MyPlayer.inv[temp]);
			cout << "You have succesfuly put the " << name1 << " into the " << name2 << endl;
		}
		else
		{
			cout << "You cant do that :(" << endl;
		}
	}
	else
	{
		cout << "You cant put one item inside itself! :(" << endl;
	}
}

void game::DROP() // Drop Comand
{
	if (MyPlayer.inv.size() > 0)
	{
		cout << "What item you want to drop? Write the number!" << endl;
		int max = 0;
		for (int i = 0; i < MyPlayer.inv.size(); i++)
		{
			cout << "      - [" << i << "] - " << MyPlayer.inv[i].name << endl;
			max = i;
		}
		int temp = -1;
		cin >> temp;
		if (temp >= 0 && temp <= max)
		{
			string name = MyPlayer.inv[temp].name;
			MyPlayer.whereami->AddItemToPlace(MyPlayer.inv[temp]);
			MyPlayer.RemoveFromInv(MyPlayer.inv[temp]);
			cout << "You drop " << name << " on the floor" << endl;
		}
		else
		{
			cout << "You enter a wrong number" << endl;
		}
	}
	else
	{
		cout << "Your inventory is empty!" << endl;
	}
}

void game::USE() // Use Comand
{
	if (MyPlayer.inv.size() > 0)
	{
		cout << "What item you want to use? Write the number!" << endl;
		int max = 0;
		for (int i = 0; i < MyPlayer.inv.size(); i++)
		{
			cout << "      - [" << i << "] - " << MyPlayer.inv[i].name << endl;
			max = i;
		}
		int temp = -1;
		cin >> temp;
		if (temp >= 0 && temp <= max)
		{
			if (MyPlayer.inv[temp].objusestr != "")
			{
				if (MyPlayer.inv[temp].name == "Plasma Cutter" && MyPlayer.whereami->name == "Combat Center")
				{
					PCutterUse(MyPlayer.inv[temp]);
				}
				else if (MyPlayer.inv[temp].name == "Captain's acces card" && MyPlayer.whereami->name == "Bridge of the ship")
				{
					hangaropen(MyPlayer.inv[temp]);
				}
				else if (MyPlayer.inv[temp].name == "Engine Start code" && MyPlayer.whereami->name == "Engineering")
				{
					onenergy(MyPlayer.inv[temp]);
				}
				else
				{
					cout << "I cant use that item here!" << endl;
				}
			}
			else
			{
				cout << "I cant use that item!" << endl;
			}
		}
		else
		{
			cout << "You enter a wrong number" << endl;
		}


	}
	else
	{
		cout << "Your inventory is empty!" << endl;
	}
	
}


void game::PCutterUse(items &pcutter) // Use Plasma Cutter
{
	if (!UsePCuter.eventend)
	{
		bool done = false;
		if (pcutter.contitems.size() > 0)
		{
			for (int i = 0; i < pcutter.contitems.size(); i++)
			{
				if (pcutter.contitems[i].objusestr == "Edoor")
				{
					done = true;
				}
			}
		}
		if (done)
		{
			cout << UsePCuter.eventdesccomp << endl;
			UsePCuter.eventend = true;
		}
		else
		{
			cout << "The Plasma Cutter seems unpowered, maybe he need some batery inside..." << endl;
		}
	}
	else
	{
		cout << "The Plasma Cutter seems unpowered" << endl;
	}
	
}

void game::hangaropen(items &hangarcard) // Open Hangar Door
{
	if(!OpenHangar.eventend)
	{
		cout << OpenHangar.eventdesccomp << endl;
		OpenHangar.eventend = true;
	}
	else
	{
		cout << "The security lock has already been unlocked" << endl;
	}
}

void game::onenergy(items &codecard) // Switch on energy
{
	if(!Energy.eventend)
	{
		cout << Energy.eventdesccomp << endl;
		Energy.eventend = true;
	}
	else
	{
		cout << "The engine is already working" << endl;
	}
}