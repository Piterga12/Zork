#ifndef __Item__
#define __Item__

#include <string>
#include <list>



using namespace std;

enum ItemType
{
	COMMON,
	WEAPON,
	ARMOUR
};


class Item
{
public:
	Item() = default;
	Item(const char* name, const char* description, ItemType item_type = COMMON);
	~Item();

	void GetItem(string order);

	int GetValue() const;

public:
	std::string name;
	int min_value;
	int max_value;
	ItemType item_type;

	std::list<Item*> container;
};

#endif