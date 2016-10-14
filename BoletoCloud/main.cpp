/**
  @file
  @author Herik Lima
*/


#include <QCoreApplication>
#include <iostream>
#include <geradorboleto.h>

/*
 * Crie uma conta na https://sandbox.boletocloud.com/login
 * Gere um token para a sua conta
 * Depois crie uma conta bancária e gere um token para sua conta bancária
 */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Digite o PDF do boleto. Ex.: /home/pc/boleto_joao.pdf
    std::string fileName;
    std::cout << "Salvar como: ";    
    std::cin >> fileName;

    //Preparando o boleto
    Boleto boleto;

    //Token da conta bancária    
    boleto.setTokenContaBancaria("api-key_TOKEN_SUA_CONTA_BANCARIA");
    boleto.setDocumento("DOC-XPTO");
    boleto.setEmissao("2014-07-11");
    boleto.setInstrucao("Nao pague este boleto. Este e apenas um teste");
    boleto.setCprf("222.222.222-22");
    boleto.setNome("Exemplo de nome");
    boleto.setLogradouro("Exemplo de rua");
    boleto.setBairro("Exemplo de bairro");
    boleto.setLocalidade("Exemplo de localidade");
    boleto.setUf("TO");
    boleto.setNumero("01");
    boleto.setCep("36240-000");
    boleto.setComplemento("Exemplo de complemento");
    boleto.setValor("1250.43");
    boleto.setVencimento("2020-05-30");

    //Informar o token da sua conta de usuário (diferente do token da conta bancária).
    GeradorBoleto geradorBoleto(boleto, "api-key_TOKEN_SUA_CONTA", "token");

    //Tenta gerar o boleto
    if(geradorBoleto.generate(fileName.data()))
    {
        std::cout << "\n\nBoleto: " << fileName << " gerado com sucesso.";
        std::cout << "\nNosso numero: " << geradorBoleto.getNossoNumero().data();
        std::cout << "\nToken: " << geradorBoleto.getTokenBoleto().data();
        std::cout << "\nURL: " << geradorBoleto.getUrl().data();
    }
    else
    {
        std::cout << "\n\nOcorreu um erro \n\n" << geradorBoleto.getLastError().toStdString();
    }

    std::cout << "\n\n\n----------------------------------Fim----------------------------------\n\n\n";
    return a.exec();
}
