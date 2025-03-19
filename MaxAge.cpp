/*maxage.cpp
Yashvi Joshi
This is C++ program for print person details using class..*/
#include <iostream>
#include <cstring>
using namespace std;
//Class Declaration..
class person{
    private:
        string fname;
        string lname;
        int age;
    public:
        void getdata(string,string,int);
        void putdata();
        int getage(){
            return age;
        }
        friend person maxage(person [],int);
};
//Function implementation..
void person :: getdata(string fn,string ln,int a){
    cout<<"\nPlease enter person's first name: ";
    cin>>fn;
    cout<<"\nPlease enter person's last name: ";
    cin>>ln;
    cout<<"\nPlease enter person's age: ";
    cin>>a;
    fname=fn;
    lname=ln;
    age=a;
}
void person :: putdata(){
    cout<<"\nFull Name of person is : "<<fname<<" "<<lname<<endl;
    cout<<"\nAge of Person is : "<<age<<endl;
}
//simple funtion implementation for calculate age of given people..
int agesum(person *p1,int size){
    int sum=0;
    for (int i=0;i<size;i++){
        sum=sum+p1[i].getage();
    }
    return sum;
}
//Friend function implementation..
person maxage(person p1[],int size){
    int max=p1[0].age;
    int index=0;
    for (int i=1;i<size;i++){
        if(max<p1[i].age){
            max=p1[i].age;
            index=i;
        }
    }
    return p1[index];
}
int main(){
    //class Objects..
    person *p1;
    string s1,s2;
    int a,size;
    cout<<"\nHow many people's details you want to enter? : ";
    cin>>size;
    p1=new person[size];
    for (int i=0;i<size;i++){
        cout<<"\nPerson -"<<(i+1)<<" Details:"<<endl;
        p1[i].getdata(s1,s2,a);
    }
    for (int i=0;i<size;i++){
        cout<<"\n<---------------------------->\n";
        cout<<"\nPerson -"<<(i+1)<<" Details:"<<endl<<endl;
        p1[i].putdata();
        cout<<"\n<---------------------------->\n";
    }
    //calling simple funtion..
    int sum=agesum(p1,size);
    cout<<"\nSum of age of total given person's is : "<<sum<<endl;    
    *p1=maxage(p1,size);
    cout<<"\nMaximum age from total entered persons is: "<<p1->getage()<<endl;
    return 0;
}
