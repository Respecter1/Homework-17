/*
	������� � ������� � ������ 3 �������� �� �������-���� 
	��� ������� �� �������� ���������� �����-����� � ������������� ��� 
	��� ��������� ��� ������� �� ����.
*/

#include <iostream>
#include <string>

using str = std::string;

class MyRabbit {
public:
    MyRabbit(str name);
    ~MyRabbit();

    void Show() const;
    str GetName() const { return name_; }

    static int GetInHole()  { return InHole; } // �������� ������� ��� ���������  InHole
    int GetAge() const { return age_; }
private:
    static int InHole; // �������� �����, ��� ������ ������� ������� � ���
    str name_; // ��'� �������
    int age_;//�� �������� �����
};

int MyRabbit::InHole = 0; // ����������� �������� ����� InHole

MyRabbit::MyRabbit(str name) : name_(name),age_(1) {
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
        std::cout << "There are " << InHole << " rabbits in the hole\n";
    else if (GetInHole())
        std::cout << "There is " << InHole << " rabbit in the hole\n";
    else
        std::cout << "There are no rabbits in the hole.\n";
}

int main() {
    // ��������� ��'���� ����� MyRabbit � ������ �������
    MyRabbit Eugene{ "Eugene" };
    MyRabbit Victoria{ "Victoria" };
    MyRabbit Romchik{ "Romchik" };

    // �������� �� �������-���� ��� ��������� �������� ���
    int (MyRabbit:: * getAgePtr)() const = &MyRabbit::GetAge;


    // ��������� ������� ��� ��� ������� ��'���� �� ��������� ��������� �� �������-����
    std::cout << "\nRabbit Roman says he is not yet  " << (Romchik.*getAgePtr)() << " year old\n\n";

    return 0;
}
