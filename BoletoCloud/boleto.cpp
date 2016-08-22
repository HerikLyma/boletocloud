/**
  @file
  @author Herik Lima
*/


#include "boleto.h"

QByteArray Boleto::getTokenContaBancaria() const
{
    return tokenContaBancaria;
}

void Boleto::setTokenContaBancaria(const QByteArray &value)
{
    tokenContaBancaria = value;
    tokenContaBancaria.replace("&", "e");
}

QByteArray Boleto::getDocumento() const
{
    return documento;
}

void Boleto::setDocumento(const QByteArray &value)
{
    documento = value;
    documento.replace("&", "e");
}

QByteArray Boleto::getEmissao() const
{
    return emissao;
}

void Boleto::setEmissao(const QByteArray &value)
{
    emissao = value;
    emissao.replace("&", "e");
}

QByteArray Boleto::getInstrucao() const
{
    return instrucao;
}

void Boleto::setInstrucao(const QByteArray &value)
{
    instrucao = value;
    instrucao.replace("&", "e");
}

QByteArray Boleto::getCprf() const
{
    return cprf;
}

void Boleto::setCprf(const QByteArray &value)
{
    cprf = value;
    cprf.replace("&", "e");
}

QByteArray Boleto::getNome() const
{
    return nome;
}

void Boleto::setNome(const QByteArray &value)
{
    nome = value;
    nome.replace("&", "e");
}

QByteArray Boleto::getLogradouro() const
{
    return logradouro;
}

void Boleto::setLogradouro(const QByteArray &value)
{
    logradouro = value;
    logradouro.replace("&", "e");
}

QByteArray Boleto::getBairro() const
{
    return bairro;
}

void Boleto::setBairro(const QByteArray &value)
{
    bairro = value;
    bairro.replace("&", "e");
}

QByteArray Boleto::getLocalidade() const
{
    return localidade;
}

void Boleto::setLocalidade(const QByteArray &value)
{
    localidade = value;
    localidade.replace("&", "e");
}

QByteArray Boleto::getUf() const
{
    return uf;
}

void Boleto::setUf(const QByteArray &value)
{
    uf = value;
    uf.replace("&", "e");
}

QByteArray Boleto::getNumero() const
{
    return numero;
}

void Boleto::setNumero(const QByteArray &value)
{
    numero = value;
    numero.replace("&", "e");
}

QByteArray Boleto::getCep() const
{
    return cep;
}

void Boleto::setCep(const QByteArray &value)
{
    cep = value;
    cep.replace("&", "e");
}

QByteArray Boleto::getComplemento() const
{
    return complemento;
}

void Boleto::setComplemento(const QByteArray &value)
{
    complemento = value;
    complemento.replace("&", "e");
}

QByteArray Boleto::getValor() const
{
    return valor;
}

void Boleto::setValor(const QByteArray &value)
{
    valor = value;
    valor.replace("&", "e");
}

QByteArray Boleto::getVencimento() const
{
    return vencimento;
}

void Boleto::setVencimento(const QByteArray &value)
{
    vencimento = value;
    vencimento.replace("&", "e");
}

//Formato de boleto exigido pela API Boleto Cloud
QByteArray Boleto::toXWWWFormUrlEncoded() const
{
    QByteArray boleto;
    boleto += "boleto.conta.token=" + tokenContaBancaria + "&";
    boleto += "boleto.documento=" + documento + "&";
    boleto += "boleto.emissao=" + emissao + "&";
    boleto += "boleto.instrucao=" + instrucao + "&";
    boleto += "boleto.pagador.cprf=" + cprf + "&";
    boleto += "boleto.pagador.nome=" + nome + "&";
    boleto += "boleto.pagador.endereco.logradouro=" + logradouro + "&";
    boleto += "boleto.pagador.endereco.bairro=" + bairro + "&";
    boleto += "boleto.pagador.endereco.localidade=" + localidade + "&";
    boleto += "boleto.pagador.endereco.uf=" + uf + "&";
    boleto += "boleto.pagador.endereco.numero=" + numero + "&";
    boleto += "boleto.pagador.endereco.cep=" + cep + "&";
    boleto += "boleto.pagador.endereco.complemento=" + complemento + "&";
    boleto += "boleto.valor=" + valor + "&";
    boleto += "boleto.vencimento=" + vencimento;

    return boleto;
}
