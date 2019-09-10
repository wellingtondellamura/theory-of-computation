
const SAMPLE_INPUT = "S->aAb | ab \n A->aAb | ";

const SAMPLE_GRAMMAR = {
    variables : ['S', 'A'],
    terminals : ['a', 'b'],
    productions: {
        'S' : ['aAb', 'ab'],
        'A' : ['aAb', '']
    },
    initial : 'S'
}


function loadGrammar(text){
    let g = {variables:new Set(), terminals:new Set(), productions:[], initial:null};
    let vars = text.trim().split("\n");
    vars.forEach(element => {
        let deriv = element.split("->");
        if (g.initial == null) {
            g.initial = deriv[0].trim(); 
        }
        g.productions[deriv[0].trim()] = deriv[1].split("|").map(x => x.trim());
    });
    g.variables = Object.keys(g.productions);
    g.variables.forEach(v => g.productions[v].forEach(p => p.split("").forEach(a=> {if (!g.variables.includes(a)) g.terminals.add(a)})));
    return g;
}

//console.log("-----");
console.log(
    loadGrammar(SAMPLE_INPUT)
);

