#include <stdio.h>
#include <math.h>

typedef double (*Funcao)(double);

double calcular_integral(Funcao f, double a, double b, int n_passos) {
    if (a == b) {
        return 0.0;
    }

    double largura_retangulo = (b - a) / n_passos;
    double soma_areas = 0.0;

    for (int i = 0; i < n_passos; i++) {
        double ponto_medio = a + (i + 0.5) * largura_retangulo;
        double altura = f(ponto_medio);
        soma_areas += altura * largura_retangulo;
    }

    return soma_areas;
}

double polinomio_quadratico(double x) {
    return x * x;
}

double trigonometrica_seno(double x) {
    return sin(x);
}

double exponencial(double x) {
    return exp(x);
}

double logaritmo_natural(double x) {
    if (x <= 0) {
        return NAN;
    }
    return log(x);
}

double gaussiana(double x) {
    return exp(-pow(x, 2));
}

double quociente_sinc(double x) {
    if (x == 0.0) {
        return 1.0; 
    }
    return sin(x) / x;
}

int main() {
    int n_passos = 1000000;

    printf("Calculadora de Integral Numérica (Método dos Retângulos)\n");
    printf("Usando n = %d passos para a aproximação.\n\n", n_passos);

    // --- Caso: 1: Polinômio ---
    double a1 = 0.0, b1 = 1.0;
    double res1 = calcular_integral(polinomio_quadratico, a1, b1, n_passos);
    printf("Integral de f(x)=x^2 de %.2f a %.2f = %f\n", a1, b1, res1);
    printf("(Valor exato = 1/3 = 0.333333...)\n\n");

    // --- Caso 2: Trigonométrica ---
    double a2 = 0.0, b2 = M_PI; // M_PI é a constante pi da math.h
    double res2 = calcular_integral(trigonometrica_seno, a2, b2, n_passos);
    printf("Integral de f(x)=sin(x) de %.2f a %.2f = %f\n", a2, b2, res2);
    printf("(Valor exato = 2.0)\n\n");

    // --- Caso 3: Exponencial ---
    double a3 = 0.0, b3 = 1.0;
    double res3 = calcular_integral(exponencial, a3, b3, n_passos);
    printf("Integral de f(x)=e^x de %.2f a %.2f = %f\n", a3, b3, res3);
    printf("(Valor exato = e - 1 = 1.718281...)\n\n");

    // --- Caso 4: Função Composta (Gaussiana) ---
    double a4 = -1.0, b4 = 1.0;
    double res4 = calcular_integral(gaussiana, a4, b4, n_passos);
    printf("Integral de f(x)=e^(-x^2) de %.2f a %.2f = %f\n", a4, b4, res4);
    printf("(Valor aproximado conhecido ~= 1.493648...)\n\n");
    
    // --- Caso 5: Logaritmo ---
    double a5 = 1.0, b5 = exp(1.0); // Integrando de 1 até 'e'
    double res5 = calcular_integral(logaritmo_natural, a5, b5, n_passos);
    printf("Integral de f(x)=ln(x) de %.2f a %.2f = %f\n", a5, b5, res5);
    printf("(Valor exato = 1.0)\n\n");

    return 0;

}
