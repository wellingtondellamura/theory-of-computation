let entrada = document.getElementById('entrada');
let botao = document.getElementById('botao');
let resultado = document.getElementById('resultado');

botao.addEventListener('click', function() {
    clearLog();
    let palavra = entrada.value;
    let res = automato(palavra, fp2);
    if(res) 
        log('>>>>>Aceita');
    else
        log('>>>>>Rejeita');
});


let fp1 = {
    q0: 0,
    final: [4],
    delta : function(q, a){
        switch(q){
            case 0 : if(a == 'a') return 1;
            case 1 : if(a == 'a') return 2;
            case 2 : if(a == 'b') return 3;
            case 3 : if(a == 'b') return 4;
            case 4 : if(a == 'a') return 1;
        }
        return -1;
    }
}


let fp2 = {
    q0: 0,
    final: [4],
    transitions: [
        {from: 0, read: 'a', to: 1},
        {from: 1, read: 'a', to: 2},
        {from: 2, read: 'b', to: 3},
        {from: 3, read: 'b', to: 4},
        {from: 4, read: 'a', to: 1}
    ],
    delta : function(q, a){
        for(let i = 0; i < this.transitions.length; i++){
            if(this.transitions[i].from == q && this.transitions[i].read == a)
                return this.transitions[i].to;
        }
        return -1;
    }
}


let fp_par = {
    q0: 0,
    final: [0],
    delta : function(q, a){
        switch(q){
            case 0 : if(a == 'a' || a == 'b') return 1;
            case 1 : if(a == 'a' || a == 'b') return 0;
        }
        return -1;
    }
}



let automato = function(palavra, funcao_programa){
    log('Palavra: ' + palavra);
    let q = funcao_programa.q0;
    for(let i = 0; i < palavra.length; i++){
        q = funcao_programa.delta(q, palavra[i]);
        log('q' + q + ' - ' + palavra[i]);
        if(q == -1) return false;
    }
    return funcao_programa.final.includes(q);
}


let log = (str) =>  resultado.innerHTML += str + '<br>';
let clearLog = () => resultado.innerHTML = '';