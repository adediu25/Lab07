#pragma once

#include <iostream>
#include <string>

class Part {
private:
	int PartNumber;				//Part number
	std::string Description;	//Part description
	float Price;				//Part price
	std::string UOM;			//Part unit of measure (ft, lb, each, etc.)
	int QuantityOnHand;			//The quantity on hand of the part
	int LeadTime;				//The number of days to get the part if out of stock

public:
	Part();
	Part(int);
	Part(int, std::string, float, std::string, int = 0);
	std::string GetPartInfo() const;	//Returns "Part Number: [PartNumber].
								//		   Description: [Description]."	
	float GetPrice();
	int GetQuantity();			//Gets quantity
	bool InStock();				//True if quantity > 0
	bool Available(int);		//True if in stock now or by the desired date
	bool operator>(Part);		//Compares PartNumbers of 2 parts
	bool operator<(Part);		//Compares PartNumbers of 2 parts
	bool operator>=(Part);
	bool operator<=(Part);
	bool operator==(Part);	//Compares PartNumbers of 2 parts
	// Overload so that part can be printed using print() from LinkedList
	friend std::ostream& operator<<(std::ostream&, const Part&);
	Part(const Part&) = default;
	Part& operator=(const Part&) = default;
};