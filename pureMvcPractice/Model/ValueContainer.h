#pragma once

class ValueContainer
{
public:

	ValueContainer();
	~ValueContainer();
	void SetValue(int value);
	int GetValue();

private:
	int currentValue;
	

};