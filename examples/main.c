#include <stm32/rcc.h>
#include <stm32/gpio.h>

int main() {
	RCC->APB2ENR |= IOPCEN;
	GPIOC->CRH = 0x44444411;
	GPIOC->ODR = BIT(8);

	while(1);
}