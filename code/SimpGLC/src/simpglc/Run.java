/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simpglc;

/**
 *
 * @author wellington
 */
public class Run {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String input = "S->aAa|bBb,A->a|S,C->c";
        Grammar g = Grammar.fromString(input);
        System.out.println(g);
        Grammar u = new UselessSymbolsProcessor().process(g);
        System.out.println(u);

    }
}
