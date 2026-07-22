#include <iostream>
#include "p_4_header.hpp"
#include <algorithm>

std::size_t length( char const *a );
int compare( char const *str1, char const *str2 );
void assign( char *str1, char const *str2 );
unsigned int distance( char const *str1, char const *str2 );
std::size_t is_sorted( char *array[], std::size_t capacity );
void insert( char *array[], std::size_t capacity );
void insertion_sort( char *array[], std::size_t capacity );
std::size_t remove_duplicates( char *array[], std::size_t capacity );
std::size_t find( char *array[], std::size_t capacity, char const *str );
void free_word_array( char** word_array );

std::size_t length (char const*a){
    std::size_t counter{0};
    while ((a[counter]) != '\0'){
        counter++;
    }
    return counter;
}

int compare( char const *str1, char const *str2 ){
    for (std::size_t k{0};; k++) {
        if ((str1[k]== '\0') && (str2[k]!= '\0')){
            return -1;
        } else if ((str1[k]!= '\0') && (str2[k]=='\0')){
            return 1;
        } else if ((str1[k]== '\0') && (str2[k]== '\0')){
            return 0;
        } else if (str1[k]<str2[k]){
            return -1;
        } else if (str1[k]>str2[k]){
            return 1;
        }
    }
}

void assign( char *str1, char const *str2 ){
    for (std::size_t k{0};((str2[k] != '\0')); k++){
        str1[k] = str2[k];
        str1[k+1] = '\0';
    }
    
}

unsigned int distance( char const *str1, char const *str2 ){
    if (str1[0] == '\0'){
        int counter = 0;
        for (std::size_t k{}; str2[k] != '\0'; k++){
            counter++;
        }
        return counter;
    }else if (str2[0] == '\0'){
        int counter = 0;
        for (std::size_t k{}; str1[k] != '\0'; k++){
            counter++;
        }
        return counter;
    }else if (str1[0]==str2[0]){
        return distance((str1+1),(str2+1));
    } 
     else if ( str1[0]!=str2[0]){
        unsigned int midmin = (std::min(distance((str1+1),(str2+1)),distance((str1),(str2+1))));
        int finalmin = (std::min(midmin, distance((str1+1),(str2))));
        return finalmin + 1;
    }
    return 999999;
}

std::size_t is_sorted( char *array[], std::size_t capacity ){
    for (std::size_t k{1}; k<capacity; k++){
        if (compare(array[k] , array[k-1]) == -1){
            return k;
        }
    }
    return capacity;
}

void insert( char *array[], std::size_t capacity){
    char holder1[21]{};
    char holder2[21]{};
    for (std::size_t k{0}; k<capacity; k++){
        if (compare(array[k],array[capacity-1])==1){
            assign(holder1,array[k]);
            assign(array[k],array[capacity-1]);
            for (std::size_t p{k+1};p<capacity;p++){
                assign(holder2,array[p]);
                assign(array[p],holder1);
                assign(holder1,holder2);
            }
        }
    }
}

void insertion_sort( char *array[], std::size_t capacity ){
    for (std::size_t k{1};k<=capacity;k++){
        insert(array,k);
    }
}

std::size_t remove_duplicates( char *array[], std::size_t capacity ){
    std::size_t counter{0};
    if (capacity==1){
        return 1;
    }
    for (std::size_t k{0};k<(capacity-1);k++){
        if((compare(array[k+1],array[k]))==0){
            for (std::size_t p{k+1};p<(capacity-1);p++){
                assign(array[p],array[p+1]);
            }
            k--;
            capacity--;
        }else{
            counter++;
        }
    }
    return counter;
}

std::size_t find( char *array[], std::size_t capacity, char const *str ){
    std::size_t low_distance{1000};
    std::size_t close_str{0};
    for (std::size_t k{0}; k<capacity; k++){
        if((compare(array[k],str))==0){
            return k;
        } else {
            if ((low_distance)>distance(array[k],str)){
                close_str = k;
                low_distance  = distance(array[k],str);
            }
        }
    }
    return close_str;
}

void free_word_array( char** word_array ){
    delete[] word_array[0];

    delete[] word_array;
}
