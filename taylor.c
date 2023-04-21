#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_data(double*);
void bohr(double);
double conversion(double);
double sin_passage(double, double, int);
double cos_passage(double, double, int);
double taylor(double, double, int);
void check(double, double, int*);


int main (int argc, char*argv[]) {
    
    /* Δήλωση Μεταβλητών */
    double degree;
    
    /* Εισαγωγή τιμής */
    read_data(&degree);

    /* Μενού */
    bohr(degree);
    
    return 0;
}

void read_data(double *degree) {
    
    printf("------------------------------------------------\n");
    printf("Δώσε την γωνία σε μοίρες: ");
    scanf("%lf", degree);
    return;
}

void bohr(double degree) {

    /* Μετατροπή μοιρών σε ακτίνια */
    double rad = conversion(degree);
    printf("------------------------------------------------\n");
    printf("Τα ακτίνια είναι: %lf\n", rad);

    /* Αποτελέσματα Taylor */
    double sin_sum = sin_passage(rad, rad, 3);
    double cos_sum = cos_passage(rad, 1, 2);
    printf("------------------------------------------------\n");
    printf("\n");
    printf("Το ημίτονο βάση Taylor είναι: %f\n", sin_sum);
    printf("Το συνημίτονο βάση Taylor είναι: %f\n", cos_sum);

    /* Αποτελέσματα Συναρτήσεων */
    double N_sin = sin(rad);
    double N_cos = cos(rad);
    printf("\n------------------------------------------------\n");
    printf("\n");
    printf("Το ημίτονο είναι: %lf\n", N_sin);
    printf("Το συνημίτονο είναι: %lf\n", N_cos);
    printf("\n");

    /* Σύγκριση Αποτελεσμάτων */
    int galileo;

    check(sin_sum, N_sin, &galileo);
    if (galileo) {
        printf("================================================\n\n");
        printf("Τα αποτελέσματα των ημιτόνων είναι ίδια\n");
    }
    else {
        printf("================================================\n\n");
        printf("Τα αποτελέσματα των ημιτόνων δεν είναι ίδια\n");
    }

    check(cos_sum, N_cos, &galileo);
    if (galileo) {
       printf("Τα αποτελέσματα των συνημιτόνων είναι ίδια\n");
       printf("\n================================================\n");
    }
    else {
        printf("Τα αποτελέσματα των συνημιτόνων δεν είναι ίδια\n");
        printf("\n================================================\n");
    }
    return;
}

double conversion(double degree) {
    double rad = (degree*3.14159265359)/180;
    return rad;
}

double sin_passage(double rad, double var1, int var2) {
    double sum = taylor(rad, var1, var2);
    return sum;
}

double cos_passage(double rad, double var1, int var2) {
    double sum = taylor(rad, var1, var2);
    return sum;
}

double taylor(double rad, double var1, int var2) {
    
    /* Δήλωση Μεταβλητών */
    double prev_term = 0;
    double test = 0;
    double term = var1;
    double sum = var1;
    int sign = -1;
    int denom = var2;
 
    /* Υπολογισμός του αναπτύγματος Taylor */
    do {
        prev_term = term;
        term = (prev_term * pow(rad,2)) / (denom*(denom-1));
        denom += 2;
        sum = sum + (term * sign);
        sign *= (-1);
        test = fabs(term - prev_term);

    } while (test>1E-6);

    return sum;
}

void check(double a, double b, int *galileo) {
    
    if ( fabs(a - b) < 1E-6 ) {
        *galileo = 1;
    }
    else {
        *galileo = 0;
    }

    return;
}