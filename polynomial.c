#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_data(double*, double*, double*);
void newton_1(double, double, double);
void newton_2(double, double);
double solution_1(double, double, double, int);
double solution_2(double, double);
double disc(double, double, double);

int main (int argc, char*argv[]) {

    /* Δήλωση μεταβλητών */
    double a, b, c;    

    /* Εισαγωγή δεδομένων */
    read_data(&a, &b, &c);
    
    /* Έλεγχος μεταβλητών */
    if(a) {
        newton_1(a, b, c); 
    }
    else {
        newton_2(b, c);
    }
    return 0;
}

void read_data(double *a, double *b, double *c) {
    
    printf("-------------------------------------------------------\n");
    printf("Η εξίσωση ενός δευτεροβάθμιου πολυωνύμου είναι:\n");
    printf("            α*(x^2) + β*x + γ = 0\n");
    printf("-------------------------------------------------------\n");

    /* Δίνουμε τις τιμές */
    printf("Δώσε α:  ");
    scanf("%lf", &*a);
    
    printf("Δώσε β:  ");
    scanf("%lf", &*b);
    
    printf("Δώσε γ:  ");
    scanf("%lf", &*c);   

    return;
}

void newton_1(double a, double b, double c) {

    /* Περίπτωση όπου το α δεν είναι 0 */
    printf("-------------------------------------------------------\n");
    printf("Η εξίσωσή σου είναι το δευτεροβάθμιο πολυώνυμο:\n");
    printf("%lf*(x^2) + %lf*x + %lf = 0\n", a, b, c);
    printf("-------------------------------------------------------\n");
    printf("Η διακρίνουσα έχει μορφή: Δ = β^2 - 4*α*γ\n");
    double diak = disc(a, b, c);
    printf("Και η τιμή της είναι Δ = %lf\n", diak);
    printf("-------------------------------------------------------\n");

    /* Έλεγχος διακρίνουσας και εύρεση ριζών */
    if (diak<0.0) {
        printf("Η τιμή της διακρίνουσας είναι αρνητική.\n");
        printf("Άρα η εξίσωση δεν έχει πραγματικές ρίζες.\n");
        printf("-------------------------------------------------------\n");
    }
    else if (diak==0.0) {
        double ro = solution_1(a, b, diak, 0);
        printf("Η τιμή της διακρίνουσας είναι ίση με μηδέν.\n");
        printf("Άρα η πολλαπλή ρίζα είναι x=%lf\n", ro);
        printf("-------------------------------------------------------\n");
    }
    else {
        double ro1 = solution_1(a, b, diak, -1);
        double ro2 = solution_1(a, b, diak, 1);
        printf("Η τιμή της διακρίνουσας είναι θετική.\n");
        printf("Άρα οι ρίζες είναι x1=%lf και x2=%lf\n", ro1 ,ro2);
        printf("-------------------------------------------------------\n");
    }
    return;
}

void newton_2(double b, double c) {

    /* Περίπτωση όπου το α είναι 0 */
    printf("-------------------------------------------------------\n");
    printf("Η εξίσωσή σου είναι το δυώνυμο:\n");
    printf("%lf*x + %lf = 0\n", b, c);
    printf("-------------------------------------------------------\n");

    /* Εύρεση ρίζας του δυωνύομου */
    if(b==0.0) {
        printf("Η εξίσωση είναι αδύνατη.\n");
        printf("-------------------------------------------------------\n");
    }
    else if ( (b != 0.0) && (c == 0.0) ) {
        printf("Η εξίσωση είναι αόριστη.\n");
        printf("-------------------------------------------------------\n");
    }
    else {
        double res = solution_2(b ,c);
        printf("Η λύση είναι: %lf\n", res);
        printf("-------------------------------------------------------\n");
    }   
    return;
}

double solution_1(double a, double b, double diak, int sign) {
    
    double ro = (-b + ( sign*sqrt(diak) ) ) / (2*a);
    return ro; 
}

double solution_2(double b, double c) {

    double res = -c/b;
    return res;
}

double disc(double a, double b, double c) {

    double res = pow(b,2)-(4*a*c);
    return res;
}