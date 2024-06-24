/*
�������������� ���������� ���� �� ������ 1,
�������� ������� ������������ ��������, ��� ������� ��� ��'����,
� ���� �������� �������� �� ������-����� �� �������� �����-����� �����.
���� ��������� ��������� ��'���� �� �������� �� ����� �������� �������� �����-�����.
*/

#include <string>
#include <iostream>

using str = std::string;//�� ��� �������� ���� ���� ������ string   

class MyRabbit
{
public:
	static int InHole;//�������� ����� ��� ���������� ������ ������ � �����
	
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
