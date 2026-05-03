/*
Atencão à Reunião
Vinicius está em uma reunião da diretoria do Instituto de Consultoria de Palestras e Comentários
(ICPC) pensando que seria muito bom se os membros da diretoria fossem mais concisos, e mantivessem
suas falas dentro do tempo definido para cada diretor, para que a reunião terminasse antes do almoço.
Infelizmente, talvez devido `a natureza da institui¸c˜ao, todos gostam muito de falar.
Sabendo que
• h´a N diretores que ir˜ao falar na reuni˜ao;
• cada diretor ir´a falar pelo mesmo tempo;
• e entre duas falas consecutivas h´a um intervalo de 1 minuto,
determine a dura¸c˜ao m´axima de cada fala, em minutos, para que a reuni˜ao dure no m´aximo K
minutos.
Entrada
A primeira linha cont´em um inteiro N (1 ≤ N ≤ 100), o n´umero de diretores. A segunda linha
cont´em um inteiro K (1 ≤ K ≤ 1000 e K ≥ N), a dura¸c˜ao m´axima da reuni˜ao em minutos. Para
todos os casos de entrada, a fala de cada diretor tem dura¸c˜ao de pelo menos 1 minuto.
Sa´ıda
Seu programa deve produzir uma ´unica linha, contendo um ´unico inteiro, indicando a dura¸c˜ao da
fala de cada membro da diretoria, em minutos.
*/

#include <iostream>

using namespace std;

int diretores;

int tempo_max;

int numero_intervalos;

int x;

int main(){
    cout << ;
    cin >> diretores;
    cout << ;
    cin >> tempo_max;

    numero_intervalos = diretores/2;

    x = (tempo_max - numero_intervalos) / diretores;

    cout << x << "\n";
}