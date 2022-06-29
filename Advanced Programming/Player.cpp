#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "Player.h"
#include "Item.h"

Item _item;

using namespace std;
const int numOpt = 10;
string newOrder;
string newOrder1;
string newOrder2;

const char* options[numOpt]
= { "North", "South", "West", "East", "Examine", "Get", "Inventory", "Drop", "Combine", "Exit"};

char ord[3];
char ord1[5];
char ord2[7];

int Player::Orders(string order, int num) {
	//For GettingItems
	for (int j = 0; j < order.length() && j < 3; j++) {
			ord[j] = order.at(j);				
	}
	newOrder = ord;

	if (newOrder == options[5]) {
		if (_item.GetItem(order, num) == true) {
			return false;
		}
	}
	else {
		//For DropingItems
		for (int j = 0; j < order.length() && j < 4; j++) {
			ord1[j] = order.at(j);
		}
		newOrder1 = ord1;

		if (newOrder1 == options[7]) {
			if (_item.DropItem(order, num) == true) {
				return false;
			}
		}
		else {
			//For CombiningItems
			for (int j = 0; j < order.length() && j < 7; j++) {
				ord2[j] = order.at(j);
			}
			newOrder2 = ord2;
			if (newOrder2 == options[8]) {
				if (_item.CombineItem(order, num) == true) {
					return false;
				}
			}
		}
	}

	//For the rest
	for (int i = 0; i < numOpt; i++) {		
		if (order == options[i]) {
			if (i == 6) { //For Inventory
				_item.Inventory();
				return false;
			}
			return (i+1);
		}
	}
	
	cout << "The order doesn't exist or at least not for this room\n";
	return false; 
}