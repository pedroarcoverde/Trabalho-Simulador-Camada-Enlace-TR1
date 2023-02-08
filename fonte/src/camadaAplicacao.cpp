#include "camadaAplicacao.h"

void AplicacaoTransmissora() {
  string mensagem;
  cout << endl << "Digite uma mensagem: ";
  int erro = 0;
  getline(cin, mensagem);
  cout << endl
       << "Selecione um tipo de enquadramento (camada de enlace):" << endl
       << "0: Contagem de Caracteres" << endl
       << "1: Inserção de Bytes" << endl;
  cin >> tipoDeEnquadramento;
  cout << "Selecionado: " << tipoDeEnquadramento << endl;
  cout << endl
       << "Selecione um tipo de erro (camada de enlace):" << endl
       << "0: Bit de paridade par" << endl
       << "1: CRC (Redundância Cíclica)" << endl
       << "2: Código de Hamming" << endl;
  cin >> tipoDeErro;
  cout << "Selecionado: " << tipoDeErro << endl;
  cout << endl
       << "Selecione uma probabilidade de erro de 0 a 5 (em %) por bit (camada de "
          "enlace):"
       << endl;
  cin >> erro;
  cout << "Probabilidade de erro: " << probDeErro << "%" << endl;
  cout << endl
       << "Selecione um modo de codificação (camada física):" << endl
       << "0: Codificação Binária" << endl
       << "1: Codificação Manchester" << endl
       << "2: Codificação Bipolar" << endl;
  cin >> codificacaoFisica;
  getProbErro(erro);
  CamadaDeAplicacaoTransmissora(mensagem);
}

void CamadaDeAplicacaoTransmissora(const string& mensagem) {
  vector<int> quadro = TransformaStringEmASCII(mensagem);
  CamadaEnlaceTransmissora(quadro);
}

void CamadaDeAplicacaoReceptora(const vector<int>& quadro) {
  string mensagem = TransformaASCIIEmString(quadro);
  AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora(const string& mensagem) {
  cout << endl << "Mensagem recebida: " << mensagem << endl << endl;
}

vector<int> TransformaStringEmASCII(string mensagem) {
  vector<int> quadro;
  cout << endl << "Mensagem em ASCII caracter por caracter:" << endl;
  for (unsigned i = 0; i < mensagem.size(); i++) {
    quadro.push_back(int(mensagem.at(i)));
    cout << mensagem.at(i) << " - " << quadro.at(i) << endl;
  }
  return quadro;
}

string TransformaASCIIEmString(vector<int> quadro) {
  string mensagem = "";
  for (unsigned i = 0; i < quadro.size(); i++) {
    mensagem.append(1, char(quadro[i]));
  }
  return mensagem;
}

void getProbErro(int erro){
  probDeErro = erro;
  if (erro >= 5) probDeErro = 5;
  if (erro <= 0) probDeErro = 0;
}