#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "Map.h"
#include "Item.h"

using namespace std;

Map _map;

int main() {
    string commandName;

    while (commandName != "Exit") {

        printf("******************************\n****  UPC TEXT ADVENTURE  ****\n");
        cout << "******************************\n";
        cout << "******************************\n";
        cout << "******************************\n";
        cout << "****  1-  Start           ****\n";
        cout << "****  2-  Controls        ****\n";
        cout << "****  3-  Exit            ****\n";
        cout << "******************************\n";
        cout << "******************************\n\n";
        printf("What do you want to do? \n");

        cin >> commandName;

        while (commandName != "Start" && commandName != "Controls" && commandName != "Exit") {
            cout << "Sorry, can't understand you\n";
            cin >> commandName;
        }
        if (commandName == "Start") {
            Item* Ligther = new Item("Ligther", "Looks like you could use it once.");
            Item* Sword = new Item("Sword", "Looks like you can kill with it.");
            _map.Cave();
        }
        else if (commandName == "Controls") {
            cout << "******************************\n";
            cout << "******************************\n";
            cout << "****  Moving Options:     ****\n";
            cout << "****    -  North          ****\n";
            cout << "****    -  South          ****\n";
            cout << "****    -  West          ****\n";
            cout << "****    -  East          ****\n";
            cout << "******************************\n";
            cout << "******************************\n\n";
        }
        
    }
    return 0;
}

