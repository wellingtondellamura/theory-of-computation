class Automaton {
  constructor() {
    this.initialState = 0;
    this.transitions = new Map();
    this.finalStates = new Set();
  }

  addTransition(state, symbol, nextState) {
    const key = `${state}-${symbol}`;
    this.transitions.set(key, nextState);
  }

  addFinalState(state) {
    this.finalStates.add(state);
  }

  delta(state, symbol) {
    const key = `${state}-${symbol}`;
    if (this.transitions.has(key)) {
      return this.transitions.get(key);
    }
    return -1;
  }

  extendedTransition(state, input) {
    if (input.length === 0) {
      return state;
    }

    const symbol = input[0];
    const remainingInput = input.slice(1);
    const nextState = this.delta(state, symbol);
    if (nextState === -1) {
      return -1;
    }
    return this.extendedTransition(nextState, remainingInput);
  }

  run(input) {    
    const finalState = this.extendedTransition(this.initialState, input);
    return this.finalStates.has(finalState);
  }
}

// Exemplo de uso:
const automaton = new Automaton();

// Definindo as transições
automaton.addTransition(0, 'a', 1);
automaton.addTransition(0, 'b', 1);
automaton.addTransition(1, 'a', 0);
automaton.addTransition(1, 'b', 0);

// Definindo os estados finais
automaton.addFinalState(0);

// Testando o autômato
const inputString = [
  '',
  'a','b',
  'aa','ab','ba','bb',
  'aaa','aab','aba','abb','baa','bab','bba','bbb',
  'aaaa','aaab','aaba','aabb'
];

for (const input of inputString) {
  console.log(input, automaton.run(input));
}

