#include<stdio.h>
#include<stdlib.h>

//function declaration
void moveDisk(char source, char destination, int disk);
void towerOfHanoi(int numDisks, char source, char temp, char destination);

int main(){
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    towerOfHanoi(numDisks, 'A', 'B', 'C');

    return 0;
}

//function defination
void moveDisk(char source, char destination, int disk) {
    printf("Move disk %d from %c to %c\n", disk, source, destination);
}

void towerOfHanoi(int numDisks, char source, char temp, char destination) {
    if (numDisks == 1) {
        moveDisk(source, destination, 1);
        return;
    }

    towerOfHanoi(numDisks - 1, source, destination, temp);
    moveDisk(source, destination, numDisks);
    towerOfHanoi(numDisks - 1, temp, source, destination);
}