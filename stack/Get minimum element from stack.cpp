
class Solution{
    int minEle;
    stack<pair<int,int>> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty()) return -1;
           return s.top().second;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty()) return -1;
           int a=s.top().first; //first d stack ka 1st
           s.pop();
           return a;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           //push data in 2 stacks, in first all elements and in 2nd first element and then the ones which are greater
           if(s.empty()) s.push({x,x}); 
           else{
               s.push({x,min(s.top().second,x)}); //push in 2nd the min of x and the top of second d stack
           }
       }
};