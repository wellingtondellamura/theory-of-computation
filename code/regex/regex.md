# Aplicações das RegEx nas linguagens de programação

ER Clássicas
------------
a+b -> {a, b}
a.b -> {ab}
a*  -> {vazio, a, aa, aaa, aaaa, ..., aaaa...a}

ER Estendidas
-------------
a+  -> aa*
a?  -> a + vazio
[abcdef] -> a+b+c+d+e+f -> [a-f]

RegEx
-----
Ao longo da construção das linguagens e das ferramentas, surgiu o RegEx (Regular Expressions)

* RegEx -> Inicialmente eram compatíveis com as ER Clássicas
* Algumas operações na RegEx ultrapassam os limites das linguagens regulares
* Inspiradas nos sistemas Unix

## Onde podemos aplicar

* Editores de Texto (ctrl+f)
* Ferramenta do Sistema (GREP, GAWK, AWK)
* Linguagens de Marcação (HTML)
* Linguagens de programação (Javascript) 

RegEx (Instrução) -> Compilada -> Objeto (Autômato)
