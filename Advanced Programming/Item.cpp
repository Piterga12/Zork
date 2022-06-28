#include <iostream>
#include <cstdlib>
#include "Map.h"
#include "Player.h"
#include "item.h"

Item::Item(const char* title, const char* description, ItemType item_type): name(title), item_type(item_type)
{
	min_value = max_value = 0;
}

Item::~Item()
{}

int Item::GetValue() const
{
	return rand() % (max_value - min_value +1) + min_value;
}

void Item::GetItem(string order) {

	cout << "\n yep";
	for(list<Item*>::const_iterator it = container.begin(); it != container.end() ; ++it)
	{
		cout << "in for";
		Item* item = (Item*)*it;
		cout << "\nThere is an item here: " << item->name;
	}
}