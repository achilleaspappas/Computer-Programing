#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct point {
    float x, y;
};

struct rectangle {
    struct point top_left, bottom_right;
    char color[6];
};

struct rectangle * read_file(struct rectangle *p, int*);
void changeColor(char[]);
void menu(int*, struct rectangle *p);
void combinations(struct rectangle *p, int*, char[]);
int intersection(struct rectangle *s1, struct rectangle *s2);
void optionTwo(struct rectangle *p, char[], int*);
int *max_area(struct rectangle *p, char[], int*);
void optionThree(struct rectangle *p, char[], int *n);
int *max_perim(struct rectangle *p, char[], int*);
int *master(struct rectangle *p, char[], int*, int, int);
void bubbleSort(float value[], int[], int*);

int main(int argc, char *argv[]) {
    
    int n;
    struct rectangle *p = read_file(p, &n);      
    menu(&n, p);

    return 0;
}

struct rectangle * read_file(struct rectangle *p, int *n) {
    
    char temp[20];

    /* Άνοιγμα αρχείου*/
    FILE *fp;
    fp = fopen("data.txt","r");

    /* Έλεγχος αρχείου */
    if (fp==NULL) {
	    printf("Error: File can not be opened.\n");		    
        exit(0);
    }

    /* Αριθμός στοιχείων */
    fscanf(fp,"%s %d",temp, n);
    p = (struct rectangle*)malloc((*n)* sizeof(struct rectangle));
    
    for(int i=0; i<*n; i++) {
        
        fscanf(fp, "%f %f %f %f %s", &p[i].top_left.x, &p[i].top_left.y, 
                &p[i].bottom_right.x, &p[i].bottom_right.y, p[i].color);        
    }
    /* Κλείνω το αρχείο */
    fclose(fp);
    return p;
}

void menu(int *n, struct rectangle *p) {

    char temp[5], tempColor[6];
    do {
        changeColor(tempColor);
        system("clear");
        printf("----------------------------------------------------------\n");
        printf("                   Διάλεξε μια ενέργεια\n");
        printf("----------------------------------------------------------\n");
        printf("a -> Τομή\n");
        printf("b -> Μέγιστο εμβαδόν\n");
        printf("c -> Μέγιστη περίμετρος\n");
        printf("STOP -> Για τερματισμό του προγράμματος\n");
        printf("----------------------------------------------------------\n");
        printf("---> ");
        scanf("%s", temp);

        if ( strcmp(temp,"a") == 0 ) 
            combinations(p, n, tempColor);
        else if ( strcmp(temp,"b") == 0 )
            optionTwo(p, tempColor, n);
        else if ( strcmp(temp,"c") == 0 )
            optionThree(p, tempColor, n);   
            
    } while( strcmp(temp, "STOP")!=0 );

    /* Αποδεσμεύουμε την μνήμη */
    free(p); 
    printf("----------------------------------------------------------\n");
    printf("               Πρόγραμμα τερματίστηκε\n");
    printf("----------------------------------------------------------\n");
    return;
}

void changeColor(char tempColor[]) {
    
    do {
        system("clear");
        printf("----------------------------------------------------------\n");
        printf("                     Διάλεξε χρώμα\n");
        printf("----------------------------------------------------------\n");
        printf("red -> Για κόκκινο\n");
        printf("green -> Για πράσινο\n");
        printf("blue -> Για μπλέ\n");
        printf("----------------------------------------------------------\n");
        printf("---> ");
        scanf("%s", tempColor);

    } while( strcmp(tempColor,"red")!=0 & strcmp(tempColor,"green")!=0 && strcmp(tempColor,"blue")!=0 );
    return;
}

