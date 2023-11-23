## Exercício 03 - Contagem de operações e de tempo de execução

Você deverá implementar 4 programas diferentes, contabilizar o tempo médio de execução dele para diferentes entradas, construir um gráfico a partir disso, e contabilizar suas operações.
Para contar o tempo de execução, podem utilizar o programa de geração de vetores de número aleatórios que implementamos em aula. Ou os arquivos anexados a esse exercício.

Utilize, pelo menos, os seguintes tamanhos de entrada:
10, 100, 1.000 e 5.000
(Podem usar os arquivos que estão no .zip "Data" deste exercício)

Faça a média do tempo de, pelo menos, 100 execuções.

Os programas a serem implementados são:

1 - Inverter a ordem do vetor de entrada. Lembre-se de que é possível fazer tal operação de um jeito mais otimizado ao percorrer o vetor até sua metade, e trocar o elemento "i" com o "fim-i".

2 - Busca Sequencial no vetor de entrada

3 - Busca Binária Iterativa no vetor de entrada

4 - Busca Binária Recursiva no vetor de entrada

Faça a contagem de operação para todos considerando o pior caso.

Compare os 4 algoritmos e comente os resultados. O que os gráficos indicam?

Você deverá fazer um relatório simples, contendo a resolução da equação da contagem de operações dos algoritmos, no PIOR CASO, e o gráfico resultante das execuções. 

Submeta o relatório em formato .pdf e os códigos em um arquivo .zip nesta atividade

## Observações sobre o plot de dados

Para fazer os gráficos, é possível usar os comandos no arquivo "plotdata", contidos no .zip do exemplo.

Neste arquivo, estão comandos do programa Gnuplot.

Este programa pode ser executado tanto em Linux (instalar com apt install gnuplot) ou no Windows (https://sourceforge.net/projects/gnuplot/files/gnuplot/).

Caso esteja usando WSL, o gnuplot só irá funcionar por linha de comando no Linux caso você tenha configurado o WSL 2, e tenha algum terminal com X11 no Windows, como o MobaXTerm (https://mobaxterm.mobatek.net/) e que ele tenha sido configurado para se comunicar com o WSL. Um exemplo de tutorial que ensina a fazer isso: https://georgik.rocks/how-to-run-gui-application-on-wsl2-with-mobaxterm-and-windows-terminal/

A primeira linha dos comandos de plot definem apenas o visual do gráfico:
'set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2 pointtype 7 pointsize 1.5'

Já a segunda, pede para desenhar o gráfico, a partir dos dados contidos no arquivo 'Data/exectime1000.dat', e com o estilo de linha de linhas e pontos.
'plot "Data/exectime1000.dat" with linespoints linestyle 1'

Esses comandos funcionam tanto para Linux como para Windows!

## Observações sobre como usar o programa disponibilizado

Para fazer o exercício, você precisa apenas criar suas implementações da busca e inversão dos elementos do vetor, e chamá-las a partir da main, no lugar da função "getLargestNumber(numberVector)". A partir daí, é só executar com diferentes número de entrada e organizar os dados salvos para "plottar" no Gnuplot. 
O formato que o Gnuplot recebe é um par com o número de elementos e o tempo médio de execução!