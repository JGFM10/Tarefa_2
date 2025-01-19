#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

// Definições dos pinos dos LEDs
#define RED_LED_PIN 13
#define GREEN_LED_PIN 11
#define BLUE_LED_PIN 12

// Definições do buzzer
#define BUZZER_PIN 21      // Pino do buzzer

// Variáveis de estado dos dispositivos
int red_led_state = 0;
int green_led_state = 0;
int blue_led_state = 0;
int buzzer_state = 0;

void init_ledsebuzz() {
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_put(RED_LED_PIN, red_led_state);

    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    gpio_put(GREEN_LED_PIN, green_led_state);

    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);
    gpio_put(BLUE_LED_PIN, blue_led_state);

    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, buzzer_state);
}

void set_led_color(const char *color) {
    if (strcmp(color, "vermelho") == 0) {
        red_led_state = 1;
        green_led_state = 0;
        blue_led_state = 0;
        buzzer_state = 0;
    } else if (strcmp(color, "verde") == 0) {
        red_led_state = 0;
        green_led_state = 1;
        blue_led_state = 0;
        buzzer_state = 0;
    } else if (strcmp(color, "azul") == 0) {
        red_led_state = 0;
        green_led_state = 0;
        blue_led_state = 1;
        buzzer_state = 0;
    } else if (strcmp(color, "branco") == 0) {
        red_led_state = 1;
        green_led_state = 1;
        blue_led_state = 1;
        buzzer_state = 0;
    } else if (strcmp(color, "buzzer") == 0) {
        red_led_state = 0;
        green_led_state = 0;
        blue_led_state = 0;
        buzzer_state = 1;
    } else if (strcmp(color, "desligar") == 0) {
        red_led_state = 0;
        green_led_state = 0;
        blue_led_state = 0;
        buzzer_state = 0;
    } else {
        printf("Comando não reconhecido.\n");
        return;
    }

    // Atualiza os dispositivos conforme o estado
    gpio_put(RED_LED_PIN, red_led_state);
    gpio_put(GREEN_LED_PIN, green_led_state);
    gpio_put(BLUE_LED_PIN, blue_led_state);
    gpio_put(BUZZER_PIN, buzzer_state);
}

int main() {
    stdio_init_all(); // Inicializa o UART para comunicação
    init_ledsebuzz(); // Configura os pinos dos LEDs e buzzer

    char color[16];

    while (1) {
        printf("Digite a cor do LED para acender (vermelho, verde, azul e branco), escreva buzzer para acionar o buzzer ou desligar para apagar tudo:\n");
        scanf("%15s", color); // Lê a entrada do usuário
        set_led_color(color); // Ajusta o LED ou buzzer com base na entrada
    }

    return 0;
}
