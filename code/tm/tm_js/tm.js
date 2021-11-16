const DIR = 1;
const ESQ = -1;
const a   = 'a';
const b   = 'b';
const BLK = ' ';
const A   = 'A';
const B   = 'B';

//components
var inputTape = document.getElementById("inputTape");
var buttonExecute = document.getElementById("buttonExecute");
var output = document.getElementById("output");

buttonExecute.addEventListener("click", executeDFA);


function undef(){
    return tr(-1, null, null);
}

function tr(q, w, m){
  return {to: q, write: w, moveTo: m}
}

function delta(q,s){
  switch(q) {
    case 0:
      if (s == a) return tr(1, A, DIR) ;
      if (s == b) return tr(1, A, DIR) ;
      break;
    }
    return undef();
  }

  function program(q, w){
    if (q == -1 || w.length == 0)
      return q;
    return program(delta(q, w[0]), w.substring(1));
  }


  function executeDFA(){
    output.value = "";
    var final = [3];
    var initial = 0;
    var tape = inputTape.value;
    var state = program(initial, tape);
    if (final.includes(state)){
      log("\n\n***Accepted***")
    } else {
      log("\n\n___Rejected___");
    }
    output.focus();
  }

  function log(text){
    output.value =  output.value +"\n"+ text;
  }