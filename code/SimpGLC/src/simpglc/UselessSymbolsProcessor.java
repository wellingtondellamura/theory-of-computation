/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simpglc;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author wellington
 */
public class UselessSymbolsProcessor implements Processor {

    @Override
    public Grammar process(Grammar grammar) {
        Grammar g1 = execStep1(grammar);
        Grammar g2 = execStep2(g1);
        return g2;
    }

    private Grammar execStep1(Grammar grammar) {
        Grammar g = new Grammar();
        HashSet<Character> tuv;
        int size_v1;
        HashSet<Character> v1 = new HashSet<>();
        do {
            size_v1 = v1.size();
            tuv = new HashSet<>(grammar.getTerminals());
            tuv.addAll(v1);
            for (Character v : grammar.getProductions().keySet()) {
                for (String p : grammar.getProductions().get(v)) {
                    if (belongsTo(p, tuv)) {
                        v1.add(v);
                        break;
                    }
                }
            }
        } while (size_v1 < v1.size());
        
        for (Character v : grammar.getProductions().keySet()) {
            ArrayList<String> productions = new ArrayList<>();
            for (String p : grammar.getProductions().get(v)) {
                if (belongsTo(p, tuv)) {
                    productions.add(p);
                }
            }
            g.getProductions().put(v, productions);
        }
        g.setTerminals(grammar.getTerminals());
        g.setInitial(grammar.getInitial());
        g.setVariables(v1);
        return g;
    }

    private Grammar execStep2(Grammar g1) {
        return g1;
    }

    private boolean belongsTo(String p, HashSet<Character> vut) {
        for (Character c : p.toCharArray()) {
            if (!vut.contains(c)) {
                return false;
            }
        }
        return true;
    }

}
