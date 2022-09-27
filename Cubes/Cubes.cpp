#include <iostream>
#include <cstdlib>
#include <ctime>
int Throw();
int Throw2();
int Game_player();
int Game_computer();
bool repeat();
void show_counter(int num);
int counter_pl = 0;
int counter_com = 0;
int main() {
	setlocale(LC_ALL, "Russian");
	int player, computer;
	srand(time(NULL));
	std::cout << "Это игра в кубики!Побеждает тот кто первый наберет 50 очков!\n\tИгра началась!\n";
	if (rand() % 2 == 0) {
		do
		{
			Game_player();
			Game_computer();
		} while (counter_pl <50 || counter_com<50);		
	}
	else {
		do
		{
			Game_computer();
			Game_player();			
		} while (counter_pl < 50 || counter_com < 50);
	}
	if(counter_com>counter_pl)
		std::cout << "Выиграл компьютер!\n";
	else
		std::cout << "Выиграл игрок!\n";


	return 0;
}
//бросок кубика
int Throw() {
	return 1 + rand() % 6;
}
int Throw2() {
	int cube_val = Throw();
	if (cube_val % 2 == 0) {
		std::cout << "Выпало "<<cube_val<<", очки вычитаются\n";
		return cube_val *= -1;
	}
	if (cube_val % 2 != 0) {
		std::cout << "Выпало " << cube_val << ", очки прибавляются\n";
		return cube_val;
	}
}
int Game_player() {	
	std::cout << "\tИгрок ходит\nДля броска введите <T>: ";
	char n;
	std::cin >> n;
	switch (n) {
	case 'T':case 't':break;
	default:Game_player();
	}
	int cube_val = Throw();
	std::cout << "Вы бросили кубик, вам выпало " << cube_val << '\n';
	if (cube_val == 6) {
		counter_pl += cube_val;
		show_counter(counter_pl);
		if (repeat())
			counter_pl += Throw2();
	}
	else
		counter_pl += cube_val;
	show_counter(counter_pl);
	return counter_pl;
}
int Game_computer() {
	std::cout << "\tКомпьютер ходит\n";
	int cube_val = Throw();
	std::cout << "Компьютеру выпало " << cube_val << '\n';
	if (cube_val == 6) {
		counter_com += cube_val;
		show_counter(counter_com);
		if(repeat())
			counter_com += Throw2();
	}
	else
		counter_com += cube_val;
	show_counter(counter_com);
	return counter_com;
}
bool repeat(){
	char ch;
	std::cout << "Вы можете кинуть кубик еще раз! Введите Y/N:";
	std::cin >> ch;
	switch (ch)	{
	case 'Y':case 'y':std::cout<<"Повторный бросок!\n"; return true;
	case 'N':case 'n':std::cout << "Ход переходит сопернику\n"; return false;
	default:std::cout << "Ошибка ввода!\n";repeat();
	}
}
void show_counter(int num) {
	switch (num) {
	case 2:case 3:case 4:case 22:case 23:case 24:case 32:case 33:
	case 34:case 42:case 43:case 44:std::cout << "Набрано " << num << " очка\n"; break;
	default:std::cout << "Набрано " << num << " очков\n";
	}
}
