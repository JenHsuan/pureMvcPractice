#include "ValueContainer.h"

ValueContainer::ValueContainer(){
	SetValue(0);
};
ValueContainer::~ValueContainer(){};
void ValueContainer::SetValue(int value){
	this->currentValue = value;
}
int ValueContainer::GetValue(){
	return this->currentValue;
}