/*
Carlinhos adora filmes, e recentemente tem estado fascinado com o n´umero de Bacon, mais conhecido
como Bacon Number, que ´e definido da seguinte forma.
• O n´umero de Bacon do ator Kevin Bacon ´e igual a 0;
• Se o menor n´umero de Bacon de um ator com quem X tenha aparecido em um mesmo filme for
b, o n´umero de bacon do ator X ´e b + 1.
Ou seja, o n´umero de Bacon mede o menor caminho entre qualquer ator e o ator Kevin Bacon, em
que dois atores s˜ao conectados se eles apareceram juntos em um mesmo filme.
Carlinhos est´a interessado em um problema mais geral: dados dois atores, como conect´a-los
atrav´es de filmes e atores intermedi´arios? S˜ao dados N filmes, e, para cada filme, quais dos M
atores existentes atuaram nele. Carlinhos quer responder Q consultas: na i-´esima delas, queremos
computar alguma forma de conectar o ator xi com o ator yi
. Devemos achar alguma sequˆencia
xi = a1, f1, a2, f2, . . . , fk−1, ak = yi
, em que 1 ≤ aj ≤ N s˜ao atores e 1 ≤ fj ≤ M s˜ao filmes, e o ator
aj atuou nos filmes fj−1 e fj , ou indicar que n˜ao existe tal sequˆencia.
Entrada
Na primeira linha da entrada, s˜ao fornecidos dois inteiros N (1 ≤ N ≤ 100) e M (1 ≤ M ≤ 106
),
o n´umero de filmes e o n´umero de atores. Seguem N linhas. Na i-´esima delas, o primeiro inteiro
ni (1 ≤ ni ≤ M) denota o n´umero de atores no filme i. Seguem ni n´umeros em ordem crescente
separados por espa¸co: os ´ındices, de 1 a M, dos atores que atuaram no filme i. Na pr´oxima linha, leia
um n´umero Q (1 ≤ Q ≤ 104
): o n´umero de consultas. As pr´oximas Q linhas descrevem as consultas.
Na i-´esima delas, leia dois n´umeros xi
, yi (1 ≤ xi ̸= yi ≤ M), os atores que queremos conectar. E´
garantido que o n´umero total de atores nos filmes ´e no m´aximo 106
. Isto ´e, P
i ni ≤ 106
.
Sa´ıda
Para cada uma das consultas, se n˜ao existe sequˆencia, imprima uma linha com −1. Caso contr´ario,
imprima duas linhas. Na primeira, o n´umero de atores ki (2 ≤ ki ≤ 106
) em alguma maneira de
conectar xi e yi
. Na segunda, imprima a sequˆencia como descrita, com ki atores e ki − 1 filmes, de
maneira alternada. Se houver mais de uma maneira de conectar os atores, imprima qualquer uma
delas.
*/

