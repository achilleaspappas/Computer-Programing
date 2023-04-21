#include <stdio.h>
#include <stdlib.h>

void zeroing(int[]);
void read_data(int*, int[]);
void read_array(int, int[]);
void start_up(int, int[]);
void bubble_sort(int, int[]);
void condition_1(int*, int*);
void condition_2(int*, int*);
void menu(int, int[], int, int, int, int, int[]);
void edison(int, int[],int*, int*, int*, int*, int, int, int, int, int[]);
int merlin_1(int[], int, int, int, int, int, int*, int, int);
int merlin_2(int[], int, int, int, int, int, int*, int, int);
void frequency(int n, int prototype[], int freq[]);

int main (int argc, char*argv[]) {

    /* Δήλωση μεταβλητών */
    int n, x1, x2, y1, y2;
    int prototype[45], freq[46];

    /* Μηδενισμός στοιχείων */
    zeroing(freq);
    
    /* Εισαγωγή δεδομένων */
    read_data(&n, prototype);
    read_array(n, prototype);

    /* Έλεγχος για διπλούς αριθμούς */
    start_up(n, prototype);

    /* Οργάνωση αριθμών κατά αύξουσα σειρά */
    bubble_sort(n, prototype);

    /* Εισαγωγή αριθμών για τις συνθήκες */
    condition_1(&x1, &x2);
    condition_2(&y1, &y2);
    
    /* Μενού */ 
    menu(n, prototype, x1, x2, y1, y2, freq);
    
    return 0;
}

void zeroing(int freq[]) {
    
    for(int i=0; i<46; i++) {
        freq[i]=0;
    }
    return;
}

void read_data(int *n, int prototype[]) {

    system("clear");
    printf("------------------------------------------------------\n");
    printf("Πόσους αριθμούς θα εισάγεις (από 5 μέχρι και 45): ");
    scanf("%d", n);
    if(*n<5 || *n>45) {
        printf("Σφάλμα, αριθμός εκτός ορίων.\n");
        exit(0);
    }
    return;
}

void read_array(int n, int prototype[]) {

    system("clear");
    printf("------------------------------------------------------\n");
    printf("Δώσε %d αριθμούς (με τιμές από 1 έως 45): \n", n);
    for(int i=0; i<n; i++) {
        scanf("%d" ,&prototype[i]);
        if(prototype[i]<1 || prototype[i]>45) {
            printf("\nΣφάλμα, αριθμός εκτός ορίων.\n");
            exit(0);
        }
    }
    return;
}

void start_up(int n, int prototype[]) {
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(prototype[i] == prototype[j]) {
                printf("\nΣφάλμα, βρέθηκαν διπλοί αριθμοί.\n");
                exit(0);
            }
        }
    }    
    return;
}

void bubble_sort(int n, int prototype[]) {
   
    int j,i,temp, sorted;
    for(i=1; i<n; j++) {
        sorted=0;
        for(j=n-1; j>= i; i--){
            if(prototype[j]<prototype[j-1]) {
                temp = prototype[j];
                prototype[j] = prototype[j-1];
                prototype[j-1] = temp;
                sorted = 1;
            }
        }
        if(sorted == 0) {
            return;
        }
    }
}

void condition_1(int *x1, int *x2) {

    system("clear");
    printf("------------------------------------------------------\n");
    printf("Δώσε δύο ακέραιους αριθμόυς από το 0 έως και το 5:\n");
    printf("------------------------------------------------------\n");
    printf("Πρώτος αριθμός: ");
    scanf("%d", x1);
    if(*x1<0 || *x1>5) {
        printf("\nΣφάλμα, αριθμός εκτός ορίων.\n");
        exit(0);
    }
    printf("Δεύτερος αριθμός: ");
    scanf("%d", x2);
    if(*x2<0 || *x2>5) {
        printf("\nΣφάλμα, αριθμός εκτός ορίων.\n");
        exit(0);
    }
    if(*x1>*x2) {
        int h;
        h = *x1;
        *x2 = *x1;
        *x2 = h;
    }

    return;
}

