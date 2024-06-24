/*
	�������� ������� ��������,
	��� ������� ���� � ���� ��������� ������-������ �� ���� ��������� ������-������.
	������� �����������, ���� ������ ����������� �����-����� �� ��������� �������� �����-�����.
	���� �������� ����������, ���� ������ �� ������� �������� �������� �����.
*/

#include <string>

using str = std::string;//�� ��� �������� ���� ���� ������ string   

class MyRabbit
{
public:
	static int InHole;
	
	MyRabbit(str name) :name_(name) { ++InHole; }
	~MyRabbit() { --InHole; }

private:
	str name_;
};


int MyRabbit::InHole = 0;