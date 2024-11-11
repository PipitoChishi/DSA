 Write a recursive algorithm for solving the Tower of Hanoi problem. Given N disks, move all the disks
from the source rod (from_rod) to the destination rod (to_rod) using an auxiliary rod (aux_rod). The rules are:
1.Only one disk can be moved at a time.
2.A larger disk cannot be placed on top of a smaller disk.

Algorithm:
The Tower of Hanoi algorithm uses a recursive approach to move disks from the source rod to the destination rod.
    
Base Case:
If n == 0, return without any operation (no disk to move).

Recursive Case:
Move n-1 disks from the from_rod to the aux_rod using the to_rod as an auxiliary.
Move the nth disk from the from_rod to the to_rod.
Move the n-1 disks from the aux_rod to the to_rod using the from_rod as an auxiliary.

Output the Move:
Print each move that transfers a disk from one rod to another.

#include<iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod,  char to_rod,  char aux_rod)
{
    if (n == 0){
    return;
}
towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
cout << "move disk" << n << "from rod" << from_rod << "to rod" << to_rod << endl;
towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
int main()
{
    int N=3;
    towerOfHanoi(N,'A','C','B');
    return 0;
}
 
