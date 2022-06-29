#include <iostream>
#include <cstdlib>

#include "Map.h"
#include "item.h"

const int numObj = 5;

const char* objects[numObj]
= { "Torch", "Lighter", "Hook", "Liana", "HookedLiana"};

Item* Torch = new Item("Torch", "Looks like you'll need a lighter.", ROOM0, COMBINE0);
Item* Lighter = new Item("Lighter", "Looks like you could use it once.", ROOM1, COMBINE0);
Item* Hook = new Item("Hook", "You only need something to attach it to.", ROOM2, COMBINE1);
Item* Liana = new Item("Liana", "You only need something else to use it for leaving the cave.", ROOM3, COMBINE1);
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

bool Item::LightRoom() {
	if (Torch->item_comb == NOTCOMBINABLE && (Torch->item_type == 0 || Torch->item_type == 3)) {
		return true;
	}
	return false;
}

bool Item::WinItem() {
	if (HookedLiana->item_type == PLAYER) {
		return true;
	}
	return false;
}

void Item::ItemsRoom(int num) {
	if (Torch->item_type == num) {
		cout << "You can see the item: " << Torch->name << "\n";
	}
	if (Lighter->item_type == num) {
		cout << "You can see the item: " << Lighter->name << "\n";
	}
	if (Hook->item_type == num) {
		cout << "You can see the item: " << Hook->name << "\n";
	}
	if (Liana->item_type == num) {
		cout << "You can see the item: " << Liana->name << "\n";
	}
	if (HookedLiana->item_type == num) {
		cout << "You can see the item: " << HookedLiana->name << "\n";
	}
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
}

bool Item::DropItem(string order, int num) {
	for (int i = 0; i < numObj; i++) {
		string objName = objects[i];
		string objName2 = "Drop" + objName;
		if (order ==objName2) {

			if (Torch->name == objects[i]) {
				if (Torch->item_type == 0) {
					cout << "You dropped: " << objects[i] << "\n";
					Torch->item_type = (ItemState)num;
					return true;
				}
			}
			else if (Lighter->name == objects[i]) {
				if (Lighter->item_type == 0) {
					cout << "You dropped: " << objects[i] << "\n";
					Lighter->item_type = (ItemState)num;
					return true;
				}
			}
			else if (Hook->name == objects[i]) {
				if (Hook->item_type == 0) {
					cout << "You dropped: " << objects[i] << "\n";
					Hook->item_type = (ItemState)num;
					return true;
				}
			}
			else if (Liana->name == objects[i]) {
				if (Liana->item_type == 0) {
					cout << "You dropped: " << objects[i] << "\n";
					Liana->item_type = (ItemState)num;
					return true;
				}
			}	
			else if (HookedLiana->name == objects[i]) {
				if (HookedLiana->item_type == 0) {
					cout << "You dropped: " << objects[i] << "\n";
					HookedLiana->item_type = (ItemState)num;
					return true;
				}
			}	
		}	
	}
	cout << "You don't have that item in your INVENTORY\n";
	return true;
}

bool Item::CombineItem(string order, int num) {
	string combinedItem;
	for (int i = 0; i < numObj; i++) {
		string objName = objects[i];
		string objName2 = "Combine" + objName;
		if (order ==objName2) {

			if (Torch->name == objects[i]) {
				if (Torch->item_type == 0) {
					cout << "Combine " << objects[i] << " with:\n";
					cin >> combinedItem;
					if (combinedItem == objects[1] && Lighter->item_type == 0) {
						Torch->item_comb = NOTCOMBINABLE;
						Torch->description = "Now the Torch is on fire, so it makes light.";
						delete Lighter;
						return true;
					}
				}
			}
			else if (Lighter->name == objects[i]) {
				if (Lighter->item_type == 0) {
					cout << "Combine " << objects[i] << " with:\n";
					cin >> combinedItem;
					if (combinedItem == objects[0] && Torch->item_type == 0) {
						Torch->item_comb = NOTCOMBINABLE;
						Torch->description = "Now the Torch is on fire, so it makes light.";
						delete Lighter;
						return true;
					}
				}
			}
			else if (Hook->name == objects[i]) {
				if (Hook->item_type == 0) {
					cout << "Combine " << objects[i] << " with:\n";
					cin >> combinedItem;
					if (combinedItem == objects[3] && Liana->item_type == 0) {
						HookedLiana->item_type = PLAYER;
						delete Liana;
						delete Hook;
						return true;
					}
				}
			}
			else if (Liana->name == objects[i]) {
				if (Liana->item_type == 0) {
					cout << "Combine " << objects[i] << " with:\n";
					cin >> combinedItem;
					if (combinedItem == objects[2] && Hook->item_type == 0) {
						HookedLiana->item_type = PLAYER;
						delete Liana;
						delete Hook;
						return true;
					}
				}
			}		
		}	
	}
	cout << "You can't Combine that or you don't have all the items said\n";
	return true;
}

void Item::Inventory() {
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