/*
	������� �� �������� ����-����� �� ����� � ��������� �����.
	������� ������ �������, �� ���������� �������� ��� ��� ������.
	�� �������-����� ������ ��������� �������� ���������� ���� �� ���� �������� ���������.
	��� ������� �� ��� ������ �������������� �������� �� ������� �����.
*/

#include <iostream>
#include <string>

using str = std::string;//�������� ��� ���� ������ string(�� � ����� �� ���� ������)

class MyRabbit {
public:
	MyRabbit(str name, int age, int height, int weight);
	~MyRabbit();

	void Show() const;
	//------------------------������ �������---------------------------
	str GetName() const { return name_; }
	static int GetInHole() { return InHole; } // �������� ������� ��� ���������  InHole
	int GetAge() const { return age_; }
	int GetHeight() const { return height_; }
	int GetWeight() const { return weight_; }
	//------------------------------------------------------------------
private:
	static int InHole; // �������� �����, ��� ������ ������� ������� � ���

	str name_; // ��'� �������
	int age_;//�� �������� �����
	int height_;//+2 �����
	int weight_;
};

int MyRabbit::InHole = 0; // ����������� �������� ����� InHole

MyRabbit::MyRabbit(str name, int age, int height, int weight)
	: name_(name), age_(age), height_(height), weight_(weight)
{
	std::cout << "Rabbit " << name_ << " went into the hole...\n";
	++InHole;	Show();
}


MyRabbit::~MyRabbit() {
	std::cout << "Rabbit " << name_ << " came out of the hole...\n";
	--InHole;	Show();
}

void MyRabbit::Show() const {
	if (InHole > GetInHole()) { std::cout << "There are " << InHole << " rabbits in the hole\n"; }
	else if (InHole) { std::cout << "There is " << InHole << " rabbit in the hole\n"; }
	else { std::cout << "There are no rabbits in the hole.\n"; }

}

int main() {
	// ��������� ��'���� ����� MyRabbit � ������ ������� �� �����������
	MyRabbit Eugene{ "Eugene", 1, 2, 43 };
	MyRabbit Victoria{ "Victoria", 1, 1, 38 };
	MyRabbit Romchik{ "Romchik", 1, 1, 37 };

	//-----------------�������� �� �������-���� ���-------------------------
	// ��������� �������� ���
	int (MyRabbit:: * getAgePtr)() const = &MyRabbit::GetAge;

	//��������� �������� ������
	int (MyRabbit:: * getHeightPtr)() const = &MyRabbit::GetHeight;

	//��������� �������� ����
	int (MyRabbit:: * getWeightPtr)() const = &MyRabbit::GetWeight;
	//------------------------------------------------------------------------

	// ��������� ������� ��� ������� ��'���� �� ��������� ��������� �� �������-�����
	std::cout << "\nRabbit Roman's age: " << (Romchik.*getAgePtr)() << " year(s)\n";
	std::cout << "Rabbit Roman's height: " << (Romchik.*getHeightPtr)() << " cm\n";
	std::cout << "Rabbit Roman's weight: " << (Romchik.*getWeightPtr)() << " kg\n\n";

	return 0;
}
