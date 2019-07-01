
//components
var inputTape = document.getElementById("inputTape");
var buttonExecute = document.getElementById("buttonExecute");
var output = document.getElementById("output");

buttonExecute.addEventListener("click", executeDFA);

//functions
  function delta(q,s){
    log("--- Delta("+q+","+s+")");
    switch(q) {
      case 0:
        if (s == 'a') return 1;
        if (s == 'b') return 2;
        break;
      case 1:
        if (s == 'a') return 3;
        if (s == 'b') return 2;
        break;
      case 2:
        if (s == 'a') return 1;
        if (s == 'b') return 3;
        break;
      case 3:
        if (s == 'a') return 3;
        if (s == 'b') return 3;
        //break;
    }
    return -1;
  }

  function program(q, w){
    log("Program("+q+","+w+")");
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