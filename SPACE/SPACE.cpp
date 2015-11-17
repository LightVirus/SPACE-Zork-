// SPACE.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "game.h"
#include "player.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;



int main(int argc, char* argv[])
{
	game MyGame;
	bool ft = true;
	bool gameover = false;

	

	while(!gameover)
	{
		string order = "";
		MyGame.imprimir(ft);
		cout << "-> ";
		cin >> order;
		gameover = MyGame.OrderIn(order);
	}
	return 0;
}

