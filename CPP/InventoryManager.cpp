// InventoryManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Product.h"
#include "Perishable.h"


int main()
{
	Product item = Product("Food", Meat, 10, 8, 1, 6900, 1);
    return 0;
}

