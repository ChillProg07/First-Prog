#include <iostream>
#include "bilist.h"
using namespace std;

int main(){
    BiList list, list1, list2, list3;
    int n, val;
cout<<"Введіть кількісь елементів: ";
cin>>n;
cout<<"Введіть елементи: ";
for(int i = 0; i<n; i++){
    cin>>val;
    list.push_back(val);
}
list.forward_view();
list.reverse_view();

BiNode* t = list.front;
while( t!=nullptr){
    BiNode* next = t->next;
if(t->data % 2 == 0){
    list.insert(t->data + 1,t);
 }
 t = next;
}
cout<<"Вставка чисел перед парних:\n";
list.forward_view();
list.reverse_view();


t = list.front;
while( t!=nullptr){
    BiNode* next = t->next;
if(t->data % 2 != 0){
    list.insert(t, t->data - 1);
 }
 t = next;
}
cout<<"Вставка чисел після непарних:\n";
list.forward_view();
list.reverse_view();

int k;
cout<<"\nВведіть число,кратні якому треба видалити:\n";
cin>>k;

t = list.front;
while ((t != nullptr)){
BiNode* next = t->next;
if(t->data % k == 0){
     list.remove(t);
  }
  t = next;
}

cout<<"Після видалення:\n";
list.forward_view();
list.reverse_view();

//////////////
int x;
cout << "Кількість елементів list1: ";
cin >> n;

    cout << "Введіть list1:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        list1.push_back(x);
    }

    cout << "Кількість елементів list2: ";
    cin >> n;

    cout << "Введіть list2:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        list2.push_back(x);
    }

    cout << "\nПочаткові списки:\n";
    cout << "List1: ";
    list1.forward_view();
    list1.reverse_view();
    cout << "List2: ";
    list2.forward_view();
list2.reverse_view();
    int index;
    cout << "\nВведіть index для splice_in: ";
    cin >> index;

    list1.splice_in(list2.front, index);

    cout << "\nПісля splice_in:\n";
    cout << "List1: ";
    list1.forward_view();
    list1.reverse_view();
    cout << "\nКількість елементів list3: ";
    cin >> n;

    cout << "Введіть list3:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        list3.push_back(x);
    }

    int index1, index2;
    cout << "\nВведіть index1 та index2 для splice_out: ";
    cin >> index1 >> index2;

    list1.splice_out(list3.front, index1, index2);

    cout << "\nПісля splice_out:\n";
    cout << "List1: ";
    list1.forward_view();
list1.reverse_view();
    cout << "List3: ";
    list3.forward_view();
list3.reverse_view();
cout<<":\nЗАВДАННЯ 2\n";
 cout << "\nДо сортування:\n";
list3.forward_view();
list3.reverse_view();
cout << "\nПісля сортування:\n";
list3.sort();
list3.forward_view();
list3.reverse_view();
int ind1,ind2;
cout<<"Введіть індекси для обміну:";
cin>>ind1>>ind2;

BiNode* n1 = list3.front;
BiNode* n2 = list3.front;
for(int i = 0; n1 != nullptr && i<ind1; i++){
    n1 = n1->next;
} 
for(int i = 0; n2 != nullptr && i<ind2; i++){
    n2 = n2->next;
} 
list3.swap(n1,n2);
cout<<"Після обміну: ";
list3.forward_view();
list3.reverse_view();
return 0;
}