#include <stdio.h>
#include <string.h>

const int arraySize_Dim1 = 4;
const int arraySize_Dim2 = 5;
char output_str[300];
char tmp_str[5];



void printarray(int array[][arraySize_Dim2], int Dim1, int Dim2)
{
    int i;
    int j;

    for( j = 0; j < Dim1; j++ ) {
        for( i = 0; i < Dim2; i ++) {
            printf( "%8d ", array[j][i] );
        }
        printf("\n");
	}
	printf("-----------------------\n");
}


int main(void)
{
    int i ;
    int j ;
    //initializing regular array and filling in known numbers
    int array[4][5] = 
    {
        {-1,-2,-3,-4,-5},
        {-6},
        {-11},
        {-16}
    };
    int transposeArray[5][4]=
    {
        {-1, -6, -11, -16},
        {-2},
        {-3},
        {-4},
        {-5}
    };
    //filling in remaining elements of array using calculation
    for (i = 1; i < arraySize_Dim2 + 1; i++) {
        for (j=1; j < arraySize_Dim1 + 1; j++) {
            array[i][j] = (array[i-1][j]) * (array[i][j-1]);
        }
    }
    //printing out array to screen
    printf("ORIGINAL ARRAY\n-------------------------------------------------------------\n");
    strcpy(output_str, "    ");
	for (int j = 0; j < arraySize_Dim2; j++) {
		sprintf(tmp_str, "%8d  ", j+1);
		strcat(output_str, tmp_str);
	}
	printf("%s\n", output_str);
	printf("--+----------------------------------------------------------\n");

	for (int i = 0; i < arraySize_Dim1; i++) {
		sprintf(output_str, "%d | ", i+1);
		for (int j = 0; j < arraySize_Dim2; j++) {
        	sprintf(tmp_str, "%8d  ", array[i][j]);
        	strcat(output_str, tmp_str);
    	}
    	printf("%s\n", output_str);
	}
	printf("\n");
    
    //printing out array transpose to screen
    printf("TRANSPOSE OF THE ARRAY A\n-------------------------------------------------------------\n");
    strcpy(output_str, "    ");
	for (int j = 0; j < arraySize_Dim1; j++) {
		sprintf(tmp_str, "%11d  ", j+1);
		strcat(output_str, tmp_str);
	}
	printf("%s\n", output_str);
	printf("--+----------------------------------------------------------\n");

	for (int i = 0; i < arraySize_Dim2; i++) {
		sprintf(output_str, "%d | ", i+1);
		for (int j = 0; j < arraySize_Dim1; j++) {
        	sprintf(tmp_str, "%11d  ", array[j][i]);
        	strcat(output_str, tmp_str);
    	}
    	printf("%s\n", output_str);
	}
	printf("\n");
}
    
