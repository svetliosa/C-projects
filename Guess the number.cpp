#include <iostream>
#include <locale>
#include <time.h> 
using namespace std;
int main()
{
	int  r,t=5,g;
	setlocale (LC_ALL, "bulgarian");
	srand (time(NULL));
	r=rand() % 100 + 1;
	do {
		cout << "Имаш " <<t<< " опита да познаеш числото от 1 до 100"<<endl;
		cout << "Въведи число: " << endl;
		cin >> g;
		t--;
		if (t <= 0){
			break;
		}
		if (g < r){
			cout << "Нагоре"<<endl;
		}
		else if (g> r){
			cout << "Надолу"<<endl;
		}
	} while (g != r );
	if (g == r){
		cout << "Честито позна числото" << endl;
	}
	else if (t==0){
		cout << "Изгуби, нямаш повече опити" << endl;
	}
	return 0;
}


