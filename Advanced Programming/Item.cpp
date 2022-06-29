#include <iostream>
#include <cstdlib>
#include "Map.h"
#include "Player.h"
#include "item.h"

const int numObj = 5;

const char* objects[numObj]
= { "Torch", "Lighter", "Hook", "Liana", "HookedLiana"};

Item* Torch = new Item("Torch", "Looks like you'll need a lighter.", ROOM2, COMBINE0);
Item* Lighter = new Item("Lighter", "Looks like you could use it once.", ROOM1, COMBINE0);
Item* Hook = new Item("Hook", "You only need something to attach it to.", ROOM2, COMBINE1);
Item* Liana = new Item("Liana", "You only need something else to use it for leaving the cave.", ROOM2, COMBINE1);
Item* HookedLiana = new Item("HookedLiana", "You can use it to leave the cave", NOTGETABLE, NOTCOMBINABLE);

Item::Item(const char* title, const char* description, ItemState item_type, ItemComb item_comb): name(title), description(description), item_type(item_type), item_comb(item_comb)
{
	min_value = max_value = 0;
}

Item::~Item()
{}

int Item::GetValue() const
{
	return rand() % (max_value - min_value +1) + min_value;
}

bool Item::GetItem(string order, int num) {

	for (int i = 0; i < numObj; i++) {
		string objName = objects[i];
		string objName2 = "Get" + objName;
		if (order ==objName2) {

			if (Torch->name == objects[i]) {
				if (Torch->item_type == num) {
					cout << "You got: " << objects[i] << "\n";
					Torch->item_type = PLAYER;
					return true;
				}
				else if(Torch->item_type == 0){
					cout << "You already have the item " << objects[i] << " in your inventary. Type Inventary to see it\n";
					return true;
				}
			}
			else if (Lighter->name == objects[i]) {
				if (Lighter->item_type == num) {
					cout << "You got: " << objects[i] << "\n";
					Lighter->item_type = PLAYER;
					return true;
				}
				else if(Lighter->item_type == 0){
					cout << "You already have the item " << objects[i] << " in your inventary. Type Inventary to see it\n";
					return true;
				}
			}
			else if (Hook->name == objects[i]) {
				if (Hook->item_type == num) {
					cout << "You got: " << objects[i] << "\n";
					Hook->item_type = PLAYER;
					return true;
				}
				else if(Hook->item_type == 0){
					cout << "You already have the item " << objects[i] << " in your inventary. Type Inventary to see it\n";
					return true;
				}
			}
			else if (Liana->name == objects[i]) {
				if (Liana->item_type == num) {
					cout << "You got: " << objects[i] << "\n";
					Liana->item_type = PLAYER;
					return true;
				}
				else if(Liana->item_type == 0){
					cout << "You already have the item " << objects[i] << " in your inventary. Type Inventary to see it\n";
					return true;
				}
				
			}	
			else if (HookedLiana->name == objects[i]) {
				if (HookedLiana->item_type == num) {
					cout << "You got: " << objects[i] << "\n";
					HookedLiana->item_type = PLAYER;
					return true;
				}
				else if(HookedLiana->item_type == 0){
					cout << "You already have the item " << objects[i] << " in your inventary. Type Inventary to see it\n";
					return true;
				}
				
			}	
		}		
	}
	return false;
	

}void Item::Inventory() {
	cout << "You have in your INVENTORY:\n";

	if (Torch->item_type == 0) {
		cout << "-" << Torch->name << " -> "<< Torch->description << "\n";
	}
	if (Lighter->item_type == 0) {
		cout << "-" << Lighter->name << " -> " << Lighter->description << "\n";
	}
	if (Hook->item_type == 0) {
		cout << "-" << Hook->name << " -> "<< Hook->description << "\n";
	}
	if (Liana->item_type == 0) {
		cout << "-" << Liana->name << " -> "<< Liana->description << "\n";
	}
	if (HookedLiana->item_type == 0) {
		cout << "-" << HookedLiana->name << " -> "<< HookedLiana->description << "\n";
	}

}