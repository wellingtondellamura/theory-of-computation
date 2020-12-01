#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

#ifndef MT_LIB_H_
#define MT_LIB_H_
#endif // MT_LIB_H_
using namespace std;

struct process_result{
    string tape;
    string result_tape;
    bool accepted;
    bool loop;
};

struct transition{
    string from;
    string to;
    char read;
    char write;
    char direction;

    bool operator==(const transition& other)
    {
        return (from.compare(other.from) == 0) &&
               (to.compare(other.to) == 0) &&
               direction == other.direction &&
               read == other.read &&
               write == other.write;
    }
    bool operator!=(const transition& other){
        return (from.compare(other.from) != 0) ||
               (to.compare(other.to) != 0) ||
               direction != other.direction ||
               read != other.read ||
               write != other.write;
    }
};

transition undef_transition;

class TuringMachine {
    private:
    string name;
    vector<char> alphabet;
    vector<string> states;
    string initial_state;
    vector<string> final_states;
    vector<char> aux_alphabet;
    char white;
    char start;
    vector<transition> transitions;

    bool is_final_state(string state){
        for (int i=0; i<final_states.size(); i++){
            string f = final_states[i];
            if (f.compare(state)==0){
                return true;
            }
        }
        return false;
    }
    transition find_transition(string state, char c){
			printf("find_transition(%s, %c)\n", state.c_str(), c);
        for (int i = 0; i< transitions.size(); i++){
            transition t = transitions[i];
            if (t.from.compare(state)==0 && t.read == c){
                return t;
            }
        }
        return undef_transition;
    }

    public:
    void print(){
        cout << "Turing Machine: " << name << endl;
        cout << "Alphabet: ";
        for (int i=0;i<alphabet.size(); i++) cout << alphabet[i]<<" ";
        cout << endl;
        cout << "States: ";
        for (int i=0;i<states.size(); i++) cout << states[i]<<" ";
        cout << endl;
        cout << "Final States: ";
        for (int i=0;i<final_states.size(); i++) cout << final_states[i]<<" ";
        cout << endl;
        cout << "Auxiliar Alphabet: ";
        for (int i=0;i<aux_alphabet.size(); i++) cout << aux_alphabet[i]<<" ";
        cout << endl;
        cout << "White Symbol: " << white << endl;
        cout << "Start Tape Symbol: " << start << endl;
        cout << "Transitions: "<<transitions.size()<<endl;
        for (int i=0;i<transitions.size(); i++){
            transition t = transitions[i];
            cout << t.from << "-("<<t.read << ","<<t.write<<","<<t.direction<<")->"<<t.to<<endl;
        }
        cout<<endl;
    }
    process_result run(string tape){
        process_result r;
        r.tape = tape;
        r.loop = false;
        string state = initial_state;
        if (tape[0]!=start){
            tape = start + tape;
        }

        int p = 0;
        bool stop = false;
        while (!stop){
            char c = tape[p];
            if (is_final_state(state)){
                r.accepted = true;
                r.result_tape = tape;
                break;
            }
            transition t = find_transition(state, c);
            if(t!=undef_transition){
                tape[p] = t.write;
                if (t.direction == 'D'){
                    p++;
                    if(tape.length() < p+1){
                        tape = tape + white;
                    }
                }else if (t.direction == 'E'){
                    p--;
                    if (p<0){
                        r.accepted = false;
                        r.result_tape = tape;
                        break;
                    }
                }
                state = t.to;
            }else{
                r.accepted = false;
                r.result_tape = tape;
                break;
            }
        }
        return r;
    }

//##################################################
    string getName(){
        return name;
    }
    void setName(string name){
        this->name = name;
    }

    vector<char> getAlphabet(){
        return alphabet;
    }
    void setAlphabet(vector<char> alphabet){
        this->alphabet = alphabet;
    }

    vector<string> getStates(){
        return states;
    }
    void setStates(vector<string> states){
        this->states = states;
    }

    string getInitialState(){
        return initial_state;
    }
    void setInitialState(string initial_state){
        this->initial_state = initial_state;
    }

    vector<string> getFinalStates(){
        return final_states;
    }
    void setFinalStates(vector<string> final_states){
        this->final_states = final_states;
    }

    vector<char> getAuxiliarAlphabet(){
        return aux_alphabet;
    }
    void setAuxiliarAlphabet(vector<char> aux_alphabet){
        this->aux_alphabet = aux_alphabet;
    }

    char getWhite(){
        return this->white;
    }
    void setWhite(char white){
        this->white = white;
    }

    char getStart(){
        return this->start;
    }
    void setStart(char start){
        this->start = start;
    }

    vector<transition> getTransitions(){
        return transitions;
    }
    void setTransitions(vector<transition> transitions){
        this->transitions = transitions;
    }
//##################################################

};

