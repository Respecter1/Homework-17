/*
Використовуючи програмний блок із вправи 1,
напишіть коротку виконувальну програму, яка створює три об'єкти,
а потім виводить значення їх змінних-членів та статичної змінної-члена класу.
Потім послідовно видаляйте об'єкти та виводьте на екран значення статичної змінної-члена.
*/

#include <string>
#include <iostream>

using str = std::string;//це даю псевдонім моєму типу данних string   

class MyRabbit
{
public:
	static int InHole;//статична змінна для розрахунку скільки кролей в норці
	
	MyRabbit(str name);
	~MyRabbit();

	void Show()const;
	str GetName()const { return name_; }

private:
	str name_;
};


int MyRabbit::InHole = 0;

int main()
{

	MyRabbit Eugene{ "Eugene" };
	MyRabbit Victoria{ "Victoria" };
	MyRabbit Romchik{ "Romchik" };

	return 0;
}


MyRabbit::MyRabbit(str name) :name_(name) {
	std::cout << "Rabbit " << name_ << " went into the hole...\n";
	++InHole;
	Show();
}
MyRabbit::~MyRabbit() {
	std::cout << "Rabbit " << name_ << " came out of the hole...\n";
	--InHole; 
	Show();
}

void MyRabbit::Show() const{
	
	if (InHole > 1)
		std::cout << "there are " << InHole << " rabbits in the hole\n\n";

	else if (InHole)
		std::cout << "there is " << InHole << " rabbit in the hole\n\n";

	else
		std::cout << "there are no rabbits in the hole.\n\n";
}
