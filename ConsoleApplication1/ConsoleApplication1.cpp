#include "stdafx.h"
#include<iostream>
#include<unordered_map>
#include<string>
class Composite
{
public:
	virtual double getPrice()=0;
	virtual void add(Composite*) = 0;
};
class Item:public Composite
{
	std::string Name;
	double Price;
public:
	Item(std::string name,double price)
	{
		Name = name;
		Price = price;
	}
	void add(Composite*) {}
	double getPrice()override { return Price; }
};
class ItemBox:public Composite
{
	double Price;
	std::string Name;
	std::unordered_map <Composite*, Composite*> itemBox;
public:
	void add(Composite* composite)override
	{
		itemBox[composite] = composite;
	}
	double getPrice()
	{
		double price = 0;
		for (auto&allPrices:itemBox)
		{
			price += allPrices.second->getPrice();
		}
		return price;
	}
};
int main()
{
	Item a("sa", 22);
	Composite*ss=&a;
	ItemBox items;
	items.add(ss);
	std::cout<<items.getPrice();
    return 0;
}

