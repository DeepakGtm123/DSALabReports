// RECURSIVE FUNCTIONS

// To find factorial of given number
#include <iostream>
using namespace std;

int f(int n){
   if (n <= 1)
        return 1;
   else 
       return n*f(n-1);
}
int main(){
   int num;
   cout<<"Enter a number: ";
   cin>>num;
   cout<<"Factorial of entered number: "<<f(num);
   return 0;
}


//// Fibonacci series upto nth term
#include <iostream>
using namespace std;

int main(){
    int n, t1 = 0, t2 = 1, nextTerm = 0;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
  for (int i = 1; i <= n; ++i){
        if(i == 1){
            cout << " " << t1;
            continue;
        }
        if(i == 2){
            cout << t2 << " ";
           continue;
       }
	    nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        cout << nextTerm << " ";
    }
    return 0;
}


// Tower of honai
#include<iostream>
#include<conio.h>
using namespace std;

void TOH(int d, char t1, char t2, char t3){
	if(d==1){
		cout<<"\nShift top disk from tower"<<t1<<" to tower"<<t2;
		return;
	}
	TOH(d-1,t1,t3,t2);
	cout<<"\nShift top disk from tower"<<t1<<" to tower"<<t2;
	TOH(d-1,t3,t2,t1);
}

int main(){
	int disk;
	cout<<"Enter the number of disks:"; cin>>disk;
	if(disk<1)
		cout<<"There are no disks to shift";
	else
		cout<<"There are "<<disk<<"disks in tower 1\n";
	TOH(disk, '1','2','3');
	cout<<"\n\n"<<disk<<"disks in tower 1 are shifted to tower 2";
	getch();
	return 0;
}
