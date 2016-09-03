/**
  @file
  @author Herik Lima
*/

#ifndef GERADORBOLETO_H
#define GERADORBOLETO_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QEventLoop>
#include <QFile>
#include <boleto.h>

class GeradorBoleto
{
    Boleto boleto;
    QByteArray userName;
    QByteArray password;
    QByteArray lastError;
    QByteArray tokenBoleto;
    QByteArray url;
    QByteArray nossoNumero;
public:
    GeradorBoleto(const Boleto &boleto, const QByteArray &userName,
                  const QByteArray &password = "token");

    bool generate(const QString &fileName);

    QByteArray getLastError() const;
    QByteArray getTokenBoleto() const;
    QByteArray getUrl() const;
    QByteArray getNossoNumero() const;
};

#endif // GERADORBOLETO_H
