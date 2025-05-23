**Теоретична задача:** Какво ще отпечата кодът? Има ли грешки в него?

```c++
class A {
	int x;
	char c;
public:
	void f() const {
    		std::cout << x << std::endl;
	}

	virtual void g() const {
    		std::cout << (int)c << std::endl;
	}
};

class B : public A {
	void g() override {
    		std::cout << "Pract12" << c << std::endl;
	}
};

int main() {
	A* b = new B();
	std::cout << sizeof(b) << std::endl;
	std::cout << sizeof(*b) << std::endl;
	b->g();
}
```

**Задача 1:** Създайте опростен калкулатор, при който:
Всяка константа е израз.
Всичко от вида -(израз) е израз.
Всичко от вида (израз)^(константа) е израз.
Всичко от вида (израз + израз) е израз.
Всичко от вида (израз * израз) е израз.
Трябва да има метод evaluate(), който позволява да се намери стойността на подаден израз.
Примерен main:

```c++
int main()
{
	Expression* two = new Constant(2);
	Expression* four = new Constant(4);
	Expression* one = new Constant(1);
	Expression* negOne = new Negated(one);
	Expression* sumTwoFour = new Addition(two, four);
	Expression* mult = new Multiplication(sumTwoFour, negOne);
	Expression* exp = new Exponent(mult, 2);
	Expression* res = new Addition(exp, one);


	std::cout << res->evaluate() << "\n";
	//…….
}
```

Дефинирайте клас компаратор, който приема два израза и извежда 1, ако резултатът от първия е по-голям, 0, ако са равни, и -1 ако резултатът от втория е по-голям.
Бонус: Направете йерархия от компаратори. Един сравняващ по големина, един по модул и един, който сравнява по дължината на резултатите (15=16 и -100>1). Минусът не се брои в дължината.

**Задача 2:** Трябва да реализирате играта "Камък, ножица, хартия", като използвате visitor pattern за определяне на победителя между различните фигури (камък, ножица, хартия). Всеки от обектите, които представляват фигури в играта, трябва да има метод fight(), който приема друг обект от тип Shape (камък, ножица или хартия) и връща резултата от битката (победа, загуба или равенство). Напишете и фактори за създаването на обектите. В мейна сбийте няколко обекта.
