#include <iostream>
#include <locale>
using namespace std;
int main()
{
	{
		setlocale (LC_ALL, "bulgarian");
		int d,m,y,days;
		cout<<endl<<"Въведете днешния ден ";
		cin>>d;
		cout<<endl<<"Въведете днешния месец ";
		cin>>m;
		cout<<endl<<"Въведете днешната година ";
		cin>>y;
		switch (m)
		{ case 4: case 6: case 9: case 11: days=30; break;
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: days=31; break;
		case 2: 
			if (y%4==0){
				days=29;
			}
			else if  (y%4!=0){
				days=28;
			}
			break;
		}
		if (d>31 || m>12 || y<2017){
			cout<<"Въведете валидна дата"<<endl;
		}
		else
		{
			if (d==days && m==12){
				d=1; m=1; y++;
			}
			else if (d==days ){
				d=1;  m++; 
			}
			else if (d==days && m<12){
				d=1; m++;
			}
			else if (d < days){ 
				d++;
			}
			cout<<"Утрешната дата е "<<d<<"."<<m<<"."<<y<<"г"<<endl;
		}
	}
	return 0;
}  
