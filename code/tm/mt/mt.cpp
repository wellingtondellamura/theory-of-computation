#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "mt_lib.h"
#include "mt_parser.h"

using namespace std;

void usage(string);
void batch_process(TuringMachine, string, string);
void interactive_process(TuringMachine);

int main(int argc, char* argv[]){
    if (argc >= 2){
        string opt = argv[1];
        if (opt.compare("-h")==0){
            usage(argv[0]);
        }else if ((opt.compare("-f")==0) && (argc >= 4)){
            string filename = argv[2];
            string mode = argv[3];
            if (mode.compare("-i")==0){
                TuringMachine machine = load_from_file(filename);
                interactive_process(machine);
            }else if ((mode.compare("-b")==0) && (argc >= 6)){
                TuringMachine machine = load_from_file(filename);
					machine.print();
                string input_filename = argv[4];
                string output_filename = argv[5];
                batch_process(machine, input_filename, output_filename);
            }else{
                cout << "Invalid or incomplete arguments on " << mode << endl;
            }
        } else{
            cout << "Invalid arguments" << endl;
            return 1;
        }
    }else{
        usage(argv[0]);
    }

    return 0;
}

void interactive_process(TuringMachine m){
    cout<<"Machine: " << m.getName()<<endl;
    string tape;
    cout << "Input read (? for epsilon, empty line to stop)"<<endl;
    while (true) {
        cout<<"entrada: ";
        getline(cin, tape);
        if (tape.empty()){
            return;
        }
        bool loop = false;
        process_result r = m.run(tape);
        cout <<"Result Tape: "<< r.result_tape<< endl;
        if (r.accepted){
            cout << "[accepted]"<<endl;
        }else{
            if (r.loop){
                cout << "[loop]"<<endl;
            }else{
                cout << "[rejected]"<<endl;
            }
        }
    }
}

void batch_process(TuringMachine m, string input, string output){
    fstream input_file, output_file;
    input_file.open(input.c_str(), ios::in);
    output_file.open(output.c_str(), ios::out | ios::trunc);
    string tape="";
    while (input_file.good()){
        getline(input_file, tape);
        process_result r = m.run(tape);
        output_file<<r.tape << "|" << r.result_tape << "|" << r.accepted << endl;
        //cout<<r.tape << " >> " << r.result_tape << " >> " << (r.accepted?"accepted":"rejected") << endl;
    }
    cout << "Done."<<endl;
    input_file.close();
    output_file.close();
}

void usage(string program_name){
    int p = program_name.find_last_of("\\")+1;
    program_name = program_name.substr(p);
    cout << "Basic Turing Machine"<<endl;
    cout << "USAGE:"<<endl<<endl;
    cout << program_name << " -h \n" << "- Print this usage list"<<endl<<endl;
    cout << program_name << " -f [filename] [mode] \n" << "- Load Turing Machine from [filename] and execute [mode]"<<endl<<endl;
    cout << "[mode]" << endl;
    cout << " -i: interactive mode - user informs the tape and result is printed on screen."<<endl;
    cout << " -b [in] [out]: batch mode - reads [in] file and save the result on [out]."<<endl;
    cout << endl;
}
