/**
  @file
  @author Herik Lima
*/


#include "geradorboleto.h"


GeradorBoleto::GeradorBoleto(const Boleto &boleto, const QByteArray &userName,
                             const QByteArray &password) : boleto(boleto),
                                                           userName(userName),
                                                           password(password)
{
}

bool GeradorBoleto::generate(const QString &fileName)
{
    //Limpa erros anteriores
    lastError.clear();

    //Prepara a requisição
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("https://sandbox.boletocloud.com/api/v1/boletos"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded;charset=UTF-8");

    //Configura a autorização
    QByteArray base(userName + ":" + password);
    base = base.toBase64();
    request.setRawHeader("Authorization", "Basic " + base);


    QEventLoop waitLoop;
    //Faz a requisição
    QNetworkReply *reply = manager.post(request, boleto.toXWWWFormUrlEncoded());
    QObject::connect(reply, SIGNAL(finished()), &waitLoop, SLOT(quit()));
    //Espera até a resposta ficar pronta (sincrono)
    waitLoop.exec();


    //Lê a resposta da requisição
    QByteArray retorno(std::move(reply->readAll()));
    //Verifica o tipo de retorno
    QByteArray tipoRetorno(reply->rawHeader("Content-Type"));

    //Se retornou um PDF é que tudo correu bem
    if(tipoRetorno.toLower().contains("application/pdf"))
    {
        //Tenta salvar o arquivo
        QFile boletoFile(fileName);
        if(boletoFile.open(QIODevice::WriteOnly))
        {
            if(boletoFile.write(retorno) != -1)
            {
                tokenBoleto = reply->rawHeader("X-BoletoCloud-Token");
                url = "https://sandbox.boletocloud.com/boleto/2via/" + tokenBoleto;
                nossoNumero = reply->rawHeader("X-BoletoCloud-NIB-Nosso-Numero");
                boletoFile.close();
            }
            else
            {
                lastError  =  "Ocorreu um erro ao gravar no arquivo " + boletoFile.fileName().toLatin1() + "\n";
                lastError +=  boletoFile.errorString() + "\n";
            }
        }
        else
        {
            lastError  =  "Erro ao abrir o arquivo " + boletoFile.fileName().toLatin1() + "\n";
            lastError +=  boletoFile.errorString() + "\n";
        }
    }
    //Se retornou um JSON é porque ocorreu algum erro
    else if(tipoRetorno.toLower().contains("application/json"))
    {
        QJsonDocument doc(QJsonDocument::fromJson(retorno));
        QJsonObject obj(doc.object());
        QJsonValue value(obj.value("erro"));
        QJsonObject erro(value.toObject());

        lastError  = "status : " + QByteArray::number(erro["status"].toInt()) + "\n";
        lastError += "tipo : " + erro["tipo"].toString() + "\n";

        QJsonArray array(erro["causas"].toArray());
        int total = array.size();
        for(int i = 0; i < total; ++i)
        {
            QJsonObject temp(array[i].toObject());
            for(QJsonObject::iterator it = temp.begin(); it != temp.end(); ++it)
            {
                QString key(it.key());
                QString value(it.value().toString());

                lastError +=  key + ": " + value + "\n";
            }
        }
    }
    //Erro desconhecido
    else
    {
        lastError = "Erro desconhecido.\n";
    }
    //Se o lastError estiver vazio é porque tudo correu bem, caso contrário é porque houve um erro
    return lastError.isEmpty();
}

QByteArray GeradorBoleto::getLastError() const
{
    return lastError;
}

QByteArray GeradorBoleto::getTokenBoleto() const
{
    return tokenBoleto;
}

QByteArray GeradorBoleto::getUrl() const
{
    return url;
}

QByteArray GeradorBoleto::getNossoNumero() const
{
    return nossoNumero;
}
