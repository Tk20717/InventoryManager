#pragma once
#include "Product.h"
#include <string>
using namespace std;

enum PerishType
{
	NonPerishable, Freezer,
	Fridge, NonRefridgerated
};

class Perishable : public Product{

private:
	PerishType perishType;
	int shelfLife;

public:
	Perishable() : Product(){
	}
	Perishable(string name, Department department, double price, double salePrice, double weight, int ID, int quantity, PerishType perishType, int shelfLife)
		: Product(name, department, price, salePrice, weight, ID, quantity){
		setPerishType(perishType);
		setShelfLife(shelfLife);
	}

	//Mutators
	void setPerishType(PerishType perishType) { this->perishType = perishType; }
	void setPerishType(int i) { this->perishType = getPerishType(i); } //Jake added this
	void setShelfLife(int shelfLife) { if (shelfLife > 0) { this->shelfLife = shelfLife; } }

	//Accessors
	PerishType getPerishType() const { return perishType; }

	PerishType getPerishType(int i) { //Jake added this
		switch (i)
		{
		case 0: return NonPerishable; break;
		case 1: return Freezer; break;
		case 2: return Fridge; break;
		case 3: return NonRefridgerated; break;
		}
	}
	int getShelfLife() const { return shelfLife; }

	std::string getPerishName() const //Jake thinks he added this
	{
		switch (perishType){
		case 0: return "NonPerishable"; break;
		case 1: return "Freezer"; break;
		case 2: return "Fridge"; break;
		case 3: return "NonRefridgerated"; break;
		
		default: return "ERROR - not a category"; break;
		}
	}
	int getPerishNum() const {
		switch (perishType) {
		case 0: return 0; break;
		case 1: return 1; break;
		case 2: return 2; break;
		case 3: return 3; break;
		default: return 0; break;
		}
	}

	void displayProductInformation() const{}
};

