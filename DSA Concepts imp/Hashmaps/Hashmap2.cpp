// //COUNT NUMBER OF CHARACTERS IN STRING

// #include<iostream>
// #include<unordered_map>
// using namespace std;
// int main(){
//     string str = "thiruvananthpuram";
//     unordered_map<char,int> freq;

//     for(int i=0;i<str.length();i++){ 
//         char ch =str[i];
//         freq[ch]++;
//     }

//     for(auto i: freq){
//         cout<<i.first<<" "<<i.second<<endl;
//     }
// }


///////////////////////////////////////////////////


//CHECK IF IT IS A CRICULAR LINKED LIST OR NOT

#include<iostream>
#include<unordered_map>
using namespace std;

bool checkCicular(NOde* head){
    unordered_map<node*, bool> vis;
    Node* temp = head;

    while(temp!= NULL){
        if(vis.find(temp) != vis.end()){
            return true;//end tak hnhi phoch paya cycle detected
        }
        else{
            vis[temp] = true; //temp ki entry nhi h toh temp ki entry banao
        }
        temp = temp -> next;
    }
    return false;//while loop se bahar nikl gye mtlb no loop

}
int main(){
    string str = "thiruvananthpuram";
    unordered_map<char,int> freq;

    for(int i=0;i<str.length();i++){ 
        char ch =str[i];
        freq[ch]++;
    }

    for(auto i: freq){
        cout<<i.first<<" "<<i.second<<endl;
    }
}