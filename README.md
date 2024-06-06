# Fluxo máximo à custo mínimo
Implementação do algoritmo de fluxo máximo à custo mínimo em redes.

## Estrutura do projeto
 - Lemon_Dataset : Arquivos de teste originais formato `.min` padrão DIMACS
 - model : classes de modelagem para a entidade `Network`
 - testCases : Arquivos de teste gerados pelo projeto
 - tests : código para leitura e escrita do testes
 - utils : código para filtragem dos testes originais
 - view : user interface



## Como filtrar os testes originais

primeiro limpe a pasta testCases para reecriar os testes filtrados
```
make clearTestCases
```


Para compilar o TestFilter.cpp execute:
```
make buildTestFilter
```


logo após, execute:
```
make execTestFilter
```

# Como executar o algoritmo minCostMaxFlow 

Para compilar os `.cpp` necessários, execute:
```
make buildMaxMin
```

Para executar o programa:
```
make execMaxMin
```
