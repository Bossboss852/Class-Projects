#include <iostream>
#include <cassert>

int main();
void pattern(unsigned int n);
unsigned int log10( unsigned int n );
unsigned int count( unsigned int n, unsigned int bit );
unsigned int swap_bytes( unsigned int n, unsigned int b0, unsigned int b1 );

int main(){
    /* int astamount{0};
    std::cout << "enter a number";
    std::cin >> astamount;
    pattern(astamount); */
    int input_for_log{0};
    std::cout << "enter a number";
    std::cin >> input_for_log;
    int returned = log10(input_for_log);
    std::cout << returned;
/*     unsigned int input_for_count{0};
    int input_for_bit{0};
    std::cout << "enter a number";
    std::cin >> input_for_count;
    std::cout << "enter a bit";
    std::cin >> input_for_bit;
    std::cout << count(input_for_count, input_for_bit); */
/*     int input_for_b1{0};
    int input_for_b0{0};
    int input_for_n{0};
    std::cout << "enter a byte you want to shift";
    std::cin >> input_for_b1;
    std::cout << "another";
    std::cin >> input_for_b0;
    std::cout << "enter a number";
    std::cin >> input_for_n;
    std::cout << swap_bytes(input_for_n, input_for_b0, input_for_b1);
    return 0; */
    return 0;
}

void pattern(unsigned int n){
    long new_n = n;
    int j{0};
    for (int k{0}; k<((new_n)+1); k++){
        for (int z(0); z < (k); z++){
            std::cout << " ";
        }
        for (int l{j}; l<((2*new_n)+1); l++){
            std::cout << "*";
        }
        for (int z(0); z < (k); z++){
            std::cout << " ";
        }
        j+=2;
        std::cout << std::endl;
    }
    int t{((int)new_n)-1};
    int v{3};
    for (int k{0}; k<(new_n); k++){
        for (int p{t}; p>0; p--){
            std::cout << " "; 
        }
        for (int p{0}; p<v; p++){
            std::cout << "*";
        }
        for (int p{t}; p>0; p--){
            std::cout << " "; 
        }
        std::cout << std::endl;
        t--;
        v+=2;
    }
}
unsigned int log10( unsigned int n ){
    long new_n = n;
    if (n==0){
        std::abort();
    }
    unsigned int power_10{0};
    long largest_int{1};
    while (largest_int<=new_n){
        largest_int *=10;
        power_10++;
    }
    return power_10-1;
}
unsigned int count( unsigned int n, unsigned int bit ){
    long new_n = n;
    assert(bit == 1 || bit == 0);
    int biggest_power{31};
    int one_amount{0};
    while (biggest_power>=0){
        int long subtract_num{1};
        for (int k{biggest_power}; k>0; k--){
            subtract_num *= 2;
        }
        if (((int long)new_n-subtract_num)>=0){
            one_amount++;
            new_n = new_n-subtract_num;
        }
        biggest_power--;
    } 
    if (bit == 1){
        }else if (bit == 0){
            one_amount = 32 - one_amount;
        }        
    return one_amount;
}
unsigned int swap_bytes( unsigned int n, unsigned int b0, unsigned int b1 ){
    long long new_n = n;
    unsigned int long byete= 0b00000000000000000000000000000000;
    int biggest_power{31};
    unsigned int long byete3= 0b00000000000000000000000000000000;
    unsigned int long byete2= 0b00000000000000000000000000000000;
    unsigned int long byete1= 0b00000000000000000000000000000000;
    unsigned int long byete0= 0b00000000000000000000000000000000;
    // so ore all you need to do is just take the first 8 bits and then assign them to byte3, and then so on for the rest of the bits
    while (biggest_power>=0){
        assert(b0 == 0 || b0 == 1 || b0 == 2 || b0 == 3);
        assert(b1 == 0 || b1 == 1 || b1 == 2 || b1 == 3);

        unsigned int long current_byete =0b00000000000000000000000000000000;
        long long subtract_num{1};
        for (int k{biggest_power}; k>0; k--){
            subtract_num *= 2;
        }
        
        if ((new_n-subtract_num)>=0){
            new_n = new_n-subtract_num;
            current_byete = 0b00000000000000000000000000000001;
            current_byete = (current_byete << biggest_power);
        }else{
            current_byete = 0b00000000000000000000000000000000;
        }
        if (biggest_power > 23){
            byete3 |= current_byete;
/*             std::cout << byete3; */
        }else if ((16 <= biggest_power) && (biggest_power <= 23)){
            byete2 |= current_byete;
/*             std::cout << byete2; */
        } else if ((8 <= biggest_power) && (biggest_power <= 15)){
            byete1 |= current_byete;
/*             std::cout << byete1; */
        } else if ((0 <= biggest_power) && (biggest_power <= 7)){
            byete0 |= current_byete;
/*             std::cout << byete0; */
        }
        biggest_power--;
        // here you will just use or in specific ways to add the bytes together to make the full number
        // holy this is a tweaky function
    } 

    if ((b0 == 0 && b1 == 1) || (b0 == 1 && b1 == 0)){
        byete0 = (byete0 << 8);
        byete1 = (byete1 >> 8);
        byete |= byete0;
        byete |= byete1;
        byete |= byete2;
        byete |= byete3;
    } else if ((b0 == 0 && b1 == 2) || (b0 == 2 && b1 == 0)){
        byete0 = (byete0 << 16);
        byete2 = (byete2 >> 16);
        byete |= byete0;
        byete |= byete1;
        byete |= byete2;
        byete |= byete3;
    } else if ((b0 == 0 && b1 == 3) || (b0 == 3 && b1 == 0)){
        byete0 = (byete0 << 24);
        byete3 = (byete3 >> 24);
        byete |= byete0;
        byete |= byete1;
        byete |= byete2;
        byete |= byete3;
    } else if ((b0 == 1 && b1 == 2) || (b0 == 2 && b1 == 1)){
        byete1 = (byete1 << 8);
        byete2 = (byete2 >> 8);    
        byete |= byete0;
        byete |= byete1;
        byete |= byete2;
        byete |= byete3;
    }else if ((b0 == 1 && b1 == 3) || (b0 == 3 && b1 == 1)){
        byete1 = (byete1 << 16);
        byete3 = (byete3 >> 16);  
        byete |= byete0;
        byete |= byete1;
        byete |= byete2;
        byete |= byete3;
    }else if ((b0 == 2 && b1 == 3) || (b0 == 3 && b1 == 2)){
        byete2 = (byete2 << 8);
        byete3 = (byete3 >> 8);  
        byete |= byete0;
        byete |= byete1;
        byete |= byete2;
        byete |= byete3;
    }else{
        byete |= byete0;
        byete |= byete1;
        byete |= byete2;
        byete |= byete3;
    }
    return byete;
}