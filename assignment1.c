//Name - Sricharan Kidambi
//References - Used Abijith AnadhaKrishnan's Test Values to test against my production code
//Date : 01/19/2022
//Asked assistance from TA's and professors

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

int nb(uint32_t num){
    int pos = 0;
    if(num >= 0){
    while(num != 0){
        pos++;
        num = num >> 1;
    }
    }
    return pos;
}
int uint_to_binstr(char *str, size_t size,uint32_t num, uint8_t nbits){
    if(str == NULL){
        return -1;
    }
    if((nbits < nb(num))||(size < nbits + 3)){
        *str = '\0';
        return -1;
    }
    else if(nbits > 32){
        *str = '\0';
        return -1;
    }
    else{
    int i;
    str[0] = '0';
    str[1] = 'b';
    for(i=nbits+1;i >= 2;i--){
       if((num & 1) == 1){
            str[i] = '1';
        }
        else{
            str[i] = '0';
        }
        num = num >> 1;
      }
    }
    str[nbits + 2] = '\0';
    return nbits + 2;
}

uint32_t test_uint_to_binstr(){
    uint32_t p1,p2,p3,p4,p5,n1,n2,n3,n4;
    char str[1024];
    //Accepted Entries
    p1 = uint_to_binstr(str,11,18,8);//Given working case - 1
    p2 = uint_to_binstr(str,19,65400,16);//Given working case - 2
    p3 = uint_to_binstr(str,11,255,8); // Handling the max 8bit value
    p4 = uint_to_binstr(str,19,65535,16); //Handling the max 16bit value
    p5 = uint_to_binstr(str,40,4294967295,32); //Handling the max 32bit value
    //Denied Entries
    n1 = uint_to_binstr(NULL,19,65400,16);//String is NULL
    n2 = uint_to_binstr(str,10,310,0); //Illegal Nbits - Given Negative Case - 1
    n3 = uint_to_binstr(str,10,310,4);//310 cannot be accomodated in 4 bits. - Given Negative Case - 2
    n4 = uint_to_binstr(str,11,310,9);//even though 310 can be handled in 9 bits, size must be greater than nbits by 3 to allocate 0,x and '\0'.

    if((p1 == 10)&&(p2 == 18)&&(p3 == 10)&&
       (p4 == 18)&&(p5 == 34)&&(n1 == -1)&&(n2 == -1)&&(n3 == -1)&&
       (n4 == -1)){
        return 1;
    }
    else{
        return 0;
    }
}
//--------------------------------Q2-Production---------------------------------------------
int int_to_binstr(char *str, size_t size,int32_t num, uint8_t nbits){
    if(str == NULL){
        return -1;
    }
    if(num < 0){
        num += (1 << nbits);
    }
    if((nbits < nb(num))||(size < nbits + 3)){
        str = '\0';
        return -1;
    }
    if(nbits > 32){
        str = '\0';
        return -1;
    }
    else{
    int i;
    str[0] = '0';
    str[1] = 'b';
    for(i = nbits+1;i >= 2;i--){
       if((num & 1) == 1){
            str[i] = '1';
        }
        else{
            str[i] = '0';
        }
        num = num >> 1;
      }
    str[nbits + 2] = '\0';
    }
    return nbits + 2;
}
//--------------------------------Q2-Test---------------------------------------------
uint32_t test_int_to_binstr(){
    uint32_t test1,test2,test3,test4,test5,test6,test7,test8,test9,test10,test11,test12,test13,test14,test15,test16;
    char str[1024];
//Positive cases
    test1 = int_to_binstr(str,11,127,8);            //extreme case for 8 bits
    test2 = int_to_binstr(str,11,-128,8);           //extreme case for 8 bits
    test3 = int_to_binstr(str,19,32767,16);         //extreme case for 16 bits
    test4 = int_to_binstr(str,19,-32768,16);        //extreme case for 16 bits
    test5 = int_to_binstr(str,4,1,1);               //extreme case for 1 bit
    test6 = int_to_binstr(str,4,-1,1);              //extreme case for 1 bit
    test7 = int_to_binstr(str,40,2147483647,32);    //extreme case of uint32_t input
    test8 = int_to_binstr(str,40,-2147483648,32);   //extreme case of uint32_t input
    test9 = int_to_binstr(str,11,18,8);             //given cases
    test10 = int_to_binstr(str,7,-1,4);             //given cases
    test11 = int_to_binstr(str,11,-3,8);            //given cases

//Negative cases
    test12 = int_to_binstr(NULL,22,65400,16);       //case where input is NULL
    test13 = int_to_binstr(str,3,310,0);            //case where nbits is 0
    test14 = int_to_binstr(str,40,310,8);           //case where num is greater than 2 power nbits
    test15 = int_to_binstr(str,40,310,33);          //case where nbits is greater than 33
    test16 = int_to_binstr(str,259,4,255);          //extreme case for uint8_t input

    if((test1 != -1)&&(test2 != -1)&&(test3 != -1)&&
       (test4 != -1)&&(test5 != -1)&&(test6 != -1)&&
       (test7 != -1)&&(test8 != -1)&&(test9 != -1)&&
       (test10 != -1)&&(test11 != -1)&&(test12 == -1)&&
       (test13 == -1)&&(test14 == -1)&&(test15 == -1)&&
       (test16 == -1)){
        return 1;
    }
    else{
        return 0;
    }
}
//-------------------------------------------------------------------------------------------------
int hex_bit(uint32_t num){
    int pos = 0;
    if(num >= 0){
    while(num != 0){
        pos++;
        num = num >> 4;
    }
    }
    return pos;
}
int uint_to_hexstr(char *str, size_t size, uint32_t num, uint8_t nbits){
    if((nbits != 4)&&(nbits != 8)&&(nbits != 16)&&(nbits != 32)){
        *str = '\0';
        return -1;
    }
    else if(size < (nbits >> 2) + 3){
        *str = '\0';
        return -1;
    }
    else if((nbits >> 2) < hex_bit(num)){
        *str = '\0';
        return -1;
    }
    else{
       int rem;
       str[0] = '0';
       str[1] = 'x';
       for(int i = (nbits >> 2)+1;i >= 2;i--){
           rem = num & 15;
           if(rem <= 9){
               str[i] = 48 + rem;
           }
           else{
               str[i] = 55 + rem;
           }
           num = num >> 4;
       }
       str[(nbits >> 2)+2] = '\0';
    }
    return (nbits >> 2) + 2;
}
//Ref : Obtained some Test Values from Abijith Anandakrishnan for testing purpose
uint32_t test_uint_to_hexstr(){
    uint32_t test1,test2,test3,test4,test5,test6,test7,test9,test10,test11,test12,test13,test14;
    char str[1024];
//Accepted cases
    test1 = uint_to_hexstr(str,11,255,8);           //extreme case for 8 bits
    test2 = uint_to_hexstr(str,19,65535,16);        //extreme case for 16 bits
    test3 = uint_to_hexstr(str,40,4294967295,32);   //extreme case of uint32_t input
    test4 = uint_to_hexstr(str,11,18,8);            //given cases
    test5 = uint_to_hexstr(str,22,65400,16);        //given cases
    test6 = uint_to_hexstr(str,19,18,16);           //given cases
    test7 = uint_to_hexstr(str,25,310,16);          //given cases
//Denied cases
    //test8 = uint_to_hexstr(NULL,22,65400,16);       //case where input is NULL
    test9 = uint_to_hexstr(str,3,310,0);            //case where nbits is 0
    test10 = uint_to_hexstr(str,40,310,8);          //case where num is greater than 2 power nbits
    test11 = uint_to_hexstr(str,40,310,33);         //case where nbits is greater than 33
    test12 = uint_to_hexstr(str,259,4,255);         //extreme case for uint8_t input
    test13 = uint_to_hexstr(str,9,12,6);            //case for nbits not equal 4 or 8 or 16 or 32
    test14 = uint_to_hexstr(str,4,1,1);             //extreme case for 1 bit

    if((test1 != -1)&&(test2 != -1)&&(test3 != -1)&&
       (test4 != -1)&&(test5 != -1)&&(test6 != -1)&&
       (test7 != -1)&&(test9 == -1)&&
       (test10 == -1)&&(test11 == -1)&&(test12 == -1)&&
       (test13 == -1)&&(test14 == -1)){
        return 1;
    }
    else{
        return 0;
    }
}
//------------------------------------------------------------------------------------
typedef enum {
    CLEAR,
    SET,
    TOGGLE
}operation_t;
uint32_t twiggle_bit(uint32_t    input,int bit,operation_t operation){
    uint32_t retval = 0xFFFFFFFF;
    if((bit >= 0)&&(bit <= 31)){
        if(operation == CLEAR){
            retval = (input & (1 << bit));
        }
        else if(operation == SET){
            retval = (input | (1 << bit));
        }
        else if(operation == TOGGLE){
            retval = (input ^ (1 << bit));
        }
    }
    return retval;
}
//Ref : Obtained some Test Values from Abijith Anandakrishnan for testing purpose
uint32_t test_twiggle_bit(){
    uint32_t test1,test2,test3,test4,test5,test6,test7,test8;
//Positive cases
    test1 = twiggle_bit(0,31,SET);                //extreme case 31st bit
    test2 = twiggle_bit(2147483647,31,CLEAR);     //extreme case 31st bit
    test3 = twiggle_bit(1,0,CLEAR);               //extreme case 0th bit
    test4 = twiggle_bit(32,0,TOGGLE);             //extreme case for 16 bits
    test5 = twiggle_bit(0,0,SET);                 //given cases
    test6 = twiggle_bit(0,3,SET);                 //given cases
    test7 = twiggle_bit(0x7337,5,TOGGLE);         //given cases
//Negative cases
    test8 = twiggle_bit(250,32,SET);              //case where bit is above 31

    if((test1 != 0xFFFFFFFF)&&(test2 != 0xFFFFFFFF)&&
       (test3 != 0xFFFFFFFF)&&(test4 != 0xFFFFFFFF)&&
       (test5 != 0xFFFFFFFF)&&(test6 != 0xFFFFFFFF)&&
       (test7 != 0xFFFFFFFF)&&(test8 == 0xFFFFFFFF)){
        return 1;
    }
    else{
        return 0;
    }
}
//----------------------------------------------------------------------------------------
//Ref : Obtained some Test Values from Abijith Anandakrishnan for testing purpose
uint32_t grab_three_bits(uint32_t input,int start_bit){
    if((start_bit < 0)||(start_bit >= 29)){
        return 0xFFFFFFFF;
    }
    while(start_bit != 0){
        input = input >> 1;
        start_bit --;
    }
    return input & 7;
}
uint32_t test_grab_three_bits(){
    uint32_t test1,test2,test3,test4,test5,test6,test7;
//Positive cases
    test1 = grab_three_bits(0,28);                    //extreme case 28th bit
    test2 = grab_three_bits(2147483647,28);           //extreme case 28th bit
    test3 = grab_three_bits(7,0);                     //extreme case 0th bit
    test4 = grab_three_bits(20,0);                    //extreme case for 16 bits
    test5 = grab_three_bits(0x7337,6);                //given cases
    test6 = grab_three_bits(0x7337,7);                //given cases
//Negative cases
    test7 = grab_three_bits(250,29);                  //case where bit is above 29

    if((test1 != 0xFFFFFFFF)&&(test2 != 0xFFFFFFFF)&&
       (test3 != 0xFFFFFFFF)&&(test4 != 0xFFFFFFFF)&&
       (test5 != 0xFFFFFFFF)&&(test6 != 0xFFFFFFFF)&&
       (test7 == 0xFFFFFFFF)){
        return 1;
    }
    else{
        return 0;
    }
}
//----------------------------------------------------------------------------------------------------------------------
//Ref : Obtained some Test Values from Abijith Anandakrishnan for testing purpose
char *char_to_hex(char *str,char s){
    int i,rem;
    for(i = 1;i >= 0;i--){
        rem = s & 15;
        if(rem <= 9){
            str[i] = 48 + rem;
        }
        else{
            str[i] = 55 + rem;
        }
        s = s >> 4;
    }
    str[2] = '\0';
    return str;
}
char *hex_offset(char *str,int offset){
    int i,rem;
    str[0] = '0';
    str[1] = 'x';
    for(i = 5;i >= 2;i--){
        rem = offset & 15;
        if(rem <= 9){
            str[i] = 48 + rem;
        }
        else{
            str[i] = 55 + rem;
        }
        offset = offset >> 4;
    }
    str[6] = ' ';
    str[7] = '\0';
    return str;
}
char *hexdump(char *str,size_t size,const void *loc,size_t nbytes){
    char ch[size],off_set[8];
    int offset = 0;
    str = hex_offset(str,offset);
    int i = 0;
    if(size >= nbytes + 1){
       for(;;++loc){
            char_to_hex(ch,*(char *)loc);
            strcat(str," ");
            strcat(str,ch);
            i++;
            if(((i & 15) == 0) && (*(char *)loc != '\0')){
                offset += 16;
                hex_offset(off_set,offset);
                strcat(str,"\n");
                strcat(str,off_set);
            }
            if(*(char *)loc == '\0'){
                break;
            }
        }
    }
    else{
        *str = '\0';
    }
    return str;
}
//Ref - Obtained Test values from Abijith AnadhaKrishnan
uint32_t test_hexdump(){

char *test1,*test2,*test3,*test4,*test5,*test6;
    char str1[1024];
    char str2[1024];
    char str3[1024];
    char str4[1024];
    char str5[1024];

    const char *buf1= \
        "To achieve great things, two things are needed:\n" \
        "a plan, and not quite enough time.";
    uint8_t buf2[] = {0,1,2,3,4,5,6,7,8,9,10,
                    11,12,13,14,15,16,17,18,19,20,
                    21,22,23,24,25,26,27,28,29,30,
                    31,32,33,34,35,36,37,38,39,40,
                    41,42,43,44,45,46,47,48,49,50,
                    51,52};
    const char *buf3= \
        "To achieve great things, two things are needed:\n" \
        "a plan, and not quite enough tim";

//Positive cases
    test1 = hexdump(str1,1024,buf1,16);                     //case to print only single line
    test2 = hexdump(str2,1024,buf1,17);                     //case to print till 1 byte after 16
    test3 = hexdump(str3,1024,buf2,32);                     //case to print exactly 2 lines
    test4 = hexdump(str4,1024,buf2,33);                     //case to print one byte after 2 lines
    test5 = hexdump(str5,sizeof(str5),buf3,strlen(buf3)+1); //case to print exactly 5 lines when I remove the last 2 characters

//Negative cases
    test6 = hexdump(str1,22,buf1,strlen(buf1)+1);              //case where str size is less

    if((test1[0] == '\0')&&(test2[0] != '\0')&&(test3[0] != '\0')&&
       (test4[0] != '\0')&&(test5[0] != '\0')&&(test6[0] == '\0')){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    printf("%d",test_uint_to_binstr());
    printf("%d",test_int_to_binstr());
    printf("%d",test_uint_to_hexstr());
    printf("%d",test_twiggle_bit());
    printf("%d",test_grab_three_bits());
    printf("%d",test_hexdump());
    return 0;
}
