function delta(q, s){
    switch (q){
        case 0: {
            if (s == 'a') return 1;
            break;
        }
        case 1: {
            if (s == 'a' || s == 'b') return 1;
            if (s == 'c') return 2;
            break;
        }
        case 2: {
            if (s == 'a' || s == 'b') return 2;
            if (s == 'c') return 1;
            break;
        }
    }
    return -1;
}

function process(w, q) {
    let state = delta(q, w[0]);
    if (state == -1)
        return state;
    return process(w.substr(1), state);
}

function program(w){
    let start = 0;
    let finals = [2];
    let state = process(w);
    if (finals.includes(state)){
        //aceita
    }
}