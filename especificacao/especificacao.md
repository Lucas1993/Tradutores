Especificação do trabalho de Tradutores
=======================================

Descrição do trabalho
---------------------

Este trabalho consiste na implementação de um tradutor para uma linguagem destinada à área de programação funcional.
O compilador irá implementar uma linguagem funcional baseada em outras, como ML e Haskell: pura, com funções de primeira ordem e listas como tipo primitivo.
O diferencial desta linguagem é a possibilidade de declarações de funções de uma maneira procedural,
porém sem uso de variáveis globais ou modificação de estado fora de seu escopo direto.

Em linguagens puramente funcionais, as funções são definidas a partir de composições, descrevendo seu comportamento através do relacionamento entre as funções que a compõem,
ao invés de uma descrição dos passos a serem realizados, como em linguagens mais tradicionais e estruturadas, como C.
Este alto nível de abstração, acompanhado da rigidez em relação a efeitos colaterais e de um sistema de tipos forte,
provê qualidades há muito conhecidas no campo de estudo de linguagens de programação, como diminuição do acoplamento do código, 
facilitamento no raciocínio sobre o funcionamento de funções (estas não modificam o meio) e também auxílio no
estudo de propriedades lógicas e matemáticas das funções, devido ao embasamento teórico do Cálculo Lâmbda e da Teoria de Tipos.

Porém, nem sempre a maneira funcional é a mais intuitiva para a concretização de um algoritmo. Aprendemos a projetar nossas soluções para problemas como uma sequência de passos,
o que pode não ter uma descrição simples através de composição de funções. Assim, uma modificação à esta estrutura é proposta, permitindo que funções sejam, também, declaradas
como uma sequência de passos. Mas, diferentemente das linguagens estruturadas comuns, a modificação do ambiente não é permitida, mantendo, assim, a "pureza" da função,
sem perder as vantagens mencionadas anteriormente.

Essencial para o bom funcionamento do compilador é um algoritmo básico para inferência de tipos. Apesar de já existirem algoritmos bem estabelecidos com este propósito 
para linguagens funcionais, modificações em sua estrutura podem vir a serem necessárias devido à adição das definições imperativas.

Explicação da semântica da lingugem
-----------------------------------

Abaixo encontram-se dois exemplos que demonstram os aspectos semânticos da linguagem, acompanhados de uma breve explicação.

### Exemplo 1

```
incListBy :: Integer -> [Integer] -> [Integer]
incListBy 0 xs = xs
incListBy _ [] = []
incListBy i xs = do {
    ys <- []
    while( xs /= [] ) {
        x:xs <- xs
        ys <- (x + i):ys
    }
    rev ys
} where {
    rev [] = []
    rev x:xs = (rev xs) ++ [x]
}
```

Pontos a se observar:
- Declarações de tipo
- Declaração de função com pattern matching
- Pattern matching em atribuições
- Declaração de função limitada a um escopo
- Funções definidas imperativamente

Nas primeiras linhas, observamos uma estrutura semelhante à de outras linguagens funcionais, como Haskell.
Inicia-se uma função com uma declaração de seu tipo, contendo tipos dos argumentos e de retorno.
A função pode ser definida para alguns valores específicos, com Pattern Matching. A ordem das declarações faz diferença, seguindo uma abordagem top-down. 
Wildscores "_" e variáveis também são usadas.

A partir deste ponto, já notamos uma grande diferença: a descrição imperativa da função. Nela, podemos notar o uso de estruturas de repetição, atualização do valor
de variáveis e, novamente, o uso de Pattern Matching. Podemos notar também que a função é avaliada para o valor da última linha executada. No caso "rev ys".
A limitação de escopo também está presente, explicitada pelo uso da palavra-chave "where". Nela, a função "rev" é declarada, mas tem seu escopo limitado à função. 


### Exemplo 2


```
sumBelow10 :: [Integer] -> Integer
sumBelow10 [] = 0
sumBelow10 xs = do {
    sum <- 0
    while(xs /= []) {
        x:xs <- xs
        aux  <- if (x < 10) then {
                    yield x
                } else {
                    yield 0
                }
        sum <- sum + aux
    }
    sum
}
```

Pontos a observar:
- Expressões possuem valores
- Função declarada imperativamente retorna o último valor computado.

Aqui, vemos que o valor da expressão "if-then-else" está sendo atribuída à uma variável "aux", diferente da expressão while, que não tem seu valor atribuído a nada.
Isto se deve ao uso da palavra-chave "yield", que faz com que estas estruturas tenham retornem um valor no contexto imperativo. No caso do "if", ambas as branches precisam
de um "yield", e o tipo deve ser compatível.
Caso o "yield" não seja usado, como no caso do "while", a expressão retorna o valor unitário, "()".

Vale ressaltar que o yield não funciona da mesma maneira que o "return" das linguagens tradicionais, pois não pode ser usado para terminar a execução no meio de um bloco.
Diferentemente, ele é opcional, e só pode ser usado como última instrução de uma estrutura de loop/condição.
Vemos também que a função retorna o valor de "sum", pois é a última linha a ser executada.


O uso de estruturas imperativas e modificação de variáveis internas não afeta a "previsibilidade" da função. Para os mesmo valores de entrada, ela sempre retorna o mesmo resultado.
