#include "Part.h"
#include <string>

Part::Part(int number, std::string desc, float prc, std::string unit, int quan) {
	PartNumber = number;
	Description = desc;
	Price = prc;
	UOM = unit;
	QuantityOnHand = quan;
}

std::string Part::GetPartInfo() {
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

bool Part::operator> (Part part2) {
	return PartNumber > part2.PartNumber;
}

bool Part::operator< (Part part2) {
	return PartNumber < part2.PartNumber;
}

bool Part::operator== (Part part2) {
	return PartNumber == part2.PartNumber;
}