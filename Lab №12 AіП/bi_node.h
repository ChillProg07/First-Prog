struct BiNode { 
int data; 
BiNode *prev, *next; 
BiNode () { data = 0; prev = next = nullptr; } 
BiNode (int x) { data = x; prev = next = nullptr; } 
}; 