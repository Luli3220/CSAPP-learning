#include<stdio.h>
#include<string.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start,size_t len){
    size_t i;
    for (i=0;i<len;i++){
        printf("%.2x ",start[i]);
    }
    printf("\n");
}
void show_int(int x){
    show_bytes((byte_pointer)&x,sizeof(x));
}
void show_float(float x){
    show_bytes((byte_pointer)&x,sizeof(x));
}
void show_pointer(void*x){
    show_bytes((byte_pointer)&x,sizeof(x));
}
void test_show_bytes(int x,float y){
    int*pval=&x;
    show_int(x);
    show_float(y);
    show_pointer(pval);
}
int main(){
    //test_show_bytes(12345,12345.0);
    /*  可以看出是小段存储  12345的十六进制表示为 0x00000393
    39 30 00 00 
    00 e4 40 46 
    b0 fe 5f 00 00 00 00 00 
    */

    // 习题2.5
    // int val=0x87654321;
    // byte_pointer pval=(byte_pointer)&val;
    // show_bytes(pval,1);
    // show_bytes(pval,2);
    // show_bytes(pval,3);
    
    //习题2.7
    const char*s="abcdef";
    show_bytes((byte_pointer)s,strlen(s));
    show_bytes((byte_pointer)s,7);
    /*
    61 62 63 64 65 66 
    61 62 63 64 65 66 00  多了一个终止符
    */
    
    return 0;
}