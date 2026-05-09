# EDA_PF_JairoAriza_MiguelAlvarez_EmmanuelMontoya

## Integrantes
- Jairo Ariza
- Miguel Alvarez
- Emmanuel Montoya

## Descripción
Análisis de la red vial de Pennsylvania usando el dataset roadNet-PA 
(Stanford SNAP, 1,088,092 nodos y 1,541,898 aristas). Implementación 
en C++17 de Dijkstra con heap mínimo, BFS no ponderado, MST y 
detección de componentes conexas.

## Requisitos
- Sistema operativo: Windows con MSYS2 MINGW64 / Linux / Mac
- Compilador: g++ con soporte para C++17
- RAM mínima: 512 MB

## Clonar el repositorio
git clone https://github.com/arizajairo75/EDA_PF_JairoAriza_MiguelAlvarez_EmmanuelMontoya.git
cd EDA_PF_JairoAriza_MiguelAlvarez_EmmanuelMontoya

## Dataset
El archivo data/roadNet-PA.txt está incluido en el repositorio.
Si no está disponible, descárguelo desde:
https://snap.stanford.edu/data/roadNet-PA.txt.gz

Descomprímalo y colóquelo en la carpeta data/.

## Compilación
g++ -std=c++17 -O2 -o eda_pf src/main.cpp src/graph.cpp src/loader.cpp src/dijkstra.cpp src/bfs.cpp src/consultas.cpp

## Ejecución
### Módulo A — Análisis estructural
./eda_pf A

### Módulo B — Consultas P2P Dijkstra vs BFS
./eda_pf B

### Módulo C — Subgrafo, MST y DAG
./eda_pf C

## Archivos de resultados
| Archivo | Descripción |
|---|---|
| results/analisis_estructural.txt | Estadísticas del grafo vs. valores SNAP |
| results/consultas_p2p.csv | Resultados de las 10 consultas P2P |
| results/camino_Q01.txt | Camino reconstruido para Q01 |
| results/camino_Q06.txt | Camino reconstruido para Q06 |
| results/subgrafo_caminos.txt | Subgrafo inducido por Q01 y Q06 |
| results/analisis_subgrafo.txt | MST y análisis DAG del subgrafo |

## Reindexación de nodos
Los IDs originales del dataset no son consecutivos. El programa
los reindexó internamente usando un unordered_map. La correspondencia
se guarda en g.idMap durante la carga del grafo.

## Herramientas de IA utilizadas
- Claude (Anthropic): consultas sobre conceptos de algoritmos,
  depuración de errores de compilación y estructura del proyecto.
  Todo el código fue escrito, entendido y verificado por el equipo.
