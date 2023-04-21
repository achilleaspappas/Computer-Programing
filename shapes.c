#include <stdio.h>
#include <stdlib.h>

void read_data(int*);
void heisenberg(int*, int);
void name(int*, int);

int main (int argc, char*argv[]) {

    /* Δήλωση μεταβλητών */
    int NumOfRows, ShapeNumber=0;

    /* Δίνουμε αριθμό γραμμών */
    read_data(&NumOfRows);

    /* Δημιουργία Σχημάτων */
    heisenberg(&ShapeNumber, NumOfRows);

    return 0;
}

void read_data(int *NumOfRows) {

    printf("\nΔώσε αριθμό γραμμών: ");
    scanf("%d", NumOfRows);

    return;
}

void heisenberg(int *ShapeNumber, int NumOfRows) {

    /* Δήλωση μεταβλητών */
    int row, star, space, i=1;

    /* Πρώτο Σχήμα -> Όνομα */
    name(ShapeNumber, NumOfRows);

    /* Πρώτο Σχήμα -> Σχήμα */
    for (row=1 ; row<=NumOfRows ; row++)
    {
        for (star=1; star<=row; star++)
        {
            printf("*");
        }
        printf("\n");
    }

    /* Δεύτερο Σχήμα -> Όνομα */
    name(ShapeNumber, NumOfRows);

    /* Δεύτερο Σχήμα -> Σχήμα */
    for (row=1 ; row<=NumOfRows ; row++)
    {
        for (space=NumOfRows-1 ; space>=row ; space--)
        {
            printf(" ");
        }
        
        for (star=1 ; star<=row ; star++)
        {
            printf("*");
        }
        printf("\n");
    
    }
    
    /* Τρίτο Σχήμα -> Όνομα */
    name(ShapeNumber, NumOfRows);

    /* Τρίτο Σχήμα -> Σχήμα */
    for (row=1 ; row<=NumOfRows ; row++)
    {
        for (space=NumOfRows-1 ; space>=row ; space--) 
        {                                              
            printf(" ");
        }
        
        for (star=1 ; star<=((row*2)-1) ; star++)      
        {
            printf("*");
        }
        printf("\n");
        
    }
    
    /* Τέταρτο Σχήμα -> Όνομα */
    name(ShapeNumber, NumOfRows);

    /* Τέταρτο Σχήμα -> Σχήμα */
    for (row=1 ; row<=NumOfRows ; row++)               
    {
        for (star=1 ; star<=NumOfRows ; star++)        
        {
            if (row==1 || row==NumOfRows || star==1 || star==NumOfRows)
            {
                printf ("*");
            }
            else if ( star==row || star==((NumOfRows+1)-i)  )
            {
                printf (".");
            }
            else
            {
                printf (" ");
            }
        }
        i++;
        printf("\n");
    }

    return;
}

void name(int *ShapeNumber, int NumOfRows) {
    int v;
    *ShapeNumber += 1;
    printf("\n\n");
    printf("Σχήμα %d\n", *ShapeNumber);
    for (v=1 ; v<=NumOfRows*2 ; v++)
    {  
        printf("-");
    }
    printf("\n");

    return;
}