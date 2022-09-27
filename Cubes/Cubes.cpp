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
	std::cout << "��� ���� � ������!��������� ��� ��� ������ ������� 50 �����!\n\t���� ��������!\n";
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
		std::cout << "������� ���������!\n";
	else
		std::cout << "������� �����!\n";


	return 0;
}
//������ ������
int Throw() {
	return 1 + rand() % 6;
}
int Throw2() {
	int cube_val = Throw();
	if (cube_val % 2 == 0) {
		std::cout << "������ "<<cube_val<<", ���� ����������\n";
		return cube_val *= -1;
	}
	if (cube_val % 2 != 0) {
		std::cout << "������ " << cube_val << ", ���� ������������\n";
		return cube_val;
	}
}
int Game_player() {	
	std::cout << "\t����� �����\n��� ������ ������� <T>: ";
	char n;
	std::cin >> n;
	switch (n) {
	case 'T':case 't':break;
	default:Game_player();
	}
	int cube_val = Throw();
	std::cout << "�� ������� �����, ��� ������ " << cube_val << '\n';
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
	std::cout << "\t��������� �����\n";
	int cube_val = Throw();
	std::cout << "���������� ������ " << cube_val << '\n';
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
	std::cout << "�� ������ ������ ����� ��� ���! ������� Y/N:";
	std::cin >> ch;
	switch (ch)	{
	case 'Y':case 'y':std::cout<<"��������� ������!\n"; return true;
	case 'N':case 'n':std::cout << "��� ��������� ���������\n"; return false;
	default:std::cout << "������ �����!\n";repeat();
	}
}
void show_counter(int num) {
	switch (num) {
	case 2:case 3:case 4:case 22:case 23:case 24:case 32:case 33:
	case 34:case 42:case 43:case 44:std::cout << "������� " << num << " ����\n"; break;
	default:std::cout << "������� " << num << " �����\n";
	}
}
