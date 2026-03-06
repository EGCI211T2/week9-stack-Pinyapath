#include<iostream>
using namespace std;
#include <cstring>
#include "stack.h"

int main(int argc, char **argv){
    for(int i=1;i<argc;i++){ 
      Stack s;
      int match=1;
      char t; 

      for(int j=0;j<strlen(argv[i]);j++){ 
            switch(argv[i][j]){

                case '[':
                case '(':
                case '{':
                    s.push(argv[i][j]);
                    break;

                case '}':
                    t = s.pop();
                    if(t!='{') match=0;
                    break;

                case ']':
                    t = s.pop();
                    if(t!='[') match=0;
                    break;

                case ')':
                    t = s.pop();
                    if(t!='(') match=0;
                    break;
            }

            if(match==0) break;
        }
        cout << "argv " << i << " "<<endl;
        if(match==0) cout<<"incorrect:mismatch"; 
        else if(!s.isEmpty()) cout<< "incorrect:too many open parentheses"<<endl; 
        else cout<<"correct"<<endl;
    }
    

    return 0;
}
