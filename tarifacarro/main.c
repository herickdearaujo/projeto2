#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fun��o para calcular a taxa com base nas horas de perman�ncia
float calcularTaxas(float tempo);

int main()
{
    // Declara��o das vari�veis para armazenar horas e minutos de chegada e partida
    float horaInicial, minutoInicial, horaFinal, minutoFinal;
    // Declara��o das vari�veis para armazenar as horas l�quidas e a taxa de cada cliente
    float cliente1, cliente2, cliente3, horasCliente1, horasCliente2, horasCliente3, horasLiquidas;
    int contador = 1; // Contador para iterar sobre os 3 clientes

    // Loop para processar as informa��es de cada um dos 3 clientes
    for (; contador <= 3; contador++) {
        // Solicita a hora e o minuto de chegada do cliente
        printf("Digite a hora que o cliente %d chegou: ", contador);
        scanf("%f", &horaInicial);
        printf("Digite o minuto em que ele chegou: ");
        scanf("%f", &minutoInicial);
        // Solicita a hora e o minuto de partida do cliente
        printf("Digite a hora em que ele partiu: ");
        scanf("%f", &horaFinal);
        printf("Digite o minuto em que ele partiu: ");
        scanf("%f", &minutoFinal);
        if (horaInicial > 23 || horaFinal > 23) {
            printf("Entrada inv�lida\n");
            contador--; // Decrementa o contador para repetir a entrada do cliente atual
            continue; // Pula para a pr�xima itera��o do loop
        }

        // Converte os minutos para serem contabilizados como horas
        horaInicial += minutoInicial / 60;
        horaFinal += minutoFinal / 60;

        // Calcula as horas l�quidas de perman�ncia
        if (horaInicial > horaFinal) {
            // Se a hora inicial for maior que a hora final, assume que o carro estacionou durante a noite
            horasLiquidas = (float) (horaFinal + 24) - horaInicial;
        }
        else {
            horasLiquidas = (float) horaFinal - horaInicial;
        }

        // Verifica se as horas l�quidas s�o maiores que 24, o que � inv�lido
        if (horasLiquidas > 24) {
            printf("Entrada inv�lida\n");
            contador--; // Decrementa o contador para repetir a entrada do cliente atual
            continue; // Pula para a pr�xima itera��o do loop
        }

        // Calcula a taxa de estacionamento para o cliente atual e guarda a quantidade de horas
        if (contador == 1) {
            horasCliente1 = horasLiquidas;
            cliente1 = calcularTaxas(horasCliente1);
        }
        else if (contador == 2) {
            horasCliente2 = horasLiquidas;
            cliente2 = calcularTaxas(horasCliente2);
        }
        else if (contador == 3) {
            horasCliente3 = horasLiquidas;
            cliente3 = calcularTaxas(horasCliente3);
        }
    }

    // Exibe o relat�rio das horas e taxas para cada cliente
    printf("\n%10s%10s%10s", "Carro", "Horas", "Taxa");
    printf("\n%10s %10.1f %10.2f", "1", horasCliente1, cliente1);
    printf("\n%10s %10.1f %10.2f", "2", horasCliente2, cliente2);
    printf("\n%10s %10.1f %10.2f", "3", horasCliente3, cliente3);

    return 0;
}

// Fun��o para calcular a taxa com base nas horas de perman�ncia
float calcularTaxas(float tempo)
{
    int contador = 1; // Contador para iterar sobre as horas
    int taxaCentavos = 0; // Inicializa a taxa em centavos

    // Verifica se a perman�ncia foi maior que 0 e aplica a tarifa m�nima
    if (tempo > 0) {
        taxaCentavos += 200; // Tarifa m�nima de R$2,00 para at� 3 horas
    }

    // Aplica a tarifa adicional para cada hora acima de 3 horas
    for (; contador <= floor(tempo); contador++) {
        if (contador > 3) {
            taxaCentavos += 50; // Adicional de R$0,50 por hora acima de 3 horas
        }
    }

    // Aplica o limite m�ximo de R$10,00
    if (taxaCentavos > 1000) {
        taxaCentavos = 1000; // Tarifa m�xima de R$10,00
    }

    // Retorna a taxa em reais
    return (float) taxaCentavos / 100;
}
