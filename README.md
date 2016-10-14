[![Travis-CI](https://travis-ci.org/HerikLyma/boletocloud.svg?branch=master)](https://travis-ci.org/HerikLyma/boletocloud)

# Boleto Cloud

Criação de boletos via web services Boleto Cloud utilizando C++ com Qt


Boleto Cloud

1º: Passo: Crie uma conta em https://sandbox.boletocloud.com

2º: Passo: Logue na Sandbox da Boleto Cloud

3º: Passo: Clique no nome do seu usuário e em seguida em "Meus Dados"

4º: Passo: Clique na opção "Gerar Token" para gerar um token da sua conta (Guarde esse número)

5º: Passo: Clique em beneficiário, em seguida em "+ Criar", crie um beneficiário e salve

6º: Passo: Clique em conta, em seguida "+ Criar", crie uma conta para o beneficiário e salve

7º: Passo: Clique em conta, em seguida "Consultar"->"Mais"->"Editar Conta"

8º: Passo: Clique em "Gerar Token" para gerar o token da conta bancária (Guarde esse número)


Windows

1º Passo: Baixe o projeto BoletoCloud

2º Passo: Baixe e instale o Qt Creator: http://www.qt.io/download-open-source/

3º Passo: Clique em Open Project e selecione o projeto BoletoCloud.pro

4º Passo: Na main.cpp informe o token da sua conta bancária nessa linha: boleto.setTokenContaBancaria("api-key_TOKEN_SUA_CONTA_BANCARIA");

5º Passo: Na main.cpp informe o token da sua conta nessa linha: GeradorBoleto geradorBoleto(boleto, "api-key__TOKEN_SUA_CONTA", "token");

6º Passo: Execute o projeto com Ctrl + r


Linux

1º Passo: Baixe o projeto BoletoCloud

2º Passo: Baixe e instale o Qt Creator: http://www.qt.io/download-open-source/

3º Passo: Instale a biblioteca default do Qt: sudo apt-get install qt5-default

4º Passo: Clique em Open Project e selecione o projeto BoletoCloud.pro

5º Passo: Na main.cpp informe o token da sua conta bancária nessa linha: boleto.setTokenContaBancaria("api-key_TOKEN_SUA_CONTA_BANCARIA");

6º Passo: Na main.cpp informe o token da sua conta nessa linha: GeradorBoleto geradorBoleto(boleto, "api-key__TOKEN_SUA_CONTA", "token");

7º Passo: Execute o projeto com Ctrl + r
