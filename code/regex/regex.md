# Aplicações das RegEx nas linguagens de programação

ER Clássicas -> Podem expressar/representar qualquer linguagem regular
------------
a+b -> {a, b}    b+a -> {b,a}
a.b -> {ab}    b.a -> {ba}
a*  -> {vazio, a, aa, aaa, aaaa, ..., aaaa...a}

Equivalências entre ER <-> AF

ER Estendidas -> Syntax Sugar (Açúcar Sintático)
-------------
a+ -> aa*
a?  -> a + vazio
[a-z]+
[abcdefghijklmnopqrqtuvxwyz]
(a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+x+w+y+z)(a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+x+w+y+z)*

 -> [a-f]  //asciitable.com [a-zA-Z]

RegEx
-----
Ao longo da construção das linguagens e das ferramentas, surgiu o RegEx (Regular Expressions)

* RegEx -> Inicialmente eram compatíveis com as ER Clássicas
* Algumas operações na RegEx ultrapassam os limites das linguagens regulares
* Inspiradas nos sistemas Unix

## Onde podemos aplicar
Regexr.com
* Editores de Texto (ctrl+f)
* Ferramenta do Sistema (GREP, GAWK, AWK)
* Linguagens de Marcação (HTML)
* Linguagens de programação (Javascript) 

RegEx (Instrução) -> Compilada -> Objeto (Autômato)

RegEx -> ER -> AF -> Implementado 
