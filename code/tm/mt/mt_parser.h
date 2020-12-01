#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

#ifndef MT_LIB_H_
    #include "mt_lib.h"
#endif // MT_LIB_H_
using namespace std;

TuringMachine load_from_file(string);
string trim(string);
vector<string> tokenize(string, string);
vector<char> tokenize_char(string, string);
string extract_name(string);
vector<char> extract_alphabet(string);
vector<string> extract_states(string);
string extract_value(string);
vector<transition> extract_delta(string);
transition extract_transition(string);

string trim(string str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ')+1);
    return str;
}

vector<string> tokenize(string str, string token){
  const char* t = token.c_str();
  vector<string> tokenized;
  char * cstr = new char [str.length()+1];
  strcpy (cstr, str.c_str());
  char * p = strtok (cstr,t);
  while (p!=0)
  {
    tokenized.push_back(p);
    p = strtok(NULL,t);
  }
  delete[] cstr;
  return tokenized;
}

vector<char> tokenize_char(string str, string token){
  vector<string> tokenized = tokenize(str,token);
  vector<char> tokenized_c;
  for (int i = 0; i < tokenized.size(); i++){
    tokenized_c.push_back(tokenized[i][0]);
  }
  return tokenized_c;
}

string extract_name(string line){
    int p = line.find_last_of("=") + 1;
    string name = line.substr(p, line.length()-p);
    return trim(name);
}

vector<char> extract_alphabet(string line){
    int p = line.find_last_of("=") + 1;
    string alphabet = line.substr(p, line.length()-p);
    alphabet = trim(alphabet);
    return tokenize_char(alphabet, ",");
}

vector<string> extract_states(string line){
    int p = line.find_last_of("=") + 1;
    string c = line.substr(p, line.length()-p);
    c = trim(c);
    return tokenize(c, ",");
}

string extract_value(string line){
    int p = line.find_last_of("=") + 1;
    return  line.substr(p, line.length()-p);
}

vector<transition> extract_delta(string line){
    vector<transition> r;
    r.clear();
    string transitions_line = extract_value(line);
    vector<string> transitions = tokenize(transitions_line, ";");
    for (int i = 0; i<transitions.size(); i++){
        r.push_back(extract_transition(transitions[i]));
    }
    return r;
}

transition extract_transition(string str_t){
    str_t.erase(0, str_t.find_first_not_of('(')).erase(str_t.find_last_not_of(')'), 1);
    vector<string> members_t = tokenize(str_t, ",");
    if (members_t.size()==5){
        transition t;
        t.from = members_t[0];
        t.read = members_t[1][0];
        t.write = members_t[2][0];
        t.direction = members_t[3][0];
        t.to = members_t[4];
        return t;
    }
    return undef_transition;
}

TuringMachine load_from_file(string filename){
    cout<<"loading: "<<filename << endl;
    TuringMachine m;
    fstream arq;
    arq.open(filename.c_str(), ios::in);
    string line = "";
    while (arq.good()){
        getline(arq, line);
        line = trim(line);
        if (line.find("DELTA=")==0){
            m.setTransitions(extract_delta(line));
        }else if (line.find("MT=")==0){
            m.setName(extract_name(line));
        }else if (line.find("A=")==0){
            m.setAlphabet(extract_alphabet(line));
        }else if (line.find("Q=")==0){
            m.setStates(extract_states(line));
        }else if (line.find("q0=")==0){
            m.setInitialState(extract_value(line));
        }else if (line.find("F=")==0){
            m.setFinalStates(extract_states(line));
        }else if (line.find("V=")==0){
            m.setAuxiliarAlphabet(extract_alphabet(line));
        }else if (line.find("S_B=")==0){
            m.setWhite(extract_value(line)[0]);
        }else if (line.find("S_I=")==0){
            m.setStart(extract_value(line)[0]);
        }
    }
    arq.close();
    return m;
}
