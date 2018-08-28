#include <iostream>
#include <locale>
#include <string>
#include <fstream>

using namespace std;

struct smetka{
	string nomer;
	int suma;
};

void input(smetka mas [], int br);
void vnasqne(smetka mas [], int br);
void teglene(smetka mas [], int br);
void spravka(smetka mas [], int br);
void prehvurlqne(smetka mas [], int br);

int main()
{
	setlocale (LC_ALL, "bulgarian");
	int izbor,br;
	smetka arr[10];

	do{

		cout<<"1 Регистриране на сметка"<<endl;
		cout<<"2 Внасяне на пари"<<endl;
		cout<<"3 Теглене на пари"<<endl;
		cout<<"4 Справка на сумата във вашата сметка"<<endl;
		cout<<"5 Прехвърляне на пари от една сметка в друга"<<endl;
		cout<<"6 Изход"<<endl;
		do{
			cout<<"Моля изберете условие: "<<endl;
			cin>>izbor;}
		while((izbor<1)||(izbor>6));
		switch(izbor)
		{
		case 1: 
			do{
				cout<<"________________________________________________________________________________"<<endl;
				cout<<"Колко сметки искате да регистрирате? (може да регистрирате най-много 10 полета)"<<endl;
				cout<<"________________________________________________________________________________"<<endl;
				cin>>br;
			}while((br<1)||(br>10));	
			input(arr, br);
			break;
		case 2: 
			vnasqne(arr, br);
			break;
		case 3: 
			teglene(arr, br);
			break;
		case 4: 
			spravka(arr, br);
			break;
		case 5:
			prehvurlqne(arr, br);
			break;
		}
	}while (izbor!=6);
}


void input(smetka arr[], int br)
{
	for(int i=0; i<br; i++){
		cout<<"________________________________________________________________________________"<<endl;
		cout<<"Регистриране на сметка: "<<i+1<<endl;
		cout<<"Моля въведете номер на сметката: "<<endl;
		cin.ignore();
		getline(cin,arr[i].nomer);
		cout<<"Моля въведете начален баланс на сметката в лева: "<<endl;
		cin>>arr[i].suma;
		cout<<"________________________________________________________________________________"<<endl;
	}
	fstream file;
	file.open("atm.txt", ios::out);
	for(int i=0; i<br; i++){
		file<<"Номер на сметката: "<<arr[i].nomer<<endl;
		file<<"Сума на сметката: "<<arr[i].suma<<endl;
		file<<"________________________________________________________________________________"<<endl;
	}
	file.close();
}


void vnasqne(smetka arr[], int br){
	string nom;
	int sum;
	cout<<"________________________________________________________________________________"<<endl;
	cout<<"Моля въведете номера на сметката: "<<endl;
	cin.ignore();
	getline(cin,nom);
	cout<<"Моля въведете сумата в лева, която желаете да внесете: "<<endl;
	cin>>sum;
	for(int i=0; i<br; i++){
		if(arr[i].nomer==nom){
			arr[i].suma=arr[i].suma+sum;
		}
	}
	fstream file;
	file.open("atm.txt");
	for(int i=0; i<br; i++){
		file<<"Номер на сметката: "<<arr[i].nomer<<endl;
		file<<"Сума на сметката: "<<arr[i].suma<<endl;
		file<<"________________________________________________________________________________"<<endl;
	}
	file.close();
}

void teglene(smetka arr[], int br){
	string nom;
	int sum;
	cout<<"________________________________________________________________________________"<<endl;
	cout<<"Моля въведете номера на сметката: "<<endl;
	cin.ignore();
	getline(cin,nom);
	cout<<"Моля въведете сумата в лева, която желаете да изтеглите: "<<endl;
	cin>>sum;
	for(int i=0; i<br; i++){
		if(arr[i].nomer==nom){
			arr[i].suma=arr[i].suma-sum;
		}
	}
	fstream file;
	file.open("atm.txt");
	for(int i=0; i<br; i++){
		file<<"Номер на сметката: "<<arr[i].nomer<<endl;
		file<<"Сума на сметката: "<<arr[i].suma<<endl;
		file<<"________________________________________________________________________________"<<endl;
	}
	file.close();
}

void spravka(smetka arr[], int br){
	string nom;
	cout<<"________________________________________________________________________________"<<endl;
	cout<<"Моля въведете номера на сметката: "<<endl;
	cin.ignore();
	getline(cin,nom);
	for(int i=0; i<br; i++){
		if(arr[i].nomer==nom){
			cout<<"Сумата във вашата сметка е: "<<arr[i].suma<<" лв. "<<endl;
			cout<<"________________________________________________________________________________"<<endl;
		}
	}
}

void prehvurlqne(smetka arr[], int br){
	string nom1, nom2;
	int sum;
	cout<<"________________________________________________________________________________"<<endl;
	cout<<"Моля въведете номера на сметката, на която искате да прехвърлите сумата: "<<endl;
	cin.ignore();
	getline(cin,nom2);
	cout<<"Моля въведете номера на сметката, от която искате да прехвърлите сумата: "<<endl;
	
	getline(cin,nom1);
	cout<<"Моля въведете сумата в лева, която желаете да изтеглите: "<<endl;
	cin>>sum;
	for(int i=0; i<br; i++){
		if(arr[i].nomer==nom1){
			arr[i].suma=arr[i].suma-sum;
		}
	}
	for(int i=0; i<br; i++){
		if(arr[i].nomer==nom2){
			arr[i].suma=arr[i].suma+sum;
		}
	}

	fstream file;
	file.open("atm.txt");
	for(int i=0; i<br; i++){
		file<<"Номер на сметката: "<<arr[i].nomer<<endl;
		file<<"Сума на сметката: "<<arr[i].suma<<endl;
		file<<"________________________________________________________________________________"<<endl;
	}
	file.close();
}