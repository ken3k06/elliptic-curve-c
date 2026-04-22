#include <stdio.h> 
#include <stdlib.h> 
#include "modulo.h"

void mod_add(mpz_t res, const mpz_t a, const mpz_t b, const mpz_t p){
    mpz_t tmp; 
    mpz_init(tmp); 
    mpz_add(tmp, a, b); 
    mpz_mod(res, tmp, p); 
    mpz_clear(tmp); 
}

void mod_sub(mpz_t res, const mpz_t a, const mpz_t b, const mpz_t p){
    mpz_t tmp; 
    mpz_init(tmp); 
    mpz_sub(tmp, a,b); 
    mpz_mod(res, tmp , p);
    mpz_clear(tmp); 
}

void mod_mul(mpz_t res, const mpz_t a, const mpz_t b, const mpz_t p){
    mpz_t tmp; 
    mpz_init(tmp); 
    mpz_mul(tmp, a,b); 
    mpz_mod(res,tmp, p );
    mpz_clear(tmp); 
}

void mod_neg(mpz_t res, const mpz_t a, const mpz_t p ){
    mpz_t tmp; 
    mpz_init(tmp); 
    mpz_neg(tmp, a); 
    mpz_mod(res,tmp,p); 
    mpz_clear(tmp); 
}

int mod_inv(mpz_t res, const mpz_t a, const mpz_t p){
    mpz_t tmp; 
    mpz_init(tmp); 
    mpz_mod(tmp, a, p); 
    int num = mpz_invert(res, tmp, p); 
    mpz_clear(tmp); 
    return num;
}

int mod_div(mpz_t res, const mpz_t a, const mpz_t b, const mpz_t p){
    mpz_t inv_b; 
    mpz_init(inv_b); 
    if (mod_inv(inv_b, b, p) == 0){
        mpz_clear(inv_b); 
        return 0; 
    }
    mod_mul(res, a, inv_b, p);
    mpz_clear(inv_b);
    return 1; 
}

int main(int argc, char *argv[]){ 
    printf("argc=%d\n", argc); 

    for (int i = 0 ; i <argc; i++){
        printf("argv[%d]=%s\n", i , argv[i]); 
    }
    return 0;
}

