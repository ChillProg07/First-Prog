#include "bi_node.h"

class BiList{
public:
 BiNode *front;
 BiList(); 
~BiList(); 
void clear (); 
BiNode* get_back(); 
void push_back (int x); 
void push_front (int x); 
void insert (int x, BiNode* node); 
void insert (BiNode* node, int x); 
void remove (BiNode* node); 
void forward_view(); 
void reverse_view(); 
BiNode* find(int key); 
void splice_in(BiNode* list2, int index);
void splice_out(BiNode* list2, int index1, int index2);
void swap(BiNode* n1, BiNode* n2);
void sort();
};