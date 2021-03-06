#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "Map.h"
#include "Item.h"
#include "Player.h"

using namespace std;

Item _item_;
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
    
    while (!_player.Orders(commandMove, numRoom)) {
        cin >> commandMove;
    }
    if (_player.Orders(commandMove, numRoom) == 1) {
        cout << "You go North\n";
        DeepCave();
    }
    else if (_player.Orders(commandMove, numRoom) == 2) {
        if (_item_.WinItem()) {
            cout << "***************************************************\n";
            cout << "*_____.___.               __      __              *\n";
            cout << "*\\__  |   | ____  __ __  /  \\    /  \\____   ____  *\n";
            cout << "* /   |   |/  _ \\|  |  \\ \\   \\/\\/   /  _ \\ /    \\ *\n";
            cout << "* \\____   (  <_> )  |  /  \\        (  <_> )   |  \\*\n";
            cout << "* / ______|\\____/|____/    \\__/\\  / \\____/|___|  /*\n";
            cout << "* \\/                            \\/             \\/ *\n";
            cout << "***************************************************\n\n";
            cout << "You made it! You made your way out of the Mountains of Moria!\n\n";
            return;
        }
        cout << "There's an exit, but you will need a rope with a hook in one side or something similar\n";
        Cave();
    }
    else if (_player.Orders(commandMove, numRoom) == 5) {
        _item_.ItemsRoom(numRoom);
        cout << "There's a path to North\n";
        cout << "There's an exit to South\n";
        Cave();
    }
    else if (_player.Orders(commandMove, numRoom) == 10) {
        return;
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
    
    while (!_player.Orders(commandMove, numRoom)) {
        cin >> commandMove;
    }
    if (_player.Orders(commandMove, numRoom) == 2) {
        cout << "You go South\n";
        Cave();
    }
    else if (_player.Orders(commandMove, numRoom) == 4) {
        cout << "You go East\n";
        DarknessCave();
    }
    else if (_player.Orders(commandMove, numRoom) == 5) {
        _item_.ItemsRoom(numRoom);
        cout << "There's a path to South\n";
        cout << "There's a path to East\n";
        DeepCave();
    }
    else if (_player.Orders(commandMove, numRoom) == 10) {
        return;
    }
    else {
        cout << "There's no path " + commandMove + "\n";
        DeepCave();
    }
}

void Map::DarknessCave() {
    string commandMove;
    numRoom = 3;
    
    
    cout << "**********************************************************************************\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMM   Darkness Cave   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*\n";
    cout << "**********************************************************************************\n";
    
    if (starting == 2) {
        if (!_item_.LightRoom()) {
            cout << "You can't see where you are.\n Looks like you could you a light.\n";
        }
        else {
            cout << "You can see thanks to the Torch.\n";
        }
        starting++;
    }

    cin >> commandMove;
    
    while (!_player.Orders(commandMove, numRoom)) {
        cin >> commandMove;
    }
    if (_player.Orders(commandMove, numRoom) == 1) {
        cout << "You go North\n";
        ElvenForest();
    }
    else if (_player.Orders(commandMove, numRoom) == 3) {
        cout << "You go West\n";
        DeepCave();
    }
    else if (_player.Orders(commandMove, numRoom) == 5) {
        if (_item_.LightRoom()) {
            _item_.ItemsRoom(numRoom);
            cout << "There's a path to North\n";
            cout << "There's a path to West\n";
        }
        else {
            cout << "You can't see anything else, maybe you can light it up\n";
        }

        DarknessCave();
    }
    else if (_player.Orders(commandMove, numRoom) == 10) {
        return;
    }
    else {
        cout << "There's no path " + commandMove + "\n";
        DarknessCave();
    }
}

void Map::ElvenForest() {
    string commandMove;
    numRoom = 4;
    
    
    cout << "**********************************************************************************\n";
    cout << "* ....@@ ..... @ .... @ .............   ....... .....; .... *** .....*\n";
    cout << "* .....\@\....@ .... @ ............................. #  .. *****  ...*\n";
    cout << "*  @@@.. @@@@@  @@@@@@___.. ....... ...%..... ...  {###}  *******    *\n";
    cout << "* ....@-@..@ ..@......@@@\...... %...... ....... <## ####>********   *\n";
    cout << "*   @@@@\...@ @ ........\@@@@ ..... ...... ....... {###}***********  *\n";
    cout << "* ....%..@  @@ /@@@@@ . ....... ...............<###########> ******* *\n";
    cout << "* ...... .@-@@@@ ...V......     .... %.......... {#######}******* ****\n";
    cout << "* ...... .  @@ .. ..v.. .. . { } ............<###############>********\n";
    cout << "* ......... @@ .... ........ {^^,     .......   {## ######}***** *****\n";
    cout << "* ..%..... @@ .. .%.... . .. (   `-;   ... <###################> *****\n";
    cout << "* . .... . @@ . .... .. _  .. `;;~~ ......... {#############}*********\n";
    cout << "* .... ... @@ ... ..   /(______); .. ....<################  #####>****\n";
    cout << "* . .... ..@@@ ...... (         (  .........{##################}******\n";
    cout << "* ......... @@@  ....  |:------( )  .. <##########################>***\n";
    cout << "*  @@@@ ....@@@  ... _// ...... \\ ...... {###   ##############}******\n";
    cout << "* @@@@@@@  @@@@@ .. / /@@@@@@@@@ vv  <##############################>*\n";
    cout << "* @@@@@@@ @@@@@@@ @@@@@@@@@@@@@@@@@@@ ..... @@@@@@  @@@@@@@  @@@@    *\n";
    cout << "* @@@@@@###@@@@@### @@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@ *\n";
    cout << "* @@@@@@@@###@##@@ @@@@@@@@@@@@@@@@@@@@@ @@@@@   @@@@@@@@@@@@@@@@@@@ *\n";
    cout << "* @@@@@ Elven Forest @@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@ *\n";
    cout << "* -@@@@@@@@@#####@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*\n";
    cout << "**********************************************************************************\n";
    
    if (starting == 3) {
        cout << "Somehow you find yourself in an elven forest\n";
        starting++;
    }

    cin >> commandMove;
    
    while (!_player.Orders(commandMove, numRoom)) {
        cin >> commandMove;
    }
    if (_player.Orders(commandMove, numRoom) == 2) {
        cout << "You go South\n";
        DarknessCave();
    }
    else if (_player.Orders(commandMove, numRoom) == 5) {
        _item_.ItemsRoom(numRoom);
        cout << "There's a path to South\n";
        ElvenForest();
    }
    else if (_player.Orders(commandMove, numRoom) == 10) {
        return;
    }
    else {
        cout << "There's no path " + commandMove + "\n";
        ElvenForest();
    }
}

