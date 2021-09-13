# -*- coding: utf-8 -*-
"""Digital Signature Algorithm.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1oqfHWQTUGu9vgul_U24_QryCWSWUS7b7
"""

from google.colab import drive
drive.mount('/content/drive')

pip install pycryptodome

from Crypto.PublicKey import DSA
from Crypto.Signature import DSS
from Crypto.Hash import SHA256
from Crypto.Random import get_random_bytes
from Crypto.Cipher import PKCS1_OAEP

"""# Descrição DSA (Técnica DSS)

- DSS - Digital Signature Standard - padrão NIST - *usa o SHA

- A técnica do DSS também usa uma função de hash. O código de hash é fornecido como entrada para uma função de assinatura, com um número aleatório k, gerado para essa assinatura em particular.

- Uma assinatura digital permite ao criador de uma
mensagem anexar um código que atue como uma assinatura. A mesma é formada tomando o hash da mensagem e criptografando-a com a chave privada do criador. A assinatura garante a origem e a integridade da mensagem.

- Protocolos de autenticação mútua permitem que as partes da comunicação se convençam mutuamente da identidade umas das outras e
também para a troca de chaves de sessão.

- Na autenticação unidirecional, o destinatário deseja alguma garantia de que uma mensagem vem realmente do emissor alegado.

Ela precisa ter as
seguintes características:

1.Deve verificar o autor, a data e hora da assinatura; 

2.Deve autenticar o conteúdo no momento da
assinatura; 

3.Deve ser verificável por terceiros, para resolver
disputas.

A assinatura digital precisa ter os seguintes
requisitos:

1.Precisa ser um padrão de bits que dependa da
mensagem que será assinada;

2.Precisa usar alguma informação exclusiva do emissor;

3.Deve ser relativamente fácil produzí-la;

4.Deve ser relativamente fácil reconhecê-la;

5.Deve ser computacionalmente inviável falsificá-la;

6.Deve ser prático armazenar uma cópia da assinatura;

# Chaves
"""

#Gerando um par de chave DSA
key = DSA.generate(2048)
print(key)

#Salvando a chave pública 
public_key_bytes = key.publickey().export_key()
f = open("/content/drive/My Drive/Cryptowork/DSApublic_key.pem", "wb")
f.write(public_key_bytes)
f.close()

public_key_bytes

public_key = DSA.import_key(public_key_bytes)

"""PCKS8 -> False = Encoded in the custom OpenSSL/OpenSSH container."""

#salvando a chave privada
private_key_bytes = key.export_key(format='PEM', pkcs8='True')
file_out = open("/content/drive/My Drive/Cryptowork/DSAprivkey.pem", "wb")
file_out.write(private_key_bytes)
file_out.close()

private_key_bytes

priv = DSA.import_key(private_key_bytes)

"""# Assinando a Mensagem"""

Message = b"Mensagem qualquer a ser assinada"

#Gerando um Hash autêntico baseado nessa mensagem
HASH = SHA256.new(Message)
H = HASH.hexdigest()
print(H)

"""Objeto DSS - (chave, modo, encoding,, randfunc)
- ’fips-186-3’ mode - gera uma assinatura randomizada e carrega o acordo  FIPS 186-3
"""

# Assinando a menssagem com a chave PÚBLICA
signer = DSS.new(key, 'fips-186-3')
signature = signer.sign(HASH)
print(signature)

file_out2 = open("/content/drive/My Drive/Cryptowork/SignatureSender.pem", "wb")
file_out2.write(signature)
file_out2.close()

"""Quem envia pode usar uma chave PRIVADA para assinar uma mensagem também"""

# Assinando a menssagem com a chave PRIVADA
signer2 = DSS.new(priv, 'fips-186-3')
signature2 = signer2.sign(HASH)
print(signature2)

file_out3 = open("/content/drive/My Drive/Cryptowork/SignatureSender2.pem", "wb")
file_out3.write(signature2)
file_out3.close()

"""# Verificando Autenticidade (Assinado com a chave PÚBLICA)

O Recebedor conhece:
- A mensagem
- A Assinatura da mensagem
- A Chave Pública de quem enviou

Carregando chave pública recebida e assinatura
"""

pubKEY_SEN = DSA.import_key(open("/content/drive/My Drive/Cryptowork/DSApublic_key.pem").read())

#SIG_SEN = open("/content/drive/My Drive/Cryptowork/SignatureSender.pem", "r")
#print(SIG_SEN)

#Gerando um Hash autêntico baseado na mensagem recebida
HASH_REC = SHA256.new(Message)
H2 = HASH_REC.hexdigest()
print(H2)

#Gerando o objeto verificador
verifier = DSS.new(pubKEY_SEN, 'fips-186-3')

# Verificando a autenticidade da mensagem, se a assinatura é válida
try:
  verifier.verify(HASH_REC, signature)
  print("The message is authentic.")
except ValueError:
  print("The message is not authentic")

"""# Verificando Autenticidade (Assinado com a chave PRIVADA)

O recebedor pode usar a chave PÚBLICA para verficiar a autenticidade da mensagem recebida
"""

pubKEY_SEN2 = DSA.import_key(open("/content/drive/My Drive/Cryptowork/DSApublic_key.pem").read())

#Gerando um Hash autêntico baseado na mensagem recebida
HASH_REC2 = SHA256.new(Message)
H3 = HASH_REC2.hexdigest()
print(H3)

#Gerando o objeto verificador
verifier = DSS.new(pubKEY_SEN2, 'fips-186-3')

# Verificando a autenticidade da mensagem, se a assinatura é válida
try:
  verifier.verify(HASH_REC2, signature2)
  print("The message is authentic.")
except ValueError:
  print("The message is not authentic")