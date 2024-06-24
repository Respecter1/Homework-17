/*
	Створіть у програмі з вправи 3 вказівник на функцію-член 
	для доступу до значення нестатичної змінної-члена і скористайтеся ним 
	для виведення цих значень на друк.
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

    static int GetInHole()  { return InHole; } // статична функція для отримання  InHole
    int GetAge() const { return age_; }
private:
    static int InHole; // Статична змінна, яка показує кількість кроликів у норі
    str name_; // Ім'я кролика
    int age_;//не статична змінна
};

int MyRabbit::InHole = 0; // Ініціалізація статичної змінної InHole

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
    // Створення об'єктів класу MyRabbit з різними іменами
    MyRabbit Eugene{ "Eugene" };
    MyRabbit Victoria{ "Victoria" };
    MyRabbit Romchik{ "Romchik" };

    // Вказівник на функцію-член для отримання значення віку
    int (MyRabbit:: * getAgePtr)() const = &MyRabbit::GetAge;


    // Виведення значень віку для кожного об'єкту за допомогою вказівника на функцію-член
    std::cout << "\nRabbit Roman says he is not yet  " << (Romchik.*getAgePtr)() << " year old\n\n";

    return 0;
}
