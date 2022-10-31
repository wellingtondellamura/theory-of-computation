# Simulação de Máquinas de Estado
- Autômatos Finitos Determinísticos (F)
  - 0,a,1  -- (transição de q0 para q1 lendo a)
- Autômatos de Pilha Determinísticos (P)
  - 0,a;x;y,1  -- (transição de q0 para q1 lendo a da fita, x da pilha e escrevendo y na pilha)
- Máquinas de Turing Determinísticas (T)
  - 0,a;A;D,1  -- (transição de q0 para q1 lendo a, escrevendo A e indo para d (R/L))

## Funcionamento
- Especificação da Máquina: specs.m
- Entradas a serem processadas: input.in
- Saídas do processamento: output.out

### specs.m
```
1 X (tipo da máquina [T/P/F])
2 I (estado inicial (número))
3 F1,F2,F3 (estados finais (número))
4 F,COND,T
5 ()
...
N ()
```

### input.in
```
1 abababababab
2 bbbbbbababababa
3 abababababbaaaaa
4 abababab
```

### output.out
```  (S = Accept/Reject)
1 S;tape  -- conteúdo da fita
2 A;bbbbbbababababa
3 R;abababababbaaaaa
4 R;abababab
```

### Funcionamento
Especificação: spec.m   (U)
Entrada: input.in       (U)
Saída: output.out       (S)
Simulador: SIM

spec.m --
         |------
                | ---> [SIM] ---> output.out
         |------
input.in-

$ sim spec.m input.in output.out

$ sim -i input.in spec.m



Saída - S/N

d->[DB]->b
b->[BD]->d
b1,b2->[SB]->b

d1,d2->[SD]->d

d1 ->[DB] -> b1-
                | ---> [SB] ---> b->[BD]->d
d2 ->[DB] -> b2-


db(x) -> y
bd(x) -> y
sb(x,y) -> z

fun sd(x,y) -> bd(sb(db(x),db(y)))
