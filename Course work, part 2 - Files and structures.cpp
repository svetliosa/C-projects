#include <iostream>
#include <locale>
#include <string>
#include <fstream>

using namespace std;

struct polet{
	string den;
	string nomer;
	string ime;
	int broi_1_klasa;
	int broi_2_klasa;
	int cena_1_klasa;
	int cena_2_klasa;
};

void input(polet mas [], int br);
void redakt(polet mas [], int br);
void spravka1(polet mas [], int br);
void spravka2(polet mas [], int br);

int main()
{
	setlocale (LC_ALL, "bulgarian");
	int izbor,br;
	polet arr[10];

	do{
		cout<<"Изберете условие от задачата"<<endl;
		cout<<"1 Регистриране на полет"<<endl;
		cout<<"2 Редактиране на съдържанието"<<endl;
		cout<<"3 Справка за полетите на зададен пилот"<<endl;
		cout<<"4 Справка на всички регистрирани полети за месец март"<<endl;
		cout<<"5 Изход"<<endl;
		do{
			cout<<"Моля изберете условие: "<<endl;
			cin>>izbor;}
		while((izbor<1)||(izbor>5));
		switch(izbor)
		{
		case 1: 
			do{
				cout<<"________________________________________________________________________________"<<endl;
				cout<<"Колко полета искате да регистрирате? (може да регистрирате най-много 10 полета)"<<endl;
				cout<<"________________________________________________________________________________"<<endl;
				cin>>br;
			}while((br<1)||(br>10));	
			input(arr, br);
			break;
		case 2: 
			redakt(arr, br);
			break;
		case 3: 
			spravka1(arr, br);
			break;
		case 4: 
			spravka2(arr, br);
			break;
		}
	}while (izbor!=5);
}

void input(polet arr[], int br)
{
	for(int i=0; i<br; i++){
		cout<<"________________________________________________________________________________"<<endl;
		cout<<"Регистриране на полет номер: "<<i+1<<endl;
		cout<<"Моля въведете днешния ден от месеца: "<<endl;
		cin.ignore();
		getline(cin,arr[i].den);
		cout<<"Моля въведете номер на полета: "<<endl;
		getline(cin,arr[i].nomer);
		cout<<"Моля въведете трите имена на пилота: "<<endl;
		getline(cin,arr[i].ime);
		cout<<"Моля въведете броя на пътниците от 1-ва класа: "<<endl;
		cin>>arr[i].broi_1_klasa;
		cout<<"Моля въведете броя на пътниците от 2-ра класа: "<<endl;
		cin>>arr[i].broi_2_klasa;
		cout<<"Моля въведете цена на билетите от 1-ра класа: "<<endl;
		cin>>arr[i].cena_1_klasa;
		cout<<"Моля въведете цена на билетите от 2-ра класа: "<<endl;
		cin>>arr[i].cena_2_klasa;
		cout<<"________________________________________________________________________________"<<endl;
	}
	fstream file;
	file.open("example.txt", ios::out);
	for(int i=0; i<br; i++){
		file<<"Ден от месеца: "<<arr[i].den<<endl;
		file<<"Номер на полета: "<<arr[i].nomer<<endl;
		file<<"Трите имена на пилота: "<<arr[i].ime<<endl;
		file<<"Брой пътници 1-ва класа: "<<arr[i].broi_1_klasa<<endl;
		file<<"Брой пътници 2-ра класа: "<<arr[i].broi_2_klasa<<endl;
		file<<"Цена на билетите 1-ва класа: "<<arr[i].cena_1_klasa<<endl;
		file<<"Цена на билетите 2-ва класа: "<<arr[i].cena_2_klasa<<endl;
		file<<"________________________________________________________________________________"<<endl;
	}
	file.close();
}

