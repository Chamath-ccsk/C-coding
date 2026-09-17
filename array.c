#include<stdio.h>
int main(){

int x;
for (int x=1;x<10;x++){
  if(x%7==0){
    goto label1;

    }
  printf("%d\n",x);
  }
   label1:
     printf("%d is devided by 7",x);


return 0;  
}

