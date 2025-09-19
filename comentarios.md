# Tópicos sobre o Código

1. Biblioteca <math.h>: 
Esta biblioteca padrão do C fornece implementações para quase todas as funções elementares necessárias:
- Polinômios: pow(base, expoente)
- Trigonométricas: sin(), cos(), tan()
- Exponencial: exp() para e^x
- Logaritmo: log() para logaritmo natural (ln), log10() para base 10.
- Raiz n-ésima: sqrt() para raiz quadrada, cbrt() para cúbica, e pow(x, 1.0/n) para a raiz n-ésima genérica.

2. Precisão e Tolerância 
- A precisão do cálculo está diretamente ligada ao valor de n_passos. 
- Um n_passos maior significa retângulos mais estreitos, o que resulta em uma aproximação muito melhor da área real sob a curva. 
- Um n_passos menor é mais rápido, mas menos preciso.
