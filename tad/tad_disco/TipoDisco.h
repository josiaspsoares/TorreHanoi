typedef struct disco{
    int tamanho;
    char representacao[15];

    struct disco *under;
    struct disco *above;
}TipoDisco;