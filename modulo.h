#ifndef MODULO_H 
#define MODULO_H 
/*
Các phép toán modulo bao gồm: 
+ Cộng 
+ Trừ
+ Nhân 
+ Chia, chia ở đây sẽ là nhân với nghịch đảo của số chia. 
https://gmplib.org/manual/Integer-Functions
*/
#include <gmp.h> 
void mod_add(mpz_t res, const mpz_t a, const mpz_t b,const mpz_t p); // a+b=res mod p
void mod_sub(mpz_t res,const mpz_t a,const mpz_t b, const mpz_t p); // a-b=res mod p
void mod_mul(mpz_t res, const mpz_t a, const mpz_t b, const mpz_t p); // a*b=res mod p 
void mod_neg(mpz_t res, const mpz_t a, const mpz_t p); 

int mod_div(mpz_t res, const mpz_t a, const mpz_t b,const mpz_t p); // a/b mod p = a*b^{-1} mod p 
int mod_inv(mpz_t res, const mpz_t a, const mpz_t p); // res = a^{-1} mod p 
void mod_pow(mpz_t res, const mpz_t a, const mpz_t e, const mpz_t p); 
#endif