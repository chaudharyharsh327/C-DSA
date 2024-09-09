//unordered is constant time complexity
//where orderen is log n

#include<iostream>
using namespace std;
#include<map>
int main(){

    //creation
    map<string,int> mapping;



    //insertion 3 ways
    //1
    pair<string,int> p = make_pair("harsh", 21); 

    //2
    pair<string,int> q("sumit", 19);

    //3
    pair<string,int> r;
    q.first = "arun";
    q.second = 21;
     



     //MAPPING 2 WAYS
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);

    //2nd WAY
    mapping["chaudhary"] = 100;
   
   

    //TILL HERE CREATE INSERT AUR MAP KRDIA

    cout<<"size of map: "<<mapping.size()<<endl;


    //at use krke key ki value print kr stke ho + []
    //2 ways
    cout<<mapping.at("harsh")<<endl;
    cout<<mapping["harsh"]<<endl;


   // in count function if element is present thann count=1 if not then 0
    cout<<mapping.count("harsh")<<endl;
    

    //SEARCHING through maps agar end tak nhi phocha mtlb element beech mein
    //kahi hai toh found else not found
    // if(mapping.find("chaudhary") != mapping.end()){
    //     cout<<"Found"<<endl;
    // }
    // else{
    //     cout<<"Not Found"<<endl;;
    // }

    //iterator
    cout<<"Printing all entries"<<endl;
    for(auto i:mapping){
        //now we print first(string) and second(int )
        cout<<i.first <<"-->" <<i.second<<endl;
    }

    return 0;

}