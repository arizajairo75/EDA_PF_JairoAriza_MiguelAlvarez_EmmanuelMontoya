Emmanuel Montoya feats.

ya se implemento el parser.

Se puede parsear el dataset para implementar el algoritmo de Djikstra, 

como acceder a los vecinos?
``
const vector <pair<int, int>>& getVecinos(int nodo) const;
``
El vecino se recorre
````
for(auto[vecino, peso]: g.getVecinos(nodo))
````
FALTA: el bfs