void combinations(struct rectangle *p, int *n, char tempColor[]) {
    
    /* Αντιγράφουμε τις δομές */
    struct rectangle *s1 = (struct rectangle *)malloc(sizeof(struct rectangle));
    struct rectangle *s2 = (struct rectangle *)malloc(sizeof(struct rectangle));

   for(int i=1; i<=*n-1; i++) {
        for(int j=i+1; j<*n; j++) {
           if( strcmp(tempColor, p[i].color)==0 && strcmp(tempColor, p[j].color)==0){    
            s1->top_left.x = p[i].top_left.x;
            s1->top_left.y = p[i].top_left.y;
            s1->bottom_right.x = p[i].bottom_right.x;
            s1->bottom_right.y = p[i].bottom_right.y;
            s2->top_left.x = p[j].top_left.x;
            s2->top_left.y = p[j].top_left.y;
            s2->bottom_right.x = p[j].bottom_right.x;
            s2->bottom_right.y = p[j].bottom_right.y;
            int Num = intersection(s1, s2);
            printf("Επιστράφηκε %d. Η τομή έχει τις συντεταγμένες (%f,%f) και (%f,%f)\n", Num, s1->top_left.x, s1->top_left.y, s1->bottom_right.x, s1->bottom_right.y);
            }
        }
    }
    /* Αποδεσμεύουμε την μνήμη */
    free(s1);
    free(s2);

    char temp[2];
    do {
        printf("Πίεσε r για συνέχεια --> ");
        scanf("%s", temp);
    }while( strcmp(temp,"r")!=0 );
    return;
} 

int intersection(struct rectangle *s1, struct rectangle *s2) {
    
    /* Εύρεση τομών */
    float x1 = s1->top_left.x;
    float y1 = s1->top_left.y;
    float x2 = s1->bottom_right.x;
    float y2 = s1->bottom_right.y;
    float x3 = s2->top_left.x;
    float y3 = s2->top_left.y;
    float x4 = s2->bottom_right.x;
    float y4 = s2->bottom_right.y;

    /* Έλεγχος αν υπάρχει τομή */
    if( (x1>x4 && x2>x3) || (y1<y4 && y3<y2) ) {
        s1->top_left.x = 0;
        s1->top_left.y = 0;
        s1->bottom_right.x = 0;
        s1->bottom_right.y = 0;
        return 0;
    }

    /* Έφοσον υπάρχει γίνεται εύρεση της */
    if(x1-x3<0) {
        if(y1-y3<0) {
            s1->top_left.x = x3;
            s1->top_left.y = y1;
        }
        else if(y1-y3>0) {
            s1->top_left.x = x3;
            s1->top_left.y = y3;
        }
        else if(y1-y3==0) {
            s1->top_left.x = x3;
            s1->top_left.y = y3;
        }
    }
    else if(x1-x3>0) {
        if(y1-y3<0) {
            s1->top_left.x = x1;
            s1->top_left.y = y1;
        }
        else if(y1-y3>0) {
            s1->top_left.x = x1;
            s1->top_left.y = y3;
        }
        else if(y1-y3==0) {
            s1->top_left.x = x1;
            s1->top_left.y = y1;
        }
    }
    else if(x1-x3==0) {
        if(y1-y3<0) {
            s1->top_left.x = x1;
            s1->top_left.y = y1;
        }
        else if(y1-y3>0) {
            s1->top_left.x = x3;
            s1->top_left.y = y3;
        }
        else if(y1-y3==0) {
            s1->top_left.x = x1;
            s1->top_left.y = y1;
        }
    }    

    if(x2-x4<0) {
        if(y2-y4>0) {
            s1->bottom_right.x = x2;
            s1->bottom_right.y = y4;
        }
        else if(y2-y4>0) {
            s1->bottom_right.x = x2;
            s1->bottom_right.y = y2;
        }
        else if(y2-y4==0) {
            s1->bottom_right.x = x2;
            s1->bottom_right.y = y2;
        }
    }
    else if(x2-x4>0) {
        if(y2-y4>0) {
            s1->bottom_right.x = x4;
            s1->bottom_right.y = y4;
        }
        else if(y2-y4>0) {
            s1->bottom_right.x = x4;
            s1->bottom_right.y = y2;
        }
        else if(y2-y4==0) {
            s1->bottom_right.x = x4;
            s1->bottom_right.y = y4;
        }
    }
    else if(x2-x4==0) {
        if(y2-y4>0) {
            s1->bottom_right.x = x4;
            s1->bottom_right.y = y4;
        }
        else if(y2-y4>0) {
            s1->bottom_right.x = x2;
            s1->bottom_right.y = y2;
        }
        else if(y2-y4==0) {
            s1->bottom_right.x = x2;
            s1->bottom_right.y = y2;
        }
    }

    return 1;
}