void redakt(polet arr[], int br){
	string nomer;
	int brr=0;
	int kl1,kl2;
	cout<<"________________________________________________________________________________"<<endl;
	cout<<"Моля въведете номера на полета."<<endl;
	cout<<"________________________________________________________________________________"<<endl;
	cin.ignore();
	getline(cin,nomer);
	for(int i=0; i<br; i++){
		if(arr[i].nomer==nomer){
			cout<<"________________________________________________________________________________"<<endl;
			cout<<"Моля въведете брой пътници от 1-ва класа."<<endl;	
			cin>>kl1;
			cout<<"Моля въведете брой пътници от 2-ра класа."<<endl;
			cout<<"________________________________________________________________________________"<<endl;
			cin>>kl2;
			arr[i].broi_1_klasa=kl1;
			arr[i].broi_2_klasa=kl2;
		}
		else{
			brr++;}
	}
	if (brr==br){
		cout<<"________________________________________________________________________________"<<endl;
		cout<<"Въведеният от вас номер е грешен или несъществуващ."<<endl;
		cout<<"________________________________________________________________________________"<<endl;
	}
	fstream file;
	file.open("example.txt", ios::out);
	for(int i=0; i<br; i++){
		file<<"Ден от месеца: "<<arr[i].den<<endl;
		file<<"Номер на полета: "<<arr[i].nomer<<endl;
		file<<"Трите имена на пилота: "<<arr[i].ime<<endl;
		file<<"Брой пътници 1-ва класа: "<<arr[i].broi_1_klasa<<endl;
		file<<"Брой пътници 2-ра класа: "<<arr[i].broi_2_klasa<<endl;
		file<<"Цена на билетите 1-ва класа: "<<arr[i].cena_1_klasa<<endl;
		file<<"Цена на билетите 2-ва класа: "<<arr[i].cena_2_klasa<<endl;
		file<<"________________________________________________________________________________"<<endl;
	}
	file.close();
}


void spravka1(polet arr[], int br){
	string ime;
	int brr=1,а=0;
	cout<<"________________________________________________________________________________"<<endl;
	cout<<"Моля въведете името на пилота, който търсите."<<endl;
	cout<<"________________________________________________________________________________"<<endl;
	cin.ignore();
	getline(cin,ime);
	for(int i=0; i<br; i++){
		if(arr[i].ime==ime){
			cout<<"________________________________________________________________________________"<<endl;
			cout<<"Полет номер: "<<brr<<endl;
			cout<<"Ден от месеца:"<<arr[i].den<<endl;
			cout<<"Номер на полета: "<<arr[i].nomer<<endl;
			cout<<"Трите имена на пилота: "<<arr[i].ime<<endl;
			cout<<"Брой пътници 1-ва класа: "<<arr[i].broi_1_klasa<<endl;
			cout<<"Брой пътници 2-ра класа: "<<arr[i].broi_2_klasa<<endl;
			cout<<"Цена на билетите 1-ва класа: "<<arr[i].cena_1_klasa<<endl;
			cout<<"Цена на билетите 2-ва класа: "<<arr[i].cena_2_klasa<<endl;
			cout<<"________________________________________________________________________________"<<endl;
			brr++;
		}
		else{
			а++;}
	}
	if (а==br){
		cout<<"________________________________________________________________________________"<<endl;
		cout<<"Името на въведения от вас пилот е грешено или несъществува."<<endl;
		cout<<"________________________________________________________________________________"<<endl;
	}
}


void spravka2(polet arr[], int br){
	for(int i=0; i<br; i++){
		cout<<"________________________________________________________________________________"<<endl;
		cout<<"Полет номер "<<i+1<<endl;
		cout<<"Ден от месеца: "<<arr[i].den<<endl;
		cout<<"Номер на полета: "<<arr[i].nomer<<endl;
		cout<<"Трите имена на пилота: "<<arr[i].ime<<endl;
		cout<<"Брой пътници 1-ва класа: "<<arr[i].broi_1_klasa<<endl;
		cout<<"Брой пътници 2-ра класа: "<<arr[i].broi_2_klasa<<endl;
		cout<<"Цена на билетите 1-ва класа: "<<arr[i].cena_1_klasa<<endl;
		cout<<"Цена на билетите 2-ва класа: "<<arr[i].cena_2_klasa<<endl;
		cout<<"________________________________________________________________________________"<<endl;
	}
}