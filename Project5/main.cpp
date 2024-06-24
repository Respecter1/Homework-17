/*
	Додайте дві додаткові змінні-члени до класу з попередніх вправ.
	Додайте методи доступу, які повертають значення всіх цих змінних.
	Усі функції-члени повинні повертати значення однакового типу та мати однакову сигнатуру.
	Для доступу до цих методів використовуйте вказівник на функцію члена.
*/

#include <iostream>
#include <string>

using str = std::string;//псевдонім для типу данних string(це я вився як воно працює)

class MyRabbit {
public:
	MyRabbit(str name, int age, int height, int weight);
	~MyRabbit();

	void Show() const;
	//------------------------методи доступу---------------------------
	str GetName() const { return name_; }
	static int GetInHole() { return InHole; } // статична функція для отримання  InHole
	int GetAge() const { return age_; }
	int GetHeight() const { return height_; }
	int GetWeight() const { return weight_; }
	//------------------------------------------------------------------
private:
	static int InHole; // Статична змінна, яка показує кількість кроликів у норі

	str name_; // Ім'я кролика
	int age_;//не статична змінна
	int height_;//+2 зміннні
	int weight_;
};

int MyRabbit::InHole = 0; // Ініціалізація статичної змінної InHole

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
	// Створення об'єктів класу MyRabbit з різними іменами та параметрами
	MyRabbit Eugene{ "Eugene", 1, 2, 43 };
	MyRabbit Victoria{ "Victoria", 1, 1, 38 };
	MyRabbit Romchik{ "Romchik", 1, 1, 37 };

	//-----------------Вказівник на функцію-член для-------------------------
	// отримання значення віку
	int (MyRabbit:: * getAgePtr)() const = &MyRabbit::GetAge;

	//отримання значення висоти
	int (MyRabbit:: * getHeightPtr)() const = &MyRabbit::GetHeight;

	//отримання значення ваги
	int (MyRabbit:: * getWeightPtr)() const = &MyRabbit::GetWeight;
	//------------------------------------------------------------------------

	// Виведення значень для кожного об'єкту за допомогою вказівників на функції-члени
	std::cout << "\nRabbit Roman's age: " << (Romchik.*getAgePtr)() << " year(s)\n";
	std::cout << "Rabbit Roman's height: " << (Romchik.*getHeightPtr)() << " cm\n";
	std::cout << "Rabbit Roman's weight: " << (Romchik.*getWeightPtr)() << " kg\n\n";

	return 0;
}
