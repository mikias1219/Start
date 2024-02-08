#include <iostream>
using namespace std;
int main(){
int num=2;
switch (num)
{
case 1:
  cout<<"you insert 1"<<endl;
  break;
  case 2:
  cout<<"you insert 2"<<endl;
  break;
  case 3:
  cout<<"you insert 3"<<endl;
  break;
  case 4:
  cout<<"you insert 4"<<endl;
  break;
   

default:
cout<<"oh noo"<<endl;

}
int age;
  do{
cout<<"enter your age"<<endl;
cin>>age;
  }
  while (age!=50);

  
    return 0;
}