#include <iostream>
#include <string>
#include <stack>

enum strlexic{
        false_input,
        token1,
        token2,
        token3,
        token4,
        token5,
        token6,
        token7,
        token8,
        token9,
        token10
    };

strlexic tokenOption(std::string part){
        if((part[0] == 'p')||(part[0] == 'q')||(part[0] == 'r')||(part[0] == 's')) return token1;
        if(part[0] == 'n'){
            if (part[1] == 'o'){
                if (part[2] == 't'){
                    return token2;
                }
            }
        }
        if(part[0] == 'a'){
            if(part[1] == 'n'){
                if(part[2] == 'd'){
                    return token3;
                }
            }
        }
        if(part[0] == 'o'){
            if(part[1] == 'r'){
                return token4;
            }
        }
        if(part[0] == 'x'){
            if(part[1] == 'o'){
                if(part[2] == 'r'){
                    return token5;
                }
            }
        }
        if(part.length() == 2){
            if(part[0] == 'i'){
                if (part[1] == 'f'){
                    return token6;
                }
            }
        }
        if(part[0] == 't'){
            if(part[1] == 'h'){
                if(part[2] == 'e'){
                    if(part[3] == 'n'){
                        return token7;
                    }
                }
            }
        }
        if(part[0] == 'i'){
            if (part[1] == 'f'){
                if (part[2] == 'f'){
                    return token8;
                }
            }
        }
        if(part[0] == '(') return token9;
        if(part[0] == ')') return token10;
        return false_input;
    }

std::string lexic_analyzer(std::stack<std::string> t,std::string obj){
        int i,y,x = 0;
        std::string part,result;
        for (i = 0; i < obj.length() ;i++){
            y = 0;
            x = i;
            while ((obj[x] != ' ') && (x != obj.length())){
                y++;
                x++;
            }
            part = obj.substr(i,y);
            switch(tokenOption(part)){
                case token1:{
                    result.append(1,'1');
                    result.append(1,' ');
                    break;
                }case token2:{
                    result.append(1,'2');
                    result.append(1,' ');
                    break;
                }case token3:{
                    result.append(1,'3');
                    result.append(1,' ');
                    break;
                }case token4:{
                    result.append(1,'4');
                    result.append(1,' ');
                    break;
                }case token5:{
                    result.append(1,'5');
                    result.append(1,' ');
                    break;
                }case token6:{
                    result.append(1,'6');
                    result.append(1,' ');
                    break;
                }case token7:{
                    result.append(1,'7');
                    result.append(1,' ');
                    break;
                }case token8:{
                    result.append(1,'8');
                    result.append(1,' ');
                    break;
                }case token9:{
                    result.append(1,'9');
                    result.append(1,' ');
                    break;
                }case token10:{
                    result.append(1,'1');
                    result.append(1,'0');
                    result.append(1,' ');
                    break;
                }default:{
                    result.insert(result.length(), "Error");
                    break;
                }
            }
            i+=y;
        };
        return result;
    };

void insertStack(std::stack<std::string> &t,std::string lexic){
    int i,y,x = 0;
    std::string part;
    std::stack<std::string> temp;
    for (i = 0; i < lexic.length() ;i++){
        y = 0;
        x = i;
        while ((lexic[x] != ' ') && (x != lexic.length())){
            y++;
            x++;
        }
        part = lexic.substr(i,y);
        if(part == "1"){    temp.push("1");}
        if(part == "2"){    temp.push("2");}
        if(part == "3"){    temp.push("3");}
        if(part == "4"){    temp.push("4");}
        if(part == "5"){    temp.push("5");}
        if(part == "6"){    temp.push("6");}
        if(part == "7"){    temp.push("7");}
        if(part == "8"){    temp.push("8");}
        if(part == "9"){    temp.push("9");}
        if(part == "10"){    temp.push("10");}
        i+=y;
    };
    t.push("#");
    while (!temp.empty()) {
        t.push(temp.top());
        temp.pop();
    }
}

bool parser(std::stack<std::string> &t,std::string requirment){
    if (t.top() == "#"){
        t.pop();
        return true;
    }else if (t.top() == requirment){

        std::string s = t.top();
        t.pop();
        if (s == "1"){
            return parser(t,"3") || parser(t,"4") || parser(t,"5") || parser(t,"8");
        }
        else if (s == "2"){
            return parser(t,"1") || parser(t,"9");
        }
        else if ((s == "3") || (s == "4") || (s == "5") || (s == "8") || (s == "7")){
            return parser(t,"1") || parser(t,"2") || parser(t,"9");
        }
        else if (s == "6"){
            return parser(t,"1") || parser(t,"2") || parser(t,"9") + parser(t,"7");
        }
        else if (s == "9"){
            return parser(t,"1") || parser(t,"2") + parser(t,"10");
        }
        else if (s == "10"){
            return parser(t,"3") || parser(t,"4") || parser(t,"5") || parser(t,"8");
        }
    }else{
        return false;
    }
}

int main()
{
//p xor ( q and not ( p and q ) )
    std::string input_user,resultlexic,t;
    getline(std::cin,input_user);
    std::stack<std::string> s;
    std::cout << "Input: " << input_user << std::endl;
    resultlexic = lexic_analyzer(s,input_user);
    std::cout << "Output: " << resultlexic << std::endl;
    insertStack(s,resultlexic);
    std::cout << "Hasil: ";
    if (s.top() == "1"){
        if(parser(s,"1")){
            std::cout << "VALID";
        }else{
            std::cout << "TIDAK VALID";
        }
    }
    else if (s.top() == "2"){
        if(parser(s,"2")){
            std::cout << "VALID";
        }else{
            std::cout << "TIDAK VALID";
        }
    }
    else if (s.top() == "6"){
        if(parser(s,"6")){
            std::cout << "VALID";
        }else{
            std::cout << "TIDAK VALID";
        }
    }
    else if (s.top() == "9"){
        if(parser(s,"9")){
            std::cout << "VALID";
        }else{
            std::cout << "TIDAK VALID";
        }
    }

    return 0;
}
