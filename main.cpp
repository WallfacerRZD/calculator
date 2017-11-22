#include<iostream>
#include<functions.h>
#include<BigDate.h>


int main(){
    //以空格分割
    std::string expression;
    std::cin>>expression;
    PostFixStr = TransforToPostFix(expression);
    std::cout<<GetPostFixVal(PostFixStr);
    return 0;
}