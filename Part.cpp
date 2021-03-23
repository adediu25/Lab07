#include "Part.h"
#include <string>

Part::Part() {
	PartNumber = 0;
	Description = "";
	Price = 0;
	UOM = "";
	QuantityOnHand = 0;
}

Part::Part(int num) {
	PartNumber = num;
	Description = "";
	Price = 0;
	UOM = "";
	QuantityOnHand = 0;
}

Part::Part(int number, std::string desc, float prc, std::string unit, int quan) {
	PartNumber = number;
	Description = desc;
	Price = prc;
	UOM = unit;
	QuantityOnHand = quan;
}

std::string Part::GetPartInfo() const {
	return "PartNumber: " + std::to_string(PartNumber) + "\nDescription: " + Description;
}

float Part::GetPrice() {
	return Price;
}

int Part::GetQuantity() {
	return QuantityOnHand;
}

bool Part::InStock() {
	return QuantityOnHand > 0;
}

bool Part::Available(int days) {
	if (InStock())
		return true;
	else {
		return days > LeadTime;
	}
}

bool Part::operator>(Part part2) {
	return this->PartNumber > part2.PartNumber;
}

bool Part::operator<(Part part2) {
	return this->PartNumber < part2.PartNumber;
}

bool Part::operator>=(Part part2) {
	return this->PartNumber >= part2.PartNumber;
}

bool Part::operator<=(Part part2) {
	return this->PartNumber <= part2.PartNumber;
}

bool Part::operator==(Part part2) {
	return this->PartNumber == part2.PartNumber;
}

std::ostream& operator<<(std::ostream& out, const Part& part) {
	out << part.GetPartInfo();
	return out;
}
