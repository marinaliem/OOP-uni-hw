#include "pch.h"
#include <iostream>

class Device {
protected:
	char* producer;
public:
	virtual void print() = 0;
	virtual int getPerf() = 0;
};
class Laptop : public virtual Device {
	int megaherz;
public:
	void print() {
		std::cout << "Producer: " << producer << std::endl;
		std::cout << "Speed: " << megaherz << std::endl;
	}
	int getPerf() {
		return megaherz;
	}
};
class Car : public virtual Device {
protected:
	int kw;
	int cm3;
	void print() {
		std::cout << "Producer: " << producer << std::endl;
		std::cout << "Power: " << kw << std::endl;
		std::cout << "Vol: " << cm3 << std::endl;
	}
	int getPerf() {
		return kw;
	}
};

template<typename T>
class Inventory {
	T inv[100];
	void inf() {
		for (int i = 0; i < 100; i++) {
			inv[i].print();
		}
	}
	bool incSrt() {
		for (int i = 0; i < 100; i++) {
			if (inv[i].getPerf() < inv[i + 1].getPerf()) return false;
		}
		return true;
	}
};
int main()
{

	return 0;
}
