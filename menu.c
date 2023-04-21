#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_data(int*, int*);
void menu(int, int, int*, int*, int*);
void function1(int, int, int*);
void function2(int, int, int*);
void function3(int, int, int*);
void termination(int, int, int);
int calc_pow(int, int);
int factorial(int);
int faraday(int, int);

int main (int argc, char*argv[]) {
    
    /* Δήλωση μεταβλητών */
    int a, b, sum1, sum2, sum3;
    
    /* Εισαγωγή ακέραιων αριθμών*/  
    read_data(&a, &b);

    /* Μενού */
    menu(a, b, &sum1, &sum2, &sum3);

    /* Πόσες φορές ο χρήστης πάτησε κάθε επιλογή */
    termination(sum1, sum2, sum3);

    return 0; 
}

void read_data(int *a, int *b) {
    printf("======================================================\n");
    printf("Δώσε πρώτο ακέραιο αριθμό (Α): ");
    scanf("%d", a);
    printf("Δώσε δεύτερο ακέραιο αριθμό (Β): ");
    scanf("%d", b);
    return;
}

void menu(int a, int b, int *sum1, int *sum2, int *sum3) {
    
    int option;

    do {
        system("clear");
        printf("------------------------------------------------------\n");
        printf("Πληκτρολόγησε τον κατάλληλο αριθμό\n");
        printf("------------------------------------------------------\n");
        printf("1 -> Υπολογισμός της δύναμης Α^Β\n");
        printf("2 -> Υπολογισμός του Α! και του Β!\n");
        printf("3 -> Υπολογισμός του πλήθους των συνδυασμών Α ανά Β\n");
        printf("4 -> Τερματισμός προγράμματος\n");
        printf("---> ");
        scanf("%d", &option);
    
        switch (option) {
            case 1: function1(a, b, sum1);
                    break;
            case 2: function2(a, b, sum2);
                    break;
            case 3: function3(a, b, sum3);
                    break;
        }
    } while (option != 4);
    return;
}

void function1(int a, int b, int *sum1) {
    
    *sum1 += 1;
    system("clear");
    printf("------------------------------------------------------\n");
    printf("            Υπολογισμός της δύναμης Α^Β\n");
    printf("------------------------------------------------------\n");
    int res = calc_pow(a,b);
    printf("Το αποτέλεσμα είναι: %d\n", res);
    printf("\nΠατήστε <Enter> για συνέχεια\n");
    
    getchar();
    char c;
    scanf("%c", &c);
    return;
}

int calc_pow(int a, int b) {

    int res = 1;
    for(int i=1; i<=b; i++) 
        res *= a;
    return res;
}

void function2(int a, int b, int *sum2) { 

    *sum2 += 1;
    system("clear");
    printf("------------------------------------------------------\n");
    printf("           Υπολογισμός του Α! και του Β!\n");
    printf("------------------------------------------------------\n");
    if( !(a<0) ) {
        int res1 = factorial(a);
        printf("Το παραγοντικό του Α είναι: %d\n", res1);
    }
    else 
        printf("Το παραγοντικό του Α δεν μπορεί να υπολογιστεί");

    if(! (b<0) ) {
        int res2 = factorial(b);
        printf("Το παραγοντικό του Β είναι: %d\n", res2);
    }
    else 
        printf("Το παραγοντικό του Β δεν μπορεί να υπολογιστεί");
    
    printf("\nΠατήστε <Enter> για συνέχεια\n");
    getchar();
    char c;
    scanf("%c", &c);
    return;
}

int factorial(int n) {

    int fact = 1;
    for(int i=1; i<=n; i++)
        fact *= i;
    return fact;
}

/* Εναλλακτικός τρόπος
int factorial(int temp) {

    if (temp==0) {
        return 1;
    }
    else {
        return temp*factorial(temp-1);
    }
} */

void function3(int a, int b, int *sum3) {
    
    *sum3 += 1;
    system("clear");
    printf("------------------------------------------------------\n");
    printf("   Υπολογισμός του πλήθους των συνδυασμών Α ανά Β\n");
    printf("------------------------------------------------------\n");
    if (a<0 || b<0 || a<b) {
        printf("Το πλήθος δεν μπορεί να υπολογιστεί\n");
        
        printf("\nΠατήστε <Enter> για συνέχεια\n");
        getchar();
        char c;
        scanf("%c", &c);
        return;
    }
    else {
        int res = faraday(a,b);
        printf("Το πλήθος είναι: %d\n", res);
    }
    printf("\nΠατήστε <Enter> για συνέχεια\n");
    getchar();
    char c;
    scanf("%c", &c);
    return;
}        

int faraday(int a, int b) {

    int n = factorial(a);
    int k = factorial(b);
    int sum = factorial(a-b);
    int res = n/(k*sum);
    return res;
}

void termination(int sum1, int sum2, int sum3) {

    system("clear");
    printf("------------------------------------------------------\n");
    printf("Πρόγραμμα τερματίστηκε\n");
    printf("Η επιλογή 1 πατήθηκε %d φορές\n", sum1);
    printf("Η επιλογή 2 πατήθηκε %d φορές\n", sum2);
    printf("Η επιλογή 3 πατήθηκε %d φορές\n", sum3);
    printf("------------------------------------------------------\n");
    return;
}