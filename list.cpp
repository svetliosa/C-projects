#include<iostream>
using namespace std;
 
void add_b(int n);
int del_b(int &n);
void list();
void repeat();
 
struct elem{
    int key;
    elem *next;
}*start = NULL;
 
void main(){
    int ch, num;
    do{
        cout << "\n MENU\n";
        cout << "1 - Add an element.\n";
        cout << "2 - Del the last entered element.\n";
        cout << "3 - Show the list.\n";
        cout << "4 - Print the element that repeats the most.\n";
        cout << "5 - Exit.\n";
        cin >> ch;
        if (ch == 1){
            cout << "\nInput num: ";
            cin >> num;
        }
        switch (ch){
        case 1: {add_b(num); break; }
 
        case 2: {del_b(num); break; }
 
        case 3: {cout << "\n"; list(); break; }
        case 4: {  repeat(); break; }
        }
    } while (ch != 5);
}
 
void add_b(int n){
    elem *p = start;
    start = new elem;
    start->key = n;
    start->next = p;
}
 
int del_b(int &n){
    elem *p = start;
    if (start){
        n = start->key;
        start = start->next;
        delete p;
        return 1;
    }
    else
        return 0;
}
 
void list(){
    elem *p = start;
    if (start)
        cout << "\n The list is -> ";
    else
        cout << "\n The list is empty.";
    while (p){
        cout << p->key << " ";
        p = p->next;
    }
    cout << "\n\n";
}
 
void repeat(){
 
    elem *p = start;
    elem *q = start;
    elem *f = start;
    int br = 0, max = 0;
    int c = 0;
    int z;
    if (start){
        while (q->next){
 
            z = q->key;
 
            br = 0;
            while (p!=NULL){
                if (z == p->key){ br++; }
                p = p->next;
            }
            q = q->next;
            p = f;
            if (max<br){
                max = br;
                c = z;
            }
        }
        if (c != 0){
            cout << "\nThe most frequent element is: " << c << endl;
            cout << "It's repeating " << max << " times\n";
        }
        else {
            cout << "\nPlease enter more than 1 number.\n";
            list();
        }
    }
    else
        cout << "\n The list is empty";
}