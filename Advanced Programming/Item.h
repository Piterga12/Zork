#ifndef __Item__
#define __Item__

#include <string>

using namespace std;

enum ItemState
{
	PLAYER = 0,
	ROOM0 = 1,
	ROOM1 = 2,
	ROOM2 = 3,
	ROOM3 = 4,
	NOTGETABLE = 5
};
enum ItemComb
{
	COMBINE0,
	COMBINE1,
	NOTCOMBINABLE
};


class Item
{
public:
	Item() = default;
	Item(const char* name, const char* description, ItemState item_type, ItemComb item_comb);
	~Item();

	bool GetItem(string order, int num);
	bool DropItem(string order, int num);
	bool CombineItem(string order, int num);
	bool LightRoom();
	bool WinItem();
	void ItemsRoom(int num);
	void Inventory();

	int GetValue() const;

public:
	std::string name;
	std::string description;
	int min_value;
	int max_value;
	ItemState item_type;
	ItemComb item_comb;

};

#endif