void optionTwo(struct rectangle *p, char tempColor[], int *n) {
    
    int *position = max_area(p, tempColor, n);

    printf("----------------------------------------------------------\n");
    printf("Το ορθογώνιο με το μεγαλύτερο εμβαδόν χρώματος %s\n", tempColor);
    printf("βρίσκεται στην/στις θέση/θέσεις ");
    int i=0;
    do {    
        printf("%d  ", position[i]);
        i++;
    }while(position[i-1]==position[i]);
    printf("\n----------------------------------------------------------\n");
    free(position);
    char temp[2];
    do {
        printf("Πίεσε r για συνέχεια --> ");
        scanf("%s", temp);
    } while( strcmp(temp,"r")!=0 );
    return;
}

int *max_area(struct rectangle *p, char tempColor[], int *n) {
    
    int *position = master(p, tempColor, n, 0, 1);
    return position;
}

void optionThree(struct rectangle *p, char tempColor[], int *n) {

    int *position = max_perim(p, tempColor, n);
    printf("----------------------------------------------------------\n");
    printf("Το ορθογώνιο με την μεγαλύτερη περίμετρο χρώματος %s\n", tempColor);
    printf("βρίσκεται στην/στις θέση/θέσεις ");
    int i=0;
    do {    
        printf("%d  ", position[i]);
        i++;
    }while(position[i-1]==position[i]);
    printf("\n----------------------------------------------------------\n");
    free(position);
    char temp[2];
    do {
        printf("Πίεσε r για συνέχεια --> ");
        scanf("%s", temp);
    } while( strcmp(temp,"r")!=0 );
    return;
}

int *max_perim(struct rectangle *p, char tempColor[], int *n) {

    int *position = master(p, tempColor, n, 2, 0);
    return position;
}

int *master(struct rectangle *p, char tempColor[], int *n, int a, int b) {
    
    int *position=(int *)malloc((*n) * sizeof(int));
    float *value=(float *)malloc((*n) * sizeof(float));
    int j=0,i;
    for (i=0; i<*n; i++) {
        if( strcmp(tempColor,p[i].color)==0 )  {
            float v1= fabs(p[i].bottom_right.x - p[i].top_left.x);
            float v2= fabs(p[i].top_left.y - p[i].bottom_right.y);
            float temp = ( a*(v1+v2) ) + ( b*(v1*v2) );
            value[i]=temp;
            position[i]=i;
        }
    }
  
    bubbleSort(value, position, n);

    int *check=(int *)malloc((*n) * sizeof(int));
    j=0;
    i=*n-1;
    do {
        check[j]=position[i];
        j++;
        i--;
    } while(value[i]==value[i-1]);

    free(position);
    free(value);
    return check;
}

void bubbleSort(float value[], int position[], int *n) {

    int i,j;
    float temp;

    for (j=1;j<*n;j++){
		for(i=0;i<*n-j;i++){
			if(value[i]>=value[i+1]){
				temp=value[i+1];
				value[i+1]=value[i];
				value[i]=temp;
                
				temp=position[i+1];
				position[i+1]=position[i];
				position[i]=temp;
			}
		}
	}
    return;
}