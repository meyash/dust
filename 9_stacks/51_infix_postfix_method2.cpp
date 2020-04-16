#include<bits/stdc++.h>
using namespace std;

//In this method both operators and operands are pushed into stack

class Stack{
    private:
        int size;
        int top;
        char *s;
    public:
        Stack(){
            top=-1;
        }
        Stack(int size){
            this->size=size;
            s=new char[size];
            top=-1;
        }
        ~Stack(){
            delete s;
        }
        void push(char x){
            if(top>=size-1){
                cout<<"Stack Full!"<<endl;
                return;
            }
            top=top+1;
            s[top]=x;
            cout<<"Pushed : "<<x<<" at index : "<<top<<endl;
        }
        char pop(){
            if(top<0){
                cout<<"Stack empty already!"<<endl;
                return 0;
            }
            char bakup=s[top];
            top=top-1;
            cout<<"Popped : "<<bakup<<" from index : "<<top+1<<endl;
            return bakup;
        }
        void peek(int index){
            if(index<=0||index>top){
                cout<<"Invalid index!"<<endl;
                return;
            }
            int bakup=top;
            while(bakup!=index){
                bakup--;
            }
            cout<<"Element at index : "<<index<<" is : "<<s[bakup]<<endl;
        }
        int getTopIndex(){
            return top;
        }
        char getTopElement(){
           return s[top]; 
        }
        int isEmpty(){
            if(top==-1){
                cout<<"Empty!"<<endl;
                return 0;
            }else{
                cout<<"Not Empty!"<<endl;
                return 1;
            }
        }
        int isFull(){
            if(top==size-1){
                cout<<"stack full!"<<endl;
                return 1;
            }else{
                cout<<"stack not full!"<<endl;
                return 0;
            }
        }
};

int isOperant(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return 1;
    }else{
        return 0;
    }
}

int prec(char x){
    if(x=='+'||x=='-'){
        return 1;
    }else if(x=='*'||x=='/'){
        return 2;
    }else if(x=='a'||x=='b'||x=='c'||x=='d'||x=='e'){
        return 3;
    }else{
        return 0;
    }
}

int main(){
    char infix[]={'a','+','b','*','c','-','d','/','e','\0'};
    char *postfix= new char[strlen(infix)+1];
    Stack s(strlen(infix)+1);
    
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(prec(infix[i])>prec(s.getTopElement())){
            s.push(infix[i]);
            i++;
        }else{
            postfix[j++]=s.pop();
        }
    }
    while(s.getTopIndex()>=0){
        postfix[j++]=s.pop();
    }
    postfix[j]='\0';

    i=0;
    while(postfix[i]){
        cout<<postfix[i]<<endl;
        i++;
    }
}

