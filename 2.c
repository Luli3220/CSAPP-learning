// 2.55
 
// #include<stdio.h>
// typedef unsigned char* byte_point;
// void show_bytes(byte_point start,size_t len){
//     size_t i;
//     for(i=0;i<len;i++){
//        printf(" %.2x",start[i]);
//     }
//     printf("\n");
// }
// void show_int(int x){
//     show_bytes((byte_point)&x,sizeof(int));
// }
// void show_float(float x){
//     show_bytes((byte_point)&x,sizeof(float));
// }
// void show_point(void* x){  //void是更通用的写法，这样可以展示所有类型的指针
//     show_bytes((byte_point)&x,sizeof(void*));
// }
// int main(){
//     int ival=127;
//     float fval=(float)ival;
//     int*pval=&ival;
//     show_int(ival);
//     show_float(fval);
//     show_point(pval);
//     return 0;
// }




//2.58
// #include<stdio.h>
// typedef unsigned char* byte_point;
// int is_little_endian(){
//     int test_num=0xff;
//     byte_point byte_start=(byte_point)&test_num;
//     if(byte_start[0]==0xff) return 1;
//     else return 0;
// }
// int main(){
//     if(is_little_endian()==1) printf("小端\n");
//     else printf("大端\n");
//     return 0;
// }



//2.59
//保留一个位数，用与全1取&
// #include<stdio.h>
// int main(){
//     ssize_t mask=0xff;
//     size_t x=0x89ABCDEF,y=0x76543210;
//     size_t res=(x&mask)|(y&~mask);
//     printf("%x",res);
//     return 0;
// }



//2.60
//替换的思想 ：先归零在|
// #include<stdio.h>
// unsigned replace_byte(unsigned x,int i,unsigned char b){
//    if(i<0){
//     printf("error:i<0");
//     return x;
//    }
//    else if(i>sizeof(x)-1){
//     printf("error:i>sizeof(x)-1");
//     return x;
//    }
//    unsigned mask=((unsigned)0xff)<<(i<<3);  //每个字节是8位，所以i<<3
//    unsigned pos_byte=((unsigned)b)<<(i<<3);
//    //先将那几位归零，然后在|
//    return (x&~mask)|pos_byte;
// }
// int main(){
//     unsigned rep_0 = replace_byte(0x12345678, 0, 0xAB);
//     unsigned rep_3 = replace_byte(0x12345678, 3, 0xAB);
//     printf("%x",rep_0);
//     printf("\n");
//     printf("%x",rep_3);
//     return 0;
// }



//2.61
// #include<stdio.h>
// int A(int x){  //判断是否全为1
//     return !~x;
// }
// int B(int x){ //判断是否全为0
//     return !x;
// }
// int C(int x){ //判断最低字节位是否为 0xff
//     return A(x|~0xff);
// }
// int D(int x){ //判断最高字节位是否为 0x00
//     return B((x >> ((sizeof(int)-1) << 3)) & 0xff);
// }



//2.62(是否是算数右移)
// #include<stdio.h>
// int int_shifts_are_arithmetic(){
//     int num=-1;
//     return !(num^(num>>1));  //采用异或判断相等
// }
// int main(){
//     if(int_shifts_are_arithmetic()) printf("yes\n");
//     else printf("no\n");
//     return 0;
// }



//2.63
// #include <stdio.h>
// unsigned srl(unsigned x, int k) {  //算数右移完成逻辑右移
//    unsigned xsra = (int) x >> k;
//    int w=sizeof(int)<<3;
//    int mask= (int)-1 <<(w-k);
//    return xsra&(~mask);
// }
// int sra(int x, int k) {  //逻辑右移完成算数右移
//     int xsrl=(unsigned)x>>k;
//     int w=sizeof(int)<<3;
//     int mask = (int) -1 << (w - k);
//     int m = 1 << (w - 1);
//     mask &= ! (x & m) - 1;
//     return xsrl | mask;
// }
// int main() {
//   return 0;
// }



//2.65 (判断是否有奇数个1)
//有两个相同的一 就给他消掉（这个思想挺秒的）
//前一半和后一半 如果都为1 那么消掉，如果不同，保留一（这样不会减少1的个数

// int odd_ones(unsigned x){  
//    x ^= x >> 16;
//    x ^= x >> 8;
//    x ^= x >> 4;
//    x ^= x >> 2;
//    x ^= x >> 1;
//    x &= 0x1;
//   return x;
// }



//2.66

/*
 * Generate mask indicating leftmost 1 in x. Assume w=32
 * For example, 0xFF00 -> 0x8000, and 0x6000 -> 0x4000.
 * If x = 0, then return 0
*/

int leftmost_one(unsigned x){
   
}