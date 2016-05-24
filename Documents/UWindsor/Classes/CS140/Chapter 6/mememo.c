//
//  mememo.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 99

// function prototypes
void mean(const unsigned int answer[]);
void median(unsigned int answer[]);
void mode(unsigned int freq[], unsigned const int answer[]);
void bubbleSort(unsigned int a[]);
void printArray(unsigned const int a[]);

// calculate the average of all response values
void mean(const unsigned int answer[])
{
    size_t j;
    unsigned int total = 0;
    
    printf("%s\n%s\n%s\n", "**************", "   Mean", "**************");
    
    // total response values
    for(j = 0; j < SIZE; j++)
        total += answer[j];
        
        printf("The mean is the average value of the data\n"
               "items. The mean is equal to the total of\n"
               "all the data items divided by the number\n"
               "of data items (%u). The mean value for\n"
               "this run is %u / %u = %.4f\n\n",
               SIZE, total, SIZE, (double) total / SIZE);
}

void median(unsigned int answer[])
{
    printf("\n%s\n%s\n%s\n%s", "************", "   Median", "************", "The unsorted array of responses is");
    
    printArray(answer);
    bubbleSort(answer);
    
    printf("%s", "\n\nThe sorted array is");
    printArray(answer);
    
    printf("\n\nThe median is element %u of \n"
           "the sorted %u element array.\n"
           "For this run the median is %u\n\n",
           SIZE/2, SIZE, answer[ SIZE / 2 ]);
    
}

void mode (unsigned int freq[], const unsigned int answer[])
{
    size_t rating;          // counter for accessing elements 1-9
    size_t j;               // counter for summerizing elements
    unsigned int h;          // counter for displaying histograms
    unsigned int largest = 0; // represents largest frequency
    unsigned int modeValue = 0;
    int same[2]= {0, 0};
    int key, key2;
    
    
    printf("\n%s\n%s\n%s\n", "***********", "   Mode", "***********");
    
    for (rating = 1; rating <= 9; rating++)
        freq [rating] = 0;
    
    for (j = 0; j < SIZE; j++)
        ++freq [answer[j]];
    
    printf("%s%11s%19s\n\n", "Response", "Frequency", "Histogram");
    
    for (rating = 1; rating <= 9; ++rating){
        printf("%8zu%11u             ", rating, freq[ rating ]);
        
    
        if (freq[rating] > largest) {
            largest = freq[rating];
            modeValue = rating;
        }
    
        for (h = 1; h<= freq[rating]; h++) {
            printf("%s", "*");
        }
            puts("");
    }
    
    for (rating = 1; rating <= 9; rating++){
        if (largest == freq[rating] && key != key2)
            key2 = rating;
        else if (largest == freq[rating] && key == 0)
            key = rating;
    }
    if (key != 0) {
        printf("\nThe mode is the most frequent value.\n"
               "For this run the mode we have a tie, both %u & %u "
               "occur %u times.\n", key, key2, largest);
    }
    else{
    printf("\nThe mode is the most frequent value.\n"
           "For this run the mode is %u which occured"
           " %u times.\n", modeValue, largest);
    }
}
void bubbleSort( unsigned int a[])
{
    unsigned int pass;
    size_t j;
    unsigned int hold;
    
    for (pass = 1; pass < SIZE; pass++) {
        for (j = 0; j < SIZE; j++) {
            if (a[j]> a[j+1]) {
                hold = a[j];
                a[j] = a[j+1];
                a[j +1] = hold;
            }
        }
    }
    
}

void printArray(const unsigned int a[])
{
    size_t j;
    
    for (j = 0; j < SIZE; j++) {
        if (j % 20 == 0) {
            puts("");
        }
        printf("%2u", a[j]);
    }
}

int
main(void)
{
    unsigned int frequency[10] = {0};
    
    unsigned int response [SIZE] = {7, 8, 8, 9,
        5, 5, 7, 6, 4, 2, 3, 4, 7, 8, 3, 3, 2, 6,
        3, 7, 7, 8, 9, 6, 9, 6, 6, 8, 7, 7, 6, 6, 8,
        5, 3, 3, 3, 4, 4, 6, 7, 8, 8, 8, 9, 6, 4, 3, 2,
        3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 5, 6,
        6, 7, 7, 8, 8, 9, 9, 9, 8, 7, 5, 6, 6, 5, 4, 4,
        2, 2, 4, 5, 5, 8};
    mean(response);
    median(response);
    mode(frequency, response);
    
    return 0;
}