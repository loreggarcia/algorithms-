/*A spanning tree is known as a subgraph of an undirected connected graph that 
possesses all of the graph’s edges or vertices with the rarest feasible edges. */

#include <iostream> // header file library
#include <climits>
/*sem conexão direta entre os pontos 
ele instancia que a conexão entre os pontos é máxima(ou seja, infinita)*/


using namespace std; // means that we can use names for objects and variables from the standard library.

int cost[][8] = //Adjacency matrix
    {{I,I,I,I,I,I,I,I},
     {I,I,25,I,I,I,15,I},
     {I,25,I,12,I,I,I,10},
     {I,I,12,I,8,I,I,I},
     {I,I,I,8,I,16,I,14},
     {I,I,I,I,16,I,20,18},
     {I,5,I,I,I,20,I,I},
     {I,I,10,I,14,18,I,I}
    };

int near[8]={I,I,I,I,I,I,I,I}; //reserva memória pra guardar o índice do vértice
int t[2][7]; //Matriz de resultado

int main(){
    int i,j,k,u,v,n=7,min=I;

    //Eu quero encontrar os índices do valor que tendo conexão com o número consegue o menor peso 
    for(i=1;i<=n;i++){ //Percorre linha
        for(j=i;j<=n;j++){ //Percorre coluna de cada linha
            if(cost[i][j]<min){ //tem conexão?            
                min=cost[i][j]; // o valor mínimo vira a ordenada encontrada
                //Salva os índices
                u=i;
                v=j;
            }
        }
    }
    
    //posições ocupadas dentro da matriz de resultado 
    t[0][0]=u;
    t[1][0]=v;
    
    near[u]=near[v]=0; //marca como visto

    /*nessa parte do código, como eu tenho um grafo sem direção, eu não tenho direção pra continuar,
    ou seja, eu posso escolher qualquer um dos vertices pra seguir, a questão é tentar escolher 
    qual dos caminhos para ele é menos custoso*/
    for(i=1;i<=n;i++){ 
        //guarda quem é menos custoso
        if(cost[i][u]<cost[i][v])
            near[i]=u;
        else 
            near[i]=v;
    }


    for(i=1;i<n-1;i++){ 
        min=I;
        for(j=1;j<=n;j++){
            if(near[j]!=0 && cost[j][near[j]]<min){ //mesma lógica de ordenação do mais próximo
                k=j;
                min=cost[j][near[j]];
            }
        }
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;

        for(j=1;j<=n;j++){
            if(near[j]!=0 && cost[j][k]<cost[j][near[j]])
                near[j]=k;
        }
    }

    //só pra imprimir 
    for(i=0;i<n-1;i++){
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    }
}