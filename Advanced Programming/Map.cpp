#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "Map.h"
#include "Player.h"

using namespace std;

Player _player;
int starting = 0;
int numRoom;

void Map::Cave() {
    string commandMove;
    numRoom = 1;
    
    
    cout << "**********************************************************************************\n";
    cout << "*                    /   \\              /'\\       _                              *\n";
    cout << "*\\_..           /'.,/     \\_         .,'   \\     / \\_                            *\n";
    cout << "*    \\         /            \\      _/       \\_  /    \\     _                     *\n";
    cout << "*     \\__,.   /              \\    /           \\/.,   _|  _/ \\                    *\n";
    cout << "*          \\_/                \\  /',.,''\\      \\_ \\_/  \\/    \\                   *\n";
    cout << "*                           _  \\/   /    ',../',.\\    _/      \\                  *\n";
    cout << "*             /           _/m\\  \\  /    |         \\  /.,/'\\   _\\                 *\n";
    cout << "*           _/           /MMmm\\  \\_     |          \\/      \\_/  \\                *\n";
    cout << "*          /      \\     |MMMMmm|   \\__   \          \\_       \\   \\_               *\n";
    cout << "*                  \\   /MMMMMMm|      \\   \           \\       \\    \\              *\n";
    cout << "*                   \\  |MMMMMMmm\\      \\___            \\_      \\_   \\            *\n";
    cout << "*                    \\|MMMMMMMMmm|____.'  /\\_            \\       \\   \\_          *\n";
    cout << "*                    /'.,___________...,,'   \\            \\   \\        \\         *\n";
    cout << "*                   /       \\          |      \\    |__     \\   \\_       \\        *\n";
    cout << "*                 _/        |           \\      \\_     \\     \\    \\       \\_      *\n";
    cout << "*                /                               \\     \\     \\_   \\        \\     *\n";
    cout << "*                                                 \\     \\      \\   \\__      \\    *\n";
    cout << "*                                                  \\     \\_     \\     \\      \\   *\n";
    cout << "*      The Cave                                     |      \\     \\     \\      \\  *\n";
    cout << "*                                                    \\ms          |            \\ *\n";
    cout << "**********************************************************************************\n";
    
    if (starting == 0) {
        cout << "You find yourself in a cave, up the mountains of Moria. You don't remember how you made it there, but you surely want to get back home.\n";
        cout << "So i guess it's the time for exploring and finding a way out.\n";
        starting++;
    }

    cin >> commandMove;
    
    while (!_player.Orders(commandMove)) {
        cin >> commandMove;
    }
    if (_player.Orders(commandMove) == 1) {
        cout << "You go North\n";
        DeepCave();
    }
    else if (_player.Orders(commandMove) == 2) {
        cout << "There's an exit, but you will need a rope\n";
        Cave();
    }
    else if (_player.Orders(commandMove) == 5) {
        cout << "There's no items in here\n";
        cout << "There's a path to North\n";
        cout << "There's an exit to South\n";
        Cave();
    }
    else {
        cout << "There's no path " + commandMove + "\n";
        Cave();
    }
}

void Map::DeepCave() {
    string commandMove;
    numRoom = 2;
    
    
    cout << "**********************************************************************************\n";
    cout << "*m\\                /\\       /\\                        /\\     /\\            /mmmmm*\n";
    cout << "*mm\\              /mm\\     /mm\\                      /mm\\   /mm\\          /mmmmmm*\n";
    cout << "*mmm\\            /mmmm\\   /mmmm\\                    /mmmm\\ /mmmm\\        /mmmmmmm*\n";
    cout << "*mmmm\\          /mmmmmm\\ /mmmmmm\\                  /mmmmmmm*mmmmmm\\      /mmmmmmm*\n";
    cout << "*mmmmm\\        /mmmmmmmmm*mmmmmmmm\\                /mmmmmmmmmmmmmmmm\\    /mmmmmmm*\n";
    cout << "*mmmmmm\\      /mmmmmmmmmmmmmmmmmmmm\\              /mmmmmmmmmmmmmmmmmm\\  /mmmmmmmm*\n";
    cout << "*mmmmmmm\\    /mmmmmmmmmmmmmmmmmmmmmm\\            /mmmmmmmmmmmmmmmmmmmm\\/mmmmmmmmm*\n";
    cout << "*mmmmmmmm\\  /mmmmmmmmmmmmmmmmmmmmmmmm\\          /mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm*\n";
    cout << "*mmmmmmmmm\\/mmmmmmmmmmmmmmmmmmmmmmmmmm\\        /mmmmmmmmmmmm/\\mmmmmmmmmmmmmmmmmmm*\n";
    cout << "*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\\      /mmmmmmmmmmmm/  \\mmmmmmmmmmmmmmmmm*\n";
    cout << "*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\\    /mmmmmmmmmmmm/    \\mmmmmmmmmmmmmmmm*\n";
    cout << "*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\\  /mmmmmmmmmmmm/      \\mmmmmmmmmmmmmmm*\n";
    cout << "*mmmmmmmmmmm/\\mmmmmmmmmmmmmmmmmmmmmmmmmmmm\\/mmmmmmmmmmmm/        \\mmmmmmmmmmmmmmm*\n";
    cout << "*mmmmmmmmmm/  \\mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm/          \\mmmmmmmmmmmmm*\n";
    cout << "*mmmmmmmmm/    \\mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm/            \\mmmmmmmmmmmm*\n";
    cout << "*mmmmmmmm/      \\mmmmmmmmmmmmmmmmm/\\mmmmmmmmmmmmmmmmm/              \\mmmmmmmmmmmm*\n";
    cout << "*mmmmmmm/        \\mmmmmmmmmmmmmmm/  \\mmmmmmmmmmmmmmm/                \\mmmmmmmmmmm*\n";
    cout << "*mmmmmm/          \\mmmmmmmmmmmmm/    \\mmmmmmmmmmmmm/                  \\mmmmmmmmmm*\n";
    cout << "*mmmmm/            \\mmmmmmmmmmm/      \\mmmmmmmmmmm/                    \\mmmmmmmmm*\n";
    cout << "*mmmm/   Deep Cave  \\mmmmmmmmm/        \\mmmmmmmmm/                      \\mmmmmmmm*\n";
    cout << "*mmm/                \\mmmmmmm/          \\mmmmmmm/                        \\mmmmmmm*\n";
    cout << "**********************************************************************************\n";
    
    if (starting == 1) {
        cout << "You find yourself deeper in the cave, up the mountains of Moria.\n";
        starting++;
    }

    cin >> commandMove;
    
    while (!_player.Orders(commandMove)) {
        cin >> commandMove;
    }
    if (_player.Orders(commandMove) == 2) {
        cout << "You go South\n";
        Cave();
    }
    else if (_player.Orders(commandMove) == 4) {
        cout << "You go East\n";
        DeepCave();
    }
    else if (_player.Orders(commandMove) == 5) {
        cout << "There's a Lighter\n";
        cout << "There's a path to South\n";
        cout << "There's a path to East\n";
        DeepCave();
    }
    else {
        cout << "There's no path " + commandMove + "\n";
        DeepCave();
    }
}

