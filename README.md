# task.cli

## Descrição do Projeto

task.cli é um projeto simples para organizar tasks simples.

Ele é escrito em C, e usa um banco de dados feito a mão, puramente para que eu possa estudar bancos de dados.

## Interface

task --help -> listagem da interface

task add -> menu interativo de criação de task

task ls [option] -> lista as tasks com status=pending por padrão. Options são --completed, --canceled e --all

task complete -> abre menu interativo para selecionar task que terá o status alterado para completed. Pede confirmação 

task cancel -> abre menu interativo para selecionar task que terá o status alterado para canceled. Pede confirmação.

task sync -> realiza pull e push do repo git que mantém o banco de dados

## Banco de dados 

Estrutura de Log, utilizando sempre append no final de um arquivo em texto plano. Linguagem de query implementada do zero.

struct task {
  id;
  status;
  name;
  desc;
  ts_created;
  ts_deadline; ts_completed_or_canceled;
}
