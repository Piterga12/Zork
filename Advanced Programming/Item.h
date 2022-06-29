#ifndef __Item__
#define __Item__

#include <string>

using namespace std;

enum ItemState
{
	PLAYER,
	ROOM0,
	ROOM1,
	ROOM2,
	ROOM3,
	NOTGETABLE
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