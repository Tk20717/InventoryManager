#pragma once
#include <string>
#include <iostream>


enum Department
{
	Dairy, Deli, Meat, Frozen, Produce, Grocery,
	Bakery, Alcohol, HBCM, GeneralMerchandise, NONE
};

class Product{
private:
	std::string name;
	Department department;
	double price, salePrice, weight;
	int ID, quantity;

public:
	Product(){
		name = "";
		department = NONE;
		price = 0;
		salePrice = 0;
		weight = 0;
		ID = -1;
		quantity = -1;
	}

	Product(std::string name, Department department, double price,
		double salePrice, double weight, int ID, int quantity){
		setName(name);
		setDepartment(department);
		setPrice(price);
		setSalePrice(salePrice);
		setWeight(weight);
		setID(ID);
		setQuantity(quantity);
	}
	
	//Mutators
	void setName(std::string name) { this->name = name; }
	void setDepartment(Department department) { this->department = department; }
	void setDepartment(int i) { this->department = getDepartment(i); } //added by Jake

	void setPrice(double price) { if (price > 0) { this->price = price; } }
	void setSalePrice(double salePrice) { if (salePrice > 0) { this->salePrice = salePrice; } }
	void setWeight(double weight) { if (weight > 0) { this->weight = weight; } }
	void setID(int ID) { this->ID = ID; }
	void setQuantity(int quantity) { if (quantity > 0) { this->quantity = quantity; } }

	//Accessors
	std::string getName() const { return name; }
	Department getDepartment()  const { return department; }
	double getPrice()  const { return price; }
	double getSalePrice()  const { return salePrice; }
	double getWeight()  const { return weight; }
	int getID()  const { return ID; }
	int getQuantity() const { return quantity; }

	//Modifiers to inventory count
	void AddQuantity(int quantity) {
		this->quantity += quantity;
		//Incase of negative input
		if (this->quantity < 0)
		{
			this->quantity = 0;
		}
	}
	void SubtractQuantity(int quantity) {
		this->quantity -= quantity;
		//Incase of over subtracting
		if (this->quantity < 0)
		{
			this->quantity = 0;
		}
	}

	bool Compare(Product item)
	{
		if (getID() == item.getID())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//added by Jake (ithink)
	Department getDepartment(int i) const {
		Department temp;
		switch (i)
		{
		case 0: temp = Dairy; break;
		case 1: temp = Deli; break;
		case 2: temp = Meat; break;
		case 3: temp = Frozen; break;
		case 4: temp = Produce; break;
		case 5: temp = Grocery; break;
		case 6: temp = Bakery; break;
		case 7: temp = Alcohol; break;
		case 8: temp = HBCM; break;
		case 9: temp = GeneralMerchandise; break;
		case 10: temp = NONE; break;

		default: temp = NONE;
		}
		return temp;
	}

	std::string getDepartmentName() const
	{
		std::string temp;
		switch (department)
		{
		case 0: temp = "Dairy"; break;
		case 1: temp = "Deli"; break;
		case 2: temp = "Meat"; break;
		case 3: temp = "Frozen"; break;
		case 4: temp = "Produce"; break;
		case 5: temp = "Grocery"; break;
		case 6: temp = "Bakery"; break;
		case 7: temp = "Alcohol"; break;
		case 8: temp = "HBCM"; break;
		case 9: temp = "GeneralMerchandise"; break;
		case 10: temp = "Unassigned"; break;

		default: temp = "ERROR - not a category";
		}
		return temp;
	}

	//added by Jake
	int getDepartmentNum() const
	{
		int temp;
		switch (department)
		{
		case 0: temp = 0; break;
		case 1: temp = 1; break;
		case 2: temp = 2; break;
		case 3: temp = 3; break;
		case 4: temp = 4; break;
		case 5: temp = 5; break;
		case 6: temp = 6; break;
		case 7: temp = 7; break;
		case 8: temp = 8; break;
		case 9: temp = 9; break;
		case 10: temp = 10; break;
		default: temp = -1;
		}
		return temp;
	}


	void displayProductInformation() const{
	
	}

};


