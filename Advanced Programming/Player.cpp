#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "Player.h"
#include "Item.h"

Item _item;

using namespace std;
const int numOpt = 6;

const char* options[numOpt]
= { "North", "South", "West", "East", "Examine", "Get"};

char ord[2];

int Player::Orders(string order) {
	for (int j = 0; j < 3; j++) {
			ord[j] = order.at(j);			
		}
	cout << ord << "=" << options[5];
	_item.GetItem(order);
	if (ord == options[5]) {
		cout << "Trying";
		
	}
	for (int i = 0; i < numOpt; i++) {		
		if (order == options[i]) {
			return (i+1);
		}
	}
	
	cout << "The order doesn't exist\n";
	return false; 
}