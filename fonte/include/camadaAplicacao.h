#include "camadaEnlace.h"

extern int codificacaoFisica;
extern int tipoDeEnquadramento;
extern int tipoDeErro;

/**
 * Entrada na camada de aplicação para transmissão.
 */
void AplicacaoTransmissora();

/**
 * Parte da camada de aplicação que transmite dados chamando a camada física.
 * @param mensagem Mensagem que vai ser codificada na camada física.
 * @param codificacaoFisica Codificação escolhida, entre Binária, Bipolar e
 * Manchester.
 */
void CamadaDeAplicacaoTransmissora(const string&);

/**
 * Entrada na camada de aplicação para recepção.
 * @param quadro Um vetor com os bits em binário da string em ASCII.
 */
void CamadaDeAplicacaoReceptora(const vector<int>&);

/**
 * Entrada na camada de aplicação para recepção.
 * @param mensagem String resultado da decodificação.
 */
void AplicacaoReceptora(const string&);

/**
 * Recebe string e retorna um vetor de inteiros dos valores binários em ASCII de
 * cada caracter.
 * @param mensagem String a ser convertida.
 * @return Um vetor com os bits em binário da string em ASCII.
 */
vector<int> TransformaStringEmASCII(string);

/**
 * Recebe vetor de bits em ASCII e converte em string.
 * @param quadro Um vetor com os bits em binário da string em ASCII.
 * @return A string convertida.
 */
string TransformaASCIIEmString(vector<int>);

/**
 * Entrada na camada de enlace para transmissão.
 * São realizados o Enquadramento, o Controle de Erros, e o envio à Camada
 * Física.
 * @param quadro Bits que vão viajar pelos sinais via cabo ou onda.
 * @param tipoDeEnquadramento Protocolo de enquadramento escolhido, entre
 * Contagem de Caracteres ou Inserção de Bytes.
 */
void CamadaEnlaceTransmissora(const vector<int>&);

/**
 * Limita a chance de erro entre 0 e 5%.
 * @param erro Chance de erro que foi colocada como input pelo usuário do sistema.
*/
void getProbErro(int erro);