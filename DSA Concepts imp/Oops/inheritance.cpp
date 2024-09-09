#include<iostream>
using namespace std;

class Animal{
    public:
    int age;
    int weight;

    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

//INHERTIED CLASS(SINGLE INHERTIANCE)
class Dog: public Animal{

};
//MULTI-LEVEL INHERITANCE
//animal class ko dog ne inhertic kia dog ko germansherpher ne inherit kia
class GermanShepherd: public Dog{

};

int main(){
    Dog d;
    d.speak();
    cout<<d.age<<endl;

    GermanShepherd g;
    g.speak();
}

//MULTIPLE INHERITANCE MEANS DONO CLASS SE INHERIT KREGA