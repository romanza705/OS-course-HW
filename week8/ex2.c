////
//// Created by roman on 06.10.2020.
////
//
//#include <unistd.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//int main() {
//    for (int i = 0; i < 10; i++)
//    {
//        memset(malloc(10 * 1024 * 1024), '0', 10 * 1024 * 1024);
//        sleep(1);
//    }
//
//}
////./ex2 & vmstat 1
////procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
////r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
////3  0      0 5790096 278860 2683404    0    0    78    37  179  597  5  1 92  2  0
////0  0      0 5782296 278860 2683404    0    0     0     0  991 4837  2  1 97  0  0
////0  0      0 5772864 278860 2683152    0    0     0     0  748 4361  2  1 97  0  0
////0  0      0 5762444 278868 2683660    0    0     0    44  767 4144  2  1 97  1  0
////0  0      0 5752152 278868 2683664    0    0     0     0  775 4242  2  1 97  0  0
////0  0      0 5742232 278868 2683152    0    0     0     0  750 4200  2  1 97  0  0
////0  0      0 5731940 278868 2683152    0    0     0     0  796 4208  2  1 97  0  0
////0  0      0 5721744 278868 2683664    0    0     0     0  705 4221  2  1 97  0  0
////0  0      0 5711356 278868 2683692    0    0     0     0  807 4228  2  1 97  0  0
////0  0      0 5701436 278868 2683180    0    0     0     0  749 4103  2  1 97  0  0
//// I am not sure but maybe there are zeros because I have a lot of physical memory
//// I increase conditions to 1500MB ..When RAM is not enough the OS use swapped memory
////./ex2 & top -d 1
//
////1940 roman     20   0 2246496 118272  74180 S  49,5  1,0   4:12.03 Xorg
////5337 roman     20   0 4612520 4,396g   1192 S  47,5 37,8   0:01.70 ex2
////2975 roman     20   0 8316084 1,046g  41508 S  30,7  9,0   7:37.46 java
////3613 roman     20   0 2941600 273032 102684 S   7,9  2,2   5:36.55 Web Content
////2103 roman     20   0 4420040 210476 100208 S   5,9  1,7   2:38.50 gnome-shell
////2773 roman     20   0 3831584 372908 162532 S   4,0  3,1   5:23.59 MainThread
////the usage of memory increased every second