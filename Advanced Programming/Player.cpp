#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "Player.h"
#include "Item.h"

Item _item;

using namespace std;
const int numOpt = 7;
string newOrder;

const char* options[numOpt]
= { "North", "South", "West", "East", "Examine", "Get", "Inventory"};

char ord[4];

int Player::Orders(string order, int num) {
	for (int j = 0; j < order.length() && j < 3; j++) {
			ord[j] = order.at(j);				
	}
	newOrder = ord;

	if (newOrder == options[5]) {
		if (_item.GetItem(order, num) == true) {
			return false;
		}
	}
	for (int i = 0; i < numOpt; i++) {		
		if (order == options[i]) {
			if (i == 6) {
				_item.Inventory();
				return false;
			}
			return (i+1);
		}
	}
	
	cout << "The order doesn't exist or at least not for this room\n";
	return false; 
}