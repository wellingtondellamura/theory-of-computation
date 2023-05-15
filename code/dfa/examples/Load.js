var fs = require('fs');
var fileName = process.argv[2];

const automatonDataString = fs.readFileSync(fileName, 'utf8');
const automatonData = JSON.parse(automatonDataString);
const automaton = new Automaton();

automaton.initialState = automatonData.initialState;

for (const transition of automatonData.transitions) {
automaton.addTransition(transition.from, transition.symbol, transition.to);
}

for (const finalState of automatonData.finalStates) {
automaton.addFinalState(finalState);
}
