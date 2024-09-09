// //object is a entity which have /state/property/behavior 

// //inclusion of objects in our code improves redeability

// //class ke ander entity ki properties hoti hai

// //acess modifires--> public(can be accessed outside of class)
// //               -->private(caanot be accessed outside of class)



// // Padding is the process of adding extra bytes to a data structure to align its elements in memory. 
// // This is typically done to ensure that each element of the data structure is properly aligned on a memory boundary that is optimal for the underlying hardware architecture. 
// // By adding padding, access to the elements of the data structure can be more efficient, as they are aligned in a way that minimizes memory access time.

// // Greedy alignment, on the other hand, is a technique where data elements are packed tightly together in memory to minimize wasted space.
// //  This can improve memory usage and reduce the overall size of the data structure, which can lead to better performance and reduced memory overhead.


// //ENCAPSULATION --> wrapping up data memeber and function
// //encapsulation(info hiding/data hiding)

// #include<iostream>
// #include<string>
// #include<cstring>
// using namespace std;
// class Hero{
//     //properties
//     public:
//      int health;
//      int level;
//      char *name; // char name[100] aise bhi kr skte the but we do it dynamically
//      //one line no.35 for better space management

//      Hero(){
//         cout<<"constructor called"<<endl;
//         name = new char[100];
         
//      }

//      //parameterized constructor 
//      Hero(int health){
//         //means jo hero(ramesh) ki health h uske ander jo tumne declare ki hai
//         //int health vo daaldo
//         // cout<<"->this"<<this<<endl;
//         this-> health=health;

//      }
//      void setName(const char* name){
//     strcpy(this->name, name);
// }

//      Hero(int health, char level){
//         this-> level = level;
//         this-> health = health;
//      }

//      //copy constructor khud bana lo
//      Hero(Hero& temp){
//       cout<<"copy constructor called"<<endl;
//       this->health = temp.health;
//       this->level = temp.level;
//      }

//      int getHealth(){
//       return health;
//      }

//      int getLevel(){
//       return level;
//      }

//      int setHealth(int h){
//       health = h;
//      }

//      int setLevel(char ch){
//       level = ch;
//      }

//     //**jo cheez private hai use class ke ander hi acces kr skte ho
//     //agr private ko class ke bahar access krna hai you will need getter and setter
   

//      void print(){
//       cout<<endl;
//       cout<<"Name:"<<this->name <<","; 
//         cout<<"health: "<< this->health<<",";
//         cout<<"level: "<< this->level<<endl;
//      }

  
// };

// int main(){
//     //creation of object
//     // Hero h1;
//     // cout<<"size: "<<sizeof(h1)<<endl;
//     //output of size is coming 4 because int is of 4 bytes
//     //****if there were no properties then output of size will come 1;

//     // cout<<"health is"<<ramesh.health <<endl;
//     // cout<<"level is"<<ramesh.level <<endl;
    
//     //object created statically
//     // Hero ramesh;

//     // //object created dynamically
//     // Hero *h = new Hero(11);





//     //****COPY CONSTRUCTOR
//     //MEANS S KI SAARI VALUES LIKE HEALTH, LEVEL R MEIN COPY KRDO  
//    //  Hero S(70, 'C');
//    //  S.print();

//    //  Hero R(S);
//    //  R.print();



//    // Hero hero1;
//    // hero1.setHealth(12);
//    // hero1.setLevel('D');  
//    // char name[7]= "babbar";
//    // hero1.setLevel(name);  

//    // hero1.print();





//    //DEEP VS SHALLOW COPY
//    //default copy constructor shallow copy krta hai
//    //means upar example mein health aur level hai S and R ki 
//    //apne agr default copy constructor se banya dono ko
//    //toh R ke changes S mein bhi aajenge jbki change sirf R mein kia ho


//    //whereas deep copy mein ek new array banti hai jismien cahnges store hote hai
//    // so jispe kia hai usi pe change hoga it is done in manual(not default)
//    //copy constructor



//    //DESTRUCTOR (~ hero(){})
//    //memory ko free krta hai
//    //no return type
//    //no i/p parameter

//    //statically created cheezo ke liye destructor automatically called hota hai
//    //dynamically ke liye call krna padega manually



//    ///STATIC FUNCTIONS
//    //object banane ki need nhi h
//    //this(pointer to current object) keyword not required as no object is there








