/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simpglc;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

/**
 *
 * @author wellington
 */
public class Grammar {
    private HashSet<Character> variables;
    private HashSet<Character> terminals;
    private HashMap<Character, List<String>> productions;
    private Character initial;

    public Grammar() {
        variables = new HashSet<>();
        terminals = new HashSet<>();
        productions = new HashMap<>();
    }

    public Grammar(HashSet<Character> variables, HashSet<Character> terminals, HashMap<Character, List<String>> productions, Character initial) {
        this.variables = variables;
        this.terminals = terminals;
        this.productions = productions;
        this.initial = initial;
    }

    public Character getInitial() {
        return initial;
    }

    public void setInitial(Character initial) {
        this.initial = initial;
    }

    public HashMap<Character, List<String>> getProductions() {
        return productions;
    }

    public void setProductions(HashMap<Character, List<String>> productions) {
        this.productions = productions;
    }

    public HashSet<Character> getTerminals() {
        return terminals;
    }

    public void setTerminals(HashSet<Character> terminals) {
        this.terminals = terminals;
    }

    public HashSet<Character> getVariables() {
        return variables;
    }

    public void setVariables(HashSet<Character> variables) {
        this.variables = variables;
    }
    
    public static Grammar fromString(String input){
        Grammar g = new Grammar();
        String[] lines = input.split(",");
        for (String line : lines) {
            String[] items = line.split("->");
            Character variable = items[0].charAt(0);
            String[] derivations = items[1].split("\\|");
            g.variables.add(variable);
            g.productions.put(variable, List.of(derivations));
            if (g.initial == null){
                g.initial = variable;
            }
            for (String d : derivations){
                for (Character t : d.toCharArray()){
                    if (Character.isLowerCase(t))
                        g.terminals.add(t);
                    else 
                        g.variables.add(t);
                }
            }
        }
        return g;
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (Character variable : productions.keySet()){
            s.append(variable);
            s.append("->");
            List<String> derivations = productions.get(variable);
            for (int i = 0;  i<derivations.size();  i++){
                String derivation = derivations.get(i);
                s.append(derivation);
                if (i == derivations.size()-1)
                    s.append("\n");
                else
                    s.append("|");
            }
        }
        return s.toString();
    }
    

}
