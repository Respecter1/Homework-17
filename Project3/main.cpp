/*
	����� �������� � ������ 2 ����� �����, 
	��� ������ �� �������� �����-����� ����������� �� ��������� �������� �������-�����.
	������ �������� �����-���� ��������.
*/


#include <string>
#include <iostream>

using str = std::string;//�� ��� �������� ���� ���� ������ string   

class MyRabbit
{
public:
	MyRabbit(str name);
	~MyRabbit();

	void Show()const;
	str GetName()const { return name_; }

	static int GetInHole()  { return InHole; }
private:
	str name_;
	static int InHole;//������� �������� ���� 
};

int MyRabbit::InHole = 0;

int main()
{
	
	MyRabbit Eugene{ "Eugene" };
	MyRabbit Victoria{ "Victoriia" };
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

void MyRabbit::Show() const {

	if (GetInHole() > 1)
		std::cout << "there are " << InHole << " rabbits in the hole\n";

	else if (GetInHole())
		std::cout << "there is " << InHole << " rabbit in the hole\n";

	else
		std::cout << "there are no rabbits in the hole.\n";
}


