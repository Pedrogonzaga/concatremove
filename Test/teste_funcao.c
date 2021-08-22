#include <stdio.h>
#include <string.h>

#include "Unity/unity.h"
#include "teste_funcao.h"


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}
/*
Teste da função de filtro de strings a-z
*/
void test_function_filter_string_a_z(void) {
    char string_teste[TAMANHO_PADRAO_STRING];

    memset(string_teste,0x00,TAMANHO_PADRAO_STRING);
    sprintf(string_teste,"Bla BLA abc23 t$%GFDE");
    filter_string_a_z(string_teste);
    TEST_ASSERT_EQUAL_STRING("laabct", string_teste);

    memset(string_teste,0x00,TAMANHO_PADRAO_STRING);
    sprintf(string_teste,"abcdefghijlmnopqrstuvxz");
    filter_string_a_z(string_teste);
    TEST_ASSERT_EQUAL_STRING("abcdefghijlmnopqrstuvxz", string_teste);
}
/*
Teste da função conversão de string
*/
void test_function_ConcatRemove(void) {
    char string_teste[TAMANHO_PADRAO_STRING];

    memset(string_teste,0x00,TAMANHO_PADRAO_STRING);
    sprintf(string_teste,"bla bla bla bla");
    filter_string_a_z(string_teste);
    TEST_ASSERT_EQUAL_STRING("yes", ConcatRemove(string_teste,"blablabcde",8));

    memset(string_teste,0x00,TAMANHO_PADRAO_STRING);
    sprintf(string_teste,"tab");
    filter_string_a_z(string_teste);
    TEST_ASSERT_EQUAL_STRING("yes", ConcatRemove(string_teste,"tab",7));

    memset(string_teste,0x00,TAMANHO_PADRAO_STRING);
    sprintf(string_teste,"asdasdasdas das dasdasd asd asdasdsdgsdfsdfsdfasdasdasdfsdfasdwerwetreyesada");
    filter_string_a_z(string_teste);
    TEST_ASSERT_EQUAL_STRING("no", ConcatRemove(string_teste,"euisasd",70));
}

/*
Teste de limits de tamanho da strings de trabalho nas funções
*/
void test_function_check_size(void){
    char string_teste[500];

    memset(string_teste,0x00,150);

    sprintf(string_teste,"bla bla bla blaaasdhjashdjkahdjkahsjkdasgaskjdgjkagjkgqjkgeqjkgejkgjkgkgdhagsdhafsdhfgdfashfdghasfdasfdafsdfsagdfasfdjasfdjasfdhasdgjksdhfljksdfh");
    TEST_ASSERT_EQUAL_INT(0,filter_string_a_z(string_teste));
    TEST_ASSERT_EQUAL_INT(ERROR_STRING_GRANDE,error);
    error=0;

    TEST_ASSERT_EQUAL_STRING((char *)0x00, ConcatRemove(string_teste,"teste",70));
    TEST_ASSERT_EQUAL_INT(ERROR_STRING_GRANDE,error);

}


// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_filter_string_a_z);
    RUN_TEST(test_function_ConcatRemove);
    RUN_TEST(test_function_check_size);

    return UNITY_END();

}


