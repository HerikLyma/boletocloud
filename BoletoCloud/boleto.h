/**
  @file
  @author Herik Lima
*/


#ifndef BOLETO_H
#define BOLETO_H

#include <QByteArray>

class Boleto
{
    QByteArray tokenContaBancaria;
    QByteArray documento;
    QByteArray emissao;
    QByteArray instrucao;
    QByteArray cprf;
    QByteArray nome;
    QByteArray logradouro;
    QByteArray bairro;
    QByteArray localidade;
    QByteArray uf;
    QByteArray numero;
    QByteArray cep;
    QByteArray complemento;
    QByteArray valor;
    QByteArray vencimento;
public:
    QByteArray getTokenContaBancaria() const;
    void setTokenContaBancaria(const QByteArray &value);
    QByteArray getDocumento() const;
    void setDocumento(const QByteArray &value);
    QByteArray getEmissao() const;
    void setEmissao(const QByteArray &value);
    QByteArray getInstrucao() const;
    void setInstrucao(const QByteArray &value);
    QByteArray getCprf() const;
    void setCprf(const QByteArray &value);
    QByteArray getNome() const;
    void setNome(const QByteArray &value);
    QByteArray getLogradouro() const;
    void setLogradouro(const QByteArray &value);
    QByteArray getBairro() const;
    void setBairro(const QByteArray &value);
    QByteArray getLocalidade() const;
    void setLocalidade(const QByteArray &value);
    QByteArray getUf() const;
    void setUf(const QByteArray &value);
    QByteArray getNumero() const;
    void setNumero(const QByteArray &value);
    QByteArray getCep() const;
    void setCep(const QByteArray &value);
    QByteArray getComplemento() const;
    void setComplemento(const QByteArray &value);
    QByteArray getValor() const;
    void setValor(const QByteArray &value);
    QByteArray getVencimento() const;
    void setVencimento(const QByteArray &value);
    QByteArray toXWWWFormUrlEncoded() const;
};

#endif // BOLETO_H
