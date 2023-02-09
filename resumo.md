# PROJECT 1

## TEMPO:

- Comando: t - avança a data do sistema;
- O sistema começa a dia 1 janeiro 2022 e é só testado até 2023 ou seja não vão ocorrer anos bissextos;
- Formato da data:

        DD-MM-AA (D: dia, M: mês, A: ano)
        HH:MM (H: hora, M: minutos)

-Não é necessário validar se estes estão dentro dos intervalos;


## AEROPORTOS:

-Cada aeroporto é identificado por **três letras maiúsculas**;
-Um **país**: string não vazia com um máximo de 30 caracteres;
-Uma **cidade**: uma string não vazia com um máximo de 50 caracteres;
-Nestas strings de cidades podem ocorrer caracteres brancos(espaços ou \t),;
-No entanto, na string do país só aparecem letras maiúsculas ou minúsculas;
-Máximo de 40 aeroportos, não há aeropostos com o mesmo código;

## VOOS:

-Cada **voo** é caracterizado por um código de voo, o aeroporto de chegada e partida, a data e hora de partida, duração do voo e nr máximo de passageiros;
-O código de voo é uma string composta por **duas letras maiúculas seguidas de um nr entre 1 e 9999**;
-Os códigos nunca se iniciam por um 0 e podem haver voos com o mesmo código mas nunca com o mesmo código e mesma data de partida:
-Voos com o mesmo código têm de ocorrer em dias diferentes;
-Nr máximo de passageiros entre 10 e 100 e a duração nunca pode ser superior a 12h;
-Podem existir no máximo 30 000 voos;


## COMMANDS:

- q command: to shut down the programm; //IT WORKS//
