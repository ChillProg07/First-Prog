#include <iostream>
#include "bilist.h"
using namespace std;

BiList::BiList(){
   front = nullptr;
}

BiList::~BiList(){
    clear();
}

void BiList::clear() {
    while(front != nullptr) {
        BiNode* t = front;
        front = front->next;
        delete t;
    }
}

BiNode* BiList::get_back(){
    if(front == nullptr)
        return nullptr;

    BiNode* t = front;
    while(t->next != nullptr) {
        t = t->next;
    }
    return t;
}

void BiList::push_back(int x){
    BiNode* t = new BiNode(x);
    if(front == nullptr){
        front = t;
        return;
    }
    BiNode* back = get_back();
    back->next = t;
    t->prev = back;
} 

void BiList::push_front(int x){
BiNode* temp = new BiNode(x);
if(!front)
    front = temp;
    else{
        temp->next = front;
        front ->prev = temp;
        front = temp;
    }
}

void BiList::insert(BiNode* node, int x) {
    if (node == nullptr) return;
    BiNode* temp1 = new BiNode(x);

    temp1->prev = node;
    temp1->next = node->next;

    if (node->next != nullptr) {
        node->next->prev = temp1;
    }
    node->next = temp1;
}

void BiList::insert(int x, BiNode* node) {
    if (node == nullptr) return;
    BiNode* temp1 = new BiNode(x);

    temp1->next = node;
    temp1->prev = node->prev;

    if (node->prev != nullptr) {
        node->prev->next = temp1;
    } else {
        front = temp1;
    }
    node->prev = temp1;
}

void BiList::remove(BiNode* node){
    if(node == nullptr) return;

    if(node->prev != nullptr){
        node->prev->next = node->next;
    }else{
        front = node->next;
    }
    
    if(node->next != nullptr){
        node->next->prev = node->prev;
    }
    delete node;
}

void BiList::forward_view(){
    BiNode* current = front;
    cout<<"Forward list: ";
    while(current != nullptr){
        cout<<current->data<< " ";
            current = current->next;
        }
        cout<<endl;
}

void BiList::reverse_view(){
   BiNode* curr = get_back();
    cout << "Revers list: ";
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

BiNode* BiList::find(int key) {
    BiNode* current = front;
     while(current != nullptr){
        if(current->data == key){
            return current;
        }
        current = current->next;
     }
     return nullptr;
}

void BiList::splice_in(BiNode* list2, int index){
 if(front == nullptr || list2 == nullptr) return;
 BiNode* p = front;  

 for(int i = 0; i<index && p->next != nullptr; i++){
    p = p->next;
 }
 BiNode* after = p ->next;
 BiNode* last2 = list2;
 while (last2->next != nullptr){
    last2 = last2->next;
 }
 p->next = list2;
 list2->prev = p;
 last2->next = after;
 if(after != nullptr){
    after->prev = last2;
 }
}
//////////////////////
void BiList::splice_out(BiNode* list2, int index1, int index2) {
    if (front == nullptr || list2 == nullptr || index1 > index2) {
        cout << "Nothing to move\n";
        return;
    }
    BiNode* first = front;
    for (int i = 0; i < index1 && first != nullptr; i++) {
        first = first->next;
    }

    if (first == nullptr) return;
    BiNode* last = first;

    for (int i = index1; i < index2 && last != nullptr; i++) {
        last = last->next;
    }

    if (last == nullptr) return;
    BiNode* before = first->prev;
    BiNode* after = last->next;

    if (before != nullptr) {
        before->next = after;
    } else {
        front = after;
    }

    if (after != nullptr) {
        after->prev = before;
    }
    first->prev = nullptr;
    last->next = nullptr;

    BiNode* end2 = list2;

    while (end2->next != nullptr) {
        end2 = end2->next;
    }
    end2->next = first;
    first->prev = end2;
}


//////////////
void BiList::swap(BiNode *n1, BiNode *n2){
    if(n1 == nullptr || n2 == nullptr) return;

    int temp =  n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

//за зростанням
void BiList::sort(){
    BiNode* i = front;
     while(i != nullptr){
        BiNode* min = i;
        BiNode* j = i->next;
        while (j!= nullptr){
            if(j->data < min->data){
                min = j;
            }
            j = j->next;
        }
        swap(i,min);
        i = i->next;
     }
}