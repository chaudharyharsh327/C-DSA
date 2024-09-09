// // 1-->ENCAPSULATION
// // //measn creating a class to define all the propoerties of object
// // ina single place


// //2-->INHERITANCE

// #include<iostream>
// using namespace std;
//  class Human{
//     public:
//     int height;
//     int weight;
//     int age;

//     public:
//     int getAge(){
//         return this->age;
//     }
//     void setWeight(int w){
//         this->weight = w;
//     }
//  };

// //Male class human class ko public way mein inherit kr rha hai
// //agr super class ke data private hai toh use inherit nhi kia jaa skta
//  class Male: public Human{
//     public:
//     string color;

//     void sleep(){
//         cout<<"Male sleeping"<<endl;
//     }
//  };

//  int main(){
//     Male object1;
//     cout<<object1.age<<endl;
//     cout<<object1.weight<<endl;
//     cout<<object1.height<<endl;

//     cout<<object1.color<<endl;
//     object1.setWeight(84);
//     cout<<object1.weight<<endl;
//     object1.sleep();
//  }