void condition_2(int *y1, int *y2) {

    system("clear");
    printf("------------------------------------------------------\n");
    printf("Δώσε δύο ακέραιους αριθμόυς από το 15 έως και το 215:\n");
    printf("------------------------------------------------------\n");
    printf("Πρώτος αριθμός: ");
    scanf("%d", y1);
    if(*y1<15 || *y1>215) {
        printf("\nΣφάλμα, αριθμός εκτός ορίων.\n");
        exit(0);
    }
    printf("Δεύτερος αριθμός: ");
    scanf("%d", y2);
    if(*y2<*y1 || *y2>215) {
        printf("\nΣφάλμα, αριθμός εκτός ορίων.\n");
        exit(0);
    }
    if(*y1>*y2) {
        int h;
        h = *y1;
        *y2 = *y1;
        *y2 = h;
    }
    return;
}

void menu(int n, int prototype[], int x1, int x2, int y1, int y2, int freq[]) {
    int sum1=0, sum2=0, sum3=0, sum4=0;
    system("clear");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("                             Υπολογισμός Πιθανών Συνδιασμών\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("Οι συνδιασμοί πληρούν τους όρους είναι: \n"); 
    edison(n, prototype, &sum1, &sum2, &sum3, &sum4, x1, x2, y1, y2, freq);
    printf("-----------------------------------------------------------------------------------------\n");
    printf("Το πλήθος των συνδυασμών των %d αριθμών ανά 5 είναι: %d\n", n, sum1);
    printf("Το πλήθος των συνδυασμών που δεν πληρούν τον πρώτο όρο είναι: %d\n", sum2);
    printf("Το πλήθος των συνδυασμών που δεν πληρούν τον δεύτερο όρο είναι: %d\n", sum3);
    printf("Το πλήθος των συνδυασμών που τυπώθηκαν είναι: %d\n", sum4);
    if(sum4 != 0) {
        printf("H συχνότητα εμφάνισης καθένα από τους %d αριθμούς των συνδυασμών που τυπώθηκαν είναι: \n", n);
        printf("=============================\n");
        for(int i=1; i<46; i++){
            if(freq[i] != 0) {
                double res = (double)freq[i]/(double)sum4;
                printf("Η συχνότητα του %d είναι %lf.\n", i, res);
            }
        }
    
        printf("=============================\n");
    }
    else {
        printf("Δεν τυπωθηκαν συνδιασμοί για να βρεθεί η συχνότητα εμφάνισης τους.\n");
    }
    printf("-----------------------------------------------------------------------------------------\n");
    return;
}

void edison(int n, int prototype[], int *sum1, int *sum2, int *sum3, int *sum4, int x1, int x2, int y1, int y2, int freq[]) {

    for(int i=1; i<=n-4; i++) {
        for(int j=i+1; j<=n-3; j++) {
            for(int k=j+1; k<=n-2; k++) {
                for(int l=k+1; l<=n-1; l++) {
                    for(int m=l+1; m<=n; m++) {
                        *sum1 += 1;
                        int check_1 = merlin_1(prototype, i, j, k, l, m, sum2, x1, x2);
                        int check_2 = merlin_2(prototype, i, j, k, l, m, sum3, y1, y2);
                        if(check_1 && check_2) {
                            *sum4 += 1;
                            frequency(n, prototype, freq);
                            printf("%d %d %d %d %d\n", prototype[i], prototype[j], prototype[k], prototype[l], prototype[m]);
                        }
                    }
                }    
            }
        }
    }
    return;
}

int merlin_1(int prototype[], int i, int j, int k, int l, int m, int *sum2, int x1, int x2) {

    int helper = 5 - prototype[i]%2 - prototype[j]%2 - prototype[k]%2 - prototype[l]%2 - prototype[m]%2;
    
    if((helper >= x1) && (helper <= x2)) {
        return 1;
    }
    else {
        *sum2 += 1;
        return 0;
    }
}

int merlin_2(int prototype[], int i, int j, int k, int l, int m, int *sum3, int y1, int y2) {
   
    int helper = prototype[i] + prototype[j] + prototype[k] + prototype[l] + prototype[m];

    if((helper >= y1) && (helper <= y2)) { 
        return 1;
    }
    else {
        *sum3 += 1;
        return 0;
    }
}

void frequency(int n, int prototype[], int freq[]){
    
    for(int i=0; i<n ; i++) {
        for(int j=1; j<46; j++) {
            if(prototype[i]==j) {
                freq[j]++;
                break;
            }
        }
    }
    return;
}