#include<iostream>
using namespace std;

int main () {

    //pointer to int is created, and pointing to some garbage address
    //int *p = 0; =>null

    //cout << *p << endl; // segmensat falte

    /*
    int i = 5;

    int *q = &i;
    cout << q << endl; //same address
    cout << *q << endl; // same value

    int *p = 0;
    p = &i;

    cout << p << endl;  // same address
    cout << *p << endl;  // same value
    */

   int num = 5;
   int a = num;
   cout << "a before " << num << endl; //5
   a++;
   cout << "a after " << num << endl; //5


   int *p  = &num;
   cout << "before " << num << endl; //5
   (*p)++;
   cout << "after " << num << endl;  //6 

    //copying a pointer
   int *q = p;
   cout << p <<" - " << q << endl;  //both same address
   cout << *p <<" - " << *q << endl; // both same value

   //important concept
   int i = 3;
   int *t = &i;
   //cout <<  (*t)++ << endl;
   *t = *t +1; // 4
    cout << *t << endl;
    cout << " before t " << t << endl;
    t = t + 1; // +4 int , +8 double .... arr => move to next element
    cout << " after t " << t << endl;



       int i = 3;
   int *t = &i;
//   cout <<  (*t)++ << endl;//3 ++(*t)=>4
//   cout<<*t<<endl;
  *t = *t +1; // 4
    cout << *t << endl;
    cout << " before t " << t << endl;
    t = t + 1; // +4 int , +8 double .... arr => move to next //element
    cout << " after t " << t << endl;//change
    cout << *t << endl;// -406003152


    return 0;
}