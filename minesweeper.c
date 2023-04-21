#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void read_data(int*, int*, int*);
void zeroing(int, int, char[][100]);
void seed(int, int, char[][100], int);
void planck(int, int, char [][100], int, int);
void display(int, int, char [][100]);
void helper(int);

int main(int argc, char*argv[]){

    /* Δήλωση μεταβλητών και πίνακα */
    /* bombs=B, lines=M, columns=N */
    int lines, columns, bombs;
    char p[100][100];

    /* Εισαγωγή δεδομένων */ 
    read_data(&bombs, &lines, &columns);

    /* Μηδενίζω τα στοιχεία του πίνακα */
    zeroing(lines, columns, p);

    /* Τοποθέτηση βομβών */
    seed(lines, columns, p, bombs);

    /* Εμφάνιση Πίνακα */
    display(lines, columns, p);

    return 0;
}

void read_data(int *bombs, int *lines, int *columns) {

    printf("-----------------------\n");
    printf("Δώσε αριθμό βομβών: ");
    scanf("%d", bombs);

    printf("Δώσε αριθμό γραμμών: ");
    scanf("%d", lines);

    printf("Δώσε αριθμό στηλών: ");
    scanf("%d", columns);
    printf("-----------------------\n");

    return;
}

void zeroing(int lines, int columns, char p[][100]) {

    for (int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            p[i][j]=0;
        }
    }

    return;
}

void seed(int lines, int columns, char p[][100], int bombs) {

    /* Παραγωγή τυχαίων αριθμών και τοποθέτηση βόμβας */
    srand(time(0));

    for (int i = 0; i < bombs; ) { 
        int num1 = (rand() % ((lines-1) - 0 + 1)) + 0; 
        int num2 = (rand() % ((columns-1) - 0 + 1)) + 0; 
 
        if ( p[num1][num2] == 0) {
            p[num1][num2] = 'B' ; 
            i++;

            /* Με πόσες βόμβες συνορεύει */
            planck(lines, columns, p, num1, num2);
        }
    }

    return;
}

void planck(int lines, int columns, char p[][100], int num1, int num2) {
    
    /* Βοηθητικές μεταβλητές */
    int n1=-1,n2=-1; 
	for (n1=-1; n1<=1; n1++) {

        for (n2=-1; n2<=1; n2++) {

		    if(num1+n1>=0 && num1+n1<lines && num2+n2>=0 && 
               num2+n2<columns && p[num1+n1][num2+n2]!= 'B') {
			    
                p[num1+n1][num2+n2]+=1;
			}
		}
    }
   
    return;
}
 
void display(int lines, int columns, char p[][100]) {

    system("clear");
    printf(" ");
    helper(columns);
    printf(" Ναρκαλιευτής\n ");
    helper(columns);

    for (int i=0; i<lines; i++) {

        for(int j=0; j<columns; j++) {
            printf(" | ");
            if( p[i][j] == 'B') {
                printf("%c", p[i][j]);
            }
            else {
                printf("%d", p[i][j]);
            }
        }
        printf(" | \n ");
        helper(columns);
    }
    
    printf("\n");
    return;
}

void helper(int columns) {

    for(int i=0; i<columns; i++){
        printf("----");
    }
    printf("-\n");
    return;